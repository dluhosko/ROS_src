//
// Created by viktor on 17/08/17.
//


#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include "math.h"
#include <tf/transform_listener.h>
#include <moveit/robot_trajectory/robot_trajectory.h>
#include "moveit/robot_model_loader/robot_model_loader.h"
#include <moveit/trajectory_processing/iterative_time_parameterization.h>
#include <industrial_trajectory_filters/filter_base.h>
#include <industrial_trajectory_filters/uniform_sample_filter.h>
#include "moveit_msgs/GetCartesianPath.h"
#include "moveit_msgs/GetCartesianPathRequest.h"
#include "moveit_msgs/GetCartesianPathResponse.h"
#include "moveit/robot_state/conversions.h"

using namespace std;

std::vector<double> joint_positions(4);
std::vector<double> link_length(2);
double x_offset, y_offset, z_offset;
geometry_msgs::Point point;

std::vector<geometry_msgs::Pose> setPointToWaypoints(std::vector<geometry_msgs::Pose> waypoints){

    geometry_msgs::Pose points;
    //Start position 1
    points.position.x = 0.578;
    points.position.y = 0.509;
    points.position.z = 1.019;
    points.orientation.x = 1;
    points.orientation.y = 0;
    points.orientation.z = 0.0006;
    points.orientation.w = -0.0005;
    waypoints.push_back(points);

    //Finish position 1
    points.position.x = 0.576;
    points.position.y = 0.726;
    points.position.z = 1.019;
    points.orientation.x = 1;
    points.orientation.y = 0;
    points.orientation.z = 0.0006;
    points.orientation.w = -0.0005;
    waypoints.push_back(points);

    return waypoints;


}
bool countIK(double x, double y, double z,  int mode){
    ROS_INFO("input numbers %f %f %f",x,y,z);
    x = x - x_offset;
    y = y - y_offset;
    z = z - z_offset;

    double c2 = (pow(x,2.0) + pow(y,2.0) - pow(link_length[0],2.0) - pow(link_length[1],2.0))/(2*link_length[0]*link_length[1]);
    if ((1-c2) > 0.0 ){
        if (mode == 1) {
            joint_positions[1] = atan2(-sqrt(1 - c2), c2);
        }else{
            joint_positions[1] = atan2(sqrt(1 - c2), c2);
        }
        joint_positions[0] =  atan2(y,x) - atan2(link_length[1]*sin(joint_positions[1]),link_length[0] + link_length[1]*cos(joint_positions[1]));
        joint_positions[1] = - joint_positions[1] ; //otocenie kvoli opacnej rotacii klbu
    }else if ((0.00001 >=(1-c2)) && (-0.00001 <= (1-c2))){
        joint_positions[1] = atan2(0,c2);
        joint_positions[0] =  atan2(y,x) - atan2(link_length[1]*sin(joint_positions[1]),link_length[0] + link_length[1]*cos(joint_positions[1]));
        joint_positions[1] = -joint_positions[1];
    }
    else{
        ROS_ERROR("Target is out of range");
        return false;
    }

    if (z<0.05 && z>-0.04){
        joint_positions[2] = -z;
    }else{
        ROS_ERROR("Target is out of range");
        return false;
    }
    joint_positions[3] = 0.5;

    ROS_INFO("output joint positions %f %f %f %f ",joint_positions[0],joint_positions[1],joint_positions[2],joint_positions[3]);
    return true;

}

