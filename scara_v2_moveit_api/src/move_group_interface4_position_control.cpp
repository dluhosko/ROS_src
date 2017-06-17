
#include <ros/ros.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/GetPositionIK.h>
#include <moveit/robot_state/conversions.h>

#include "sensor_msgs/JointState.h"



//#include "../../ikfast_kinematics_plugin/templates/ikfast.h"

void printDefaultInformation(moveit::planning_interface::MoveGroupInterface *moveGroup){

    ROS_INFO_NAMED("\nReference frame: %s", moveGroup->getPlanningFrame().c_str());
    ROS_INFO_NAMED("End effector link: %s\n", moveGroup->getEndEffectorLink().c_str());
}

int main (int argc, char **argv){

    bool success;
    static const std::string PLANNING_GROUP = "scara_arm";
    geometry_msgs::Pose target_pose;
    geometry_msgs::PoseStamped ws1;
    //moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::core::RobotStatePtr current_state;
    //IKFAST
    moveit_msgs::GetPositionIK IKposition;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;


    ros::init(argc, argv, "pose_control");
    ros::NodeHandle n, nn;
    ros::Rate r(2);
    ros::AsyncSpinner spinner(1);
    spinner.start();


    //nejak to osetrit
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

    printDefaultInformation(&move_group);


    //0.34695; 0.19341; 0.97653


    ros::ServiceClient service_client = n.serviceClient<moveit_msgs::GetPositionIK>("compute_ik");
    while (!service_client.exists()){
        ROS_INFO("waiting for service");
        sleep(1.0);
    }
    move_group.setGoalPositionTolerance(0.1);
    move_group.setGoalJointTolerance(0.1);
    move_group.setGoalOrientationTolerance(1);
    move_group.setGoalTolerance(0.1);

    //move_group.setEndEffector("tool0");
    const geometry_msgs::PoseStamped position = move_group.getCurrentPose();
    ROS_INFO_STREAM("REFERENCNY FRAME");
    ROS_INFO_NAMED("tutorial", "Reference frame: %s", move_group.getPlanningFrame().c_str());
    ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group.getEndEffectorLink().c_str());
    //ROS_INFO_STREAM(move_group.getPoseReferenceFrame());
    ROS_INFO_STREAM(position);
    moveit_msgs::RobotState robot_state;
    moveit::core::robotStateToRobotStateMsg(*move_group.getCurrentState(), robot_state, true);
    //fill request message
    moveit_msgs::GetPositionIK::Request service_request;
    moveit_msgs::GetPositionIK::Response service_response;
    service_request.ik_request.group_name = PLANNING_GROUP;
    service_request.ik_request.pose_stamped.header.frame_id="/world";
    service_request.ik_request.ik_link_name = "tool0";
    service_request.ik_request.robot_state=robot_state;

    ROS_INFO("hovno");




    std::vector<double> joint_group_position;




    /*ROS_INFO_STREAM(robot_state);
    move_group.setStartState(robot_state);
    move_group.setPositionTarget(position.pose.position.x,position.pose.position.y,position.pose.position.z,"tool0");
    move_group.setGoalTolerance(0.1);
    move_group.setPlannerId("RRTConnectkConfigDefault");
    move_group.setPlanningTime(10);
    move_group.allowReplanning(true);
    move_group.setNumPlanningAttempts(10);
    //move_group.setRandomTarget();
    moveit::planning_interface::MoveGroupInterface::Plan plan;

    int a = move_group.plan(plan);
    ROS_INFO_STREAM("PLAN:" << a);
    if(a){



    int size=plan.trajectory_.joint_trajectory.points.size();

    ROS_INFO_STREAM("moje IK je");
    ROS_INFO_STREAM(plan.trajectory_.joint_trajectory.points[0]);
    }
*/
    //0.49215; 0.88562; 1.0479
//    service_request.ik_request.pose_stamped.pose.position.x = position.pose.position.x;
//    service_request.ik_request.pose_stamped.pose.position.y = position.pose.position.y;
//    service_request.ik_request.pose_stamped.pose.position.z = position.pose.position.z;

    service_request.ik_request.pose_stamped.pose.position.x = 0.575932;
    service_request.ik_request.pose_stamped.pose.position.y = 0.873529;
    service_request.ik_request.pose_stamped.pose.position.z = 1.01;

    //


    //-0.056811; -0.70458; 0.70497; 0.057875
//    service_request.ik_request.pose_stamped.pose.orientation.x = position.pose.orientation.x;
//    service_request.ik_request.pose_stamped.pose.orientation.y = position.pose.orientation.y;
//    service_request.ik_request.pose_stamped.pose.orientation.z = position.pose.orientation.z;
//    service_request.ik_request.pose_stamped.pose.orientation.w = position.pose.orientation.w;

//    service_request.ik_request.pose_stamped.pose.orientation.x = -0.19714;
//    service_request.ik_request.pose_stamped.pose.orientation.y = -0.678599;
//    service_request.ik_request.pose_stamped.pose.orientation.z = 0.679277;
//    service_request.ik_request.pose_stamped.pose.orientation.w = 0.198047;
    //colision avoidance
    service_request.ik_request.avoid_collisions = true;
    service_request.ik_request.attempts = 10;

    if (service_client.call(service_request, service_response)) {
        ROS_INFO("good");
    }
    else
        ROS_INFO("bad");
    ROS_INFO_STREAM("IK zo servisu je");
    ROS_INFO_STREAM(service_response);

    joint_group_position.push_back(service_response.solution.joint_state.position[0]);   // radians
    joint_group_position.push_back(service_response.solution.joint_state.position[1]);
    joint_group_position.push_back(service_response.solution.joint_state.position[2]);

    move_group.setJointValueTarget(joint_group_position);
    success = move_group.plan(my_plan);
    ROS_INFO_NAMED("Visualizing plan (joint space goal) %s", success ? "GOOD" : "FAILED");
    move_group.execute(my_plan);
    move_group.move();


    //Kinematic model tutorial
    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
    robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
    ROS_INFO("Model frame: %s", kinematic_model->getModelFrame().c_str());
    robot_state::RobotStatePtr kinematic_state(new robot_state::RobotState(kinematic_model));
    kinematic_state->setToDefaultValues();
    const std::vector<std::string> &joint_names = joint_model_group->getVariableNames();

    //
    ROS_INFO("0");
    std::vector<double> joint_values;
    kinematic_state->copyJointGroupPositions(joint_model_group, joint_values);
    for (std::size_t i = 0; i < joint_names.size(); ++i)
    {
        ROS_INFO("Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
    }

    //joint_model_group = kinematic_state-
    //robot_state::JointStateGroup* joint_state_group = kinematic_state->getJointStateGroup(PLANNING_GROUP);
    //service_request.ik_request.robot_state.joint_state.name = joint


    ROS_INFO_ONCE("while");
    spinner.stop();

    /*while (ros::ok()){
        ROS_INFO_ONCE("while");

    }*/
    ros::shutdown();

    return 0;
}