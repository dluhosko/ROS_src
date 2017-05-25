#include <ros/ros.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometric_shapes/solid_primitive_dims.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <sstream>

const double DEG2RAD=0.01745329252;
const double RAD2DEG=57.295779513;
std::vector<double> joint_group_positions(4);
std::vector<double> joint_group_position;
bool commandForRT = false;


void setDesiredAngles (){
    ROS_INFO("VECTOR SIZE %d\n", joint_group_positions.size());

    joint_group_positions[0] = 90 * DEG2RAD;
    joint_group_positions[1] = 180 * DEG2RAD;
    joint_group_positions[2] = 270 * DEG2RAD;
    joint_group_positions[3] = 360 * DEG2RAD;
    for (int i =0;i<joint_group_positions.size(); i++){
        ROS_INFO("%d. angle is : %f",i,joint_group_positions[i]);
    }

}
geometry_msgs::Pose getTargetCoordinates (moveit::planning_interface::MoveGroupInterface *move_group){

    geometry_msgs::PoseStamped ws=move_group->getCurrentPose();
    geometry_msgs::Pose target_pose;

    target_pose.position.x = ws.pose.position.x;
    target_pose.position.y = ws.pose.position.y;
    target_pose.position.z = ws.pose.position.z;
    target_pose.orientation.x = ws.pose.orientation.x;
    target_pose.orientation.y = ws.pose.orientation.y;
    target_pose.orientation.z = ws.pose.orientation.z;
    target_pose.orientation.w = ws.pose.orientation.w;
    ROS_INFO("Effector pose : x=%f , y=%f , z=%f \n", ws.pose.position.x, ws.pose.position.y, ws.pose.position.z);

    return target_pose;
}
void turn45deg(moveit::planning_interface::MoveGroupInterface *move_group, moveit::planning_interface::MoveGroupInterface::Plan my_plan){

    static double currentDeg =45;
    bool success;

    if (currentDeg > 360){
        currentDeg = 45;
    }
    joint_group_position[0] = currentDeg*DEG2RAD;
    move_group->setJointValueTarget(joint_group_position);
    success = move_group->plan(my_plan);
    ROS_INFO_NAMED("Visualizing plan (45) %s", success ? "GOOD" : "FAILED");
    move_group->execute(my_plan);
    move_group->move();
    ROS_INFO("current degrees %f",currentDeg);
    currentDeg+=45;

}

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("command RT rotate!!");
    commandForRT = true;
}

int main(int argc, char **argv){


    int counter = 0;
    bool success;
    static const std::string PLANNING_GROUP = "rt";
    geometry_msgs::Pose target_pose1;

    geometry_msgs::PoseStamped ws1;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::core::RobotStatePtr current_state;

    setDesiredAngles();

    ros::init(argc, argv, "rt");
    ros::NodeHandle n;
    ros::Rate r(2);
    ros::AsyncSpinner spinner(1);
    spinner.start();
    //
    ros::Subscriber sub = n.subscribe("commandForRotaryTable", 1000, chatterCallback);

    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);


    while (ros::ok()){
        ROS_INFO_ONCE("spustil sa while");
        current_state = move_group.getCurrentState();
        current_state->copyJointGroupPositions(joint_model_group, joint_group_position);

        if (commandForRT) {
            turn45deg(&move_group, my_plan);
            commandForRT=false;
        }



        sleep(2);

    }


    return 0;
}