geometry_msgs::Point getPoseFromTF(std::string source, std::string target) {

    geometry_msgs::Point point;
    tf::TransformListener listener;
    tf::StampedTransform transform;

    try {
        listener.waitForTransform(source, target, ros::Time(0), ros::Duration(1));
        listener.lookupTransform(source, target, ros::Time(0), transform);
    } catch (tf::TransformException ex) {
        ROS_WARN("OSM planner: %s. Can't update pose from TF, for that will be use the latest source point.",
                 ex.what());
    }
    tf::pointTFToMsg(transform.getOrigin(), point);
    return point;

}
void getOffsets(){

    //    Default values
//    link_length[0] = 0.24942;
//    link_length[1] = 0.24304;
//    offset_x = 0.212;
//    offset_y = 0.58;
//    offset_z = 1.01962;
    geometry_msgs::Point scaraLink1, scaraLink2, scaraBase;

    point = getPoseFromTF("world","BaseBox");
    x_offset = x_offset + point.x;
    y_offset = y_offset + point.y;
    point = getPoseFromTF("BaseBox","ScaraBase");
    x_offset = x_offset + point.x;
    y_offset = y_offset + point.y;
    point = getPoseFromTF("world","tool0");
    z_offset = point.z;

    scaraBase = getPoseFromTF("world","ScaraLink1");
    scaraLink1 = getPoseFromTF("world","ScaraLink2");
    scaraLink2 = getPoseFromTF("world","GripperBase");
    link_length[0] = sqrt (pow(scaraLink1.x-scaraBase.x,2.0) + pow(scaraLink1.y-scaraBase.y,2.0) );
    link_length[1] = sqrt (pow(scaraLink2.x-scaraLink1.x,2.0) + pow(scaraLink2.y-scaraLink1.y,2.0) );
    ROS_INFO("final offsets: x_offset=%f y_offset=%f z_offset=%f",x_offset, y_offset, z_offset);
    ROS_INFO("final arm lenths: arm1=%f arm2=%f",link_length[0], link_length[1]);
    sleep(2);

}

int main(int argc, char **argv) {

    bool success;

    ros::init(argc, argv, "move_group_interface_tutorial");
    ros::NodeHandle n;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::core::RobotStatePtr current_state;
    static const std::string PLANNING_GROUP = "scara_arm";
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);
    moveit_msgs::RobotTrajectory trajectory_msg;

    ros::ServiceClient client = n.serviceClient<moveit_msgs::GetCartesianPath>("compute_cartesian_path",cartPathService_callback);
    moveit_msgs::GetCartesianPathRequest req;
    moveit_msgs::GetCartesianPathResponse res;

    //ROS_INFO("overenie klbov");
    //Na overenie limitov klbov
    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
    robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
    robot_state::RobotStatePtr kinematic_state(new robot_state::RobotState(kinematic_model));
    kinematic_state->setToDefaultValues();
    //getchar();

    current_state = move_group.getCurrentState();
    getOffsets();

    geometry_msgs::PoseStamped ws1 = move_group.getCurrentPose();
    std::vector< std::string> activeJoints = move_group.getActiveJoints();
    for (int i =0;i<activeJoints.size();i++){
        ROS_INFO("Active link %d : %s",i, activeJoints[i].c_str());
    }
    ROS_INFO(".....Current robot model.......");
    ROS_INFO_STREAM(move_group.getRobotModel());
    ROS_INFO("Reference frame: %s", move_group.getPlanningFrame().c_str());
    ROS_INFO("End effector link: %s", move_group.getEndEffectorLink().c_str());
    move_group.setPoseReferenceFrame(move_group.getEndEffectorLink().c_str());
    getchar();


    std::vector<geometry_msgs::Pose> waypoints;
    waypoints = setPointToWaypoints(waypoints);

    countIK(waypoints[1].position.x, waypoints[1].position.y, waypoints[1].position.z, 2);
    move_group.setJointValueTarget(joint_positions);
    kinematic_state->setJointGroupPositions(joint_model_group, joint_positions);
    success = move_group.plan(my_plan);
    if (success){
        ROS_INFO("Succesful plan!");
        move_group.execute(my_plan);
        move_group.move();
        ROS_INFO("moved to place!!\n");
    } else{
        ROS_ERROR("Bad plan");
    }
    for (int i=0;i<my_plan.trajectory_.joint_trajectory.points.size();i++){
            ROS_INFO("%d : %f %f %f %f",i,my_plan.trajectory_.joint_trajectory.points[i].positions[0],my_plan.trajectory_.joint_trajectory.points[i].positions[1],
                 my_plan.trajectory_.joint_trajectory.points[i].positions[2], my_plan.trajectory_.joint_trajectory.points[i].positions[3]);
    }
    getchar();

    countIK(waypoints[0].position.x, waypoints[0].position.y, waypoints[0].position.z, 2);
    move_group.setJointValueTarget(joint_positions);
    kinematic_state->setJointGroupPositions(joint_model_group, joint_positions);
    success = move_group.plan(my_plan);
    if (success){
        ROS_INFO("Succesful plan!");
        move_group.execute(my_plan);
        move_group.move();
        ROS_INFO("moved to place!!\n");
    } else{
        ROS_ERROR("Bad plan");
    }
    for (int i=0;i<my_plan.trajectory_.joint_trajectory.points.size();i++){
        ROS_INFO("%d : %f %f %f %f",i,my_plan.trajectory_.joint_trajectory.points[i].positions[0],my_plan.trajectory_.joint_trajectory.points[i].positions[1],
                 my_plan.trajectory_.joint_trajectory.points[i].positions[2], my_plan.trajectory_.joint_trajectory.points[i].positions[3]);
    }
    getchar();

    //service
//    req.avoid_collisions = true;
//    req.jump_threshold = 0.05;
//    req.group_name = PLANNING_GROUP;
//    //req.link_name = "tool0";
//    req.waypoints = waypoints;
//    req.max_step = 0.05;
//    req.header.frame_id = move_group.getPoseReferenceFrame();
//    req.header.stamp = ros::Time::now();
//    moveit_msgs::RobotState robotState;
//    robot_state::RobotStatePtr considered_start_state_;
//    considered_start_state_.reset(new robot_state::RobotState()
//    robot_state::robotStateToRobotStateMsg(*considered_start_state_, req.start_state);
//    //robot_state::RobotState start_state(* move_group.getCurrentState());
//    //req.start_state = start_state;




    geometry_msgs::PoseStamped currentPose = move_group.getCurrentPose();
    ROS_INFO("Desired: %f %f %f",waypoints[0].position.x, waypoints[0].position.y, waypoints[0].position.z);
    ROS_INFO("Current: X=%f Y=%f Z=%f",currentPose.pose.position.x,currentPose.pose.position.y, currentPose.pose.position.z);
    getchar();

    move_group.setGoalOrientationTolerance(1);
    move_group.setGoalPositionTolerance(0.1);

    //std::vector<geometry_msgs::Pose> waypoint(1);
    //waypoint[0] = waypoints[1];

    ROS_INFO("linear interpolation");
    //linear interpolation!
    double fraction = move_group.computeCartesianPath(waypoints,0.001,0.0,trajectory_msg, true);
    ROS_INFO("computed fraction = %f",fraction);
    getchar();

    robot_trajectory::RobotTrajectory rt(move_group.getCurrentState()->getRobotModel(),"scara_arm");
    rt.setRobotTrajectoryMsg(*move_group.getCurrentState(), trajectory_msg);
    trajectory_processing::IterativeParabolicTimeParameterization iptp;
    if (iptp.computeTimeStamps(rt)){
        ROS_INFO("iptp OK!");
    }else{
        ROS_INFO("iptp BAD!");
    }
    //getchar();


    my_plan.trajectory_ = trajectory_msg;
    for (int i=0;i<my_plan.trajectory_.joint_trajectory.points.size(); i++){
        ROS_INFO("%d : %f %f %f %f",i,my_plan.trajectory_.joint_trajectory.points[i].positions[0],my_plan.trajectory_.joint_trajectory.points[i].positions[1],
                 my_plan.trajectory_.joint_trajectory.points[i].positions[2], my_plan.trajectory_.joint_trajectory.points[i].positions[3]);
    }
    //if (fraction >= 0.5) {
        ROS_WARN("Plan %f percents",fraction);
        move_group.execute(my_plan);
        move_group.move();
        ROS_INFO("moving there!!!!");
    //}
    //else
    //    ROS_WARN("Could not compute the cartesian path :( <0.5 ");

    getchar();



    ros::shutdown();



        return 0;

    }