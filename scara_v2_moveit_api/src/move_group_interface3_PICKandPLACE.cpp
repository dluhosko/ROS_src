//
// Created by viktor on 09/05/17.
//

#include <ros/ros.h>

// MoveIt!
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometric_shapes/solid_primitive_dims.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <sstream>
//#include "scara_v2_moveit_api/pose_and_gripperState.msg"
//#include "std_msgs/"
#include "scara_v2_moveit_api/pose_and_gripperState.h"



const double DEG2RAD=0.01745329252;
const double RAD2DEG=57.295779513;

std::vector<std::vector<double>> joint_group_positions(4, std::vector<double>(3));
std::vector<double> joint_group_position;


void setDesiredAngles (){
    ROS_INFO("VECTOR SIZE %d x %d \n", joint_group_positions.size(),joint_group_positions[0].size());


    //gripper pick pos 0.36641; 0.2078; 1.0199 (-0.57 1.30 0.01)
    //home
    joint_group_positions[0][0] = 0;
    joint_group_positions[0][1] = 0;
    joint_group_positions[0][2] = -0.004;

    //pick position
    joint_group_positions[1][0] = -45;
    joint_group_positions[1][1] = 45;
    joint_group_positions[1][2] = 0.05;

    //work position
    joint_group_positions[2][0] = -20;
    joint_group_positions[2][1] = -60;
    joint_group_positions[2][2] = 0.0;

    //place position
    joint_group_positions[3][0] = 75;
    joint_group_positions[3][1] = 60;
    joint_group_positions[3][2] = 0.05;
    ROS_INFO("Vector filled up");

}
void openGripper(trajectory_msgs::JointTrajectory &posture){

    posture.joint_names.resize(1);
    posture.joint_names[0] = "right_gripper";
    posture.points.resize(1);
    posture.points[0].positions.resize(1);
    posture.points[0].positions[0] = 0;


}
void closeGripper(trajectory_msgs::JointTrajectory &posture){

    posture.joint_names.resize(1);
    posture.joint_names[0] = "left_gripper";
    posture.points.resize(1);
    posture.points[0].positions.resize(1);
    posture.points[0].positions[0] = 0.03;
}
void pick(moveit::planning_interface::MoveGroupInterface &group){
    moveit_msgs::Grasp grasp;


}
void place(moveit::planning_interface::MoveGroupInterface &group){
}

void jointControll (moveit::planning_interface::MoveGroupInterface *move_group, moveit::planning_interface::MoveGroupInterface::Plan my_plan,  double joint1_in_DEG, double joint2_in_DEG, double joint3_in_m){

    bool success;

    joint_group_position[0] = joint1_in_DEG*DEG2RAD;  // radians
    joint_group_position[1] = joint2_in_DEG*DEG2RAD;
    joint_group_position[2] = joint3_in_m;
    move_group->setJointValueTarget(joint_group_position);
    success = move_group->plan(my_plan);
    ROS_INFO_NAMED("tutorial", "Visualizing plan (joint space goal) %s", success ? "GOOD" : "FAILED");
    move_group->execute(my_plan);
    move_group->move();



}
void positionControll (moveit::planning_interface::MoveGroupInterface *move_group, moveit::planning_interface::MoveGroupInterface::Plan my_plan,  geometry_msgs::Pose target_pose){

    bool success;

    move_group->setPoseTarget(target_pose);
    success = move_group->plan(my_plan);
    ROS_INFO_NAMED("tutorial", "Visualizing plan 2 -back (pose goal) %s", success ? "GOOD" : "BAD");
    move_group->execute(my_plan);
    move_group->move();

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
    //ROS_INFO("Effector pose : x=%f , y=%f , z=%f \n", ws.pose.position.x, ws.pose.position.y, ws.pose.position.z);

    return target_pose;
}


int main(int argc, char **argv){

    int counter = 0;
    bool success;
    static const std::string PLANNING_GROUP = "scara_arm";
    //static const std::string PLANNING_GROUP = "left_gripper";
    geometry_msgs::Pose target_pose1;

    geometry_msgs::PoseStamped ws1;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::core::RobotStatePtr current_state;

    setDesiredAngles();
    ros::init(argc, argv, "PICK_and_PLACE");
    ros::NodeHandle n, nn;
    ros::Rate r(2);
    ros::AsyncSpinner spinner(1);
    spinner.start();
    //



    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

    ros::Publisher gripperState_pub = n.advertise<std_msgs::String>("gripper_state_topic", 1000);
    ros::Publisher grip_topic_pub =  nn.advertise<scara_v2_moveit_api::pose_and_gripperState>("gripper_state", 1000);

    scara_v2_moveit_api::pose_and_gripperState gripperStates;
    gripperStates.gripperState = false;
    gripperStates.posX = 0.0;
    gripperStates.posY = 0.0;
    gripperStates.posZ = 0.0;


    while (ros::ok()) {

        //Get current pose of tool0
        target_pose1 = getTargetCoordinates(&move_group);
        ROS_INFO("Desired joint values : %f  %f  %f",  target_pose1.position.x,target_pose1.position.y,target_pose1.position.z);
        //move to WS1
        current_state = move_group.getCurrentState();
        current_state->copyJointGroupPositions(joint_model_group, joint_group_position);

        if (counter < joint_group_positions.size()){
            jointControll(&move_group,my_plan, joint_group_positions[counter][0],joint_group_positions[counter][1],joint_group_positions[counter][2]);
            ROS_INFO("Desired joint values : %f  %f  %f", joint_group_positions[counter][0],joint_group_positions[counter][1],joint_group_positions[counter][2]);
            if (counter == 1){
                ROS_INFO ("Gripper Pick! and publish");
                gripperStates.gripperState = true;
                gripperStates.posX = target_pose1.position.x;
                gripperStates.posY = target_pose1.position.y;
                gripperStates.posZ = target_pose1.position.z;
                grip_topic_pub.publish(gripperStates);
            }
            counter++;
        } else{
            counter = 0 ;
            ROS_INFO ("Gripper Place! and publish");
            gripperStates.gripperState = false;
            gripperStates.posX = target_pose1.position.x;
            gripperStates.posY = target_pose1.position.y;
            gripperStates.posZ = target_pose1.position.z;
            grip_topic_pub.publish(gripperStates);
        }
        sleep(2);
    }



    return 0;
}
