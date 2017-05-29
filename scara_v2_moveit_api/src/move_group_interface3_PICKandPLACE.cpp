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
#include "scara_v2_moveit_api/pose_and_gripperState.h"



const double DEG2RAD=0.01745329252;
const double RAD2DEG=57.295779513;
std::vector<std::vector<double>> joint_group_positions(13, std::vector<double>(3));
std::vector<std::vector<double>> defaultPositions(11, std::vector<double>(3));
std::vector<double> joint_group_position;


void setDesiredAngles (){
    ROS_INFO("VECTOR SIZE %d x %d \n", joint_group_positions.size(),joint_group_positions[0].size());

    //Home position
    joint_group_positions[0][0] = 0;
    joint_group_positions[0][1] = 0;
    joint_group_positions[0][2] = 0.00;

    //Pick position
    joint_group_positions[1][0] = -0.44*RAD2DEG;
    joint_group_positions[1][1] = 1.30*RAD2DEG;
    joint_group_positions[1][2] = 0.01;
    //work position
    joint_group_positions[2][0] = -0.68*RAD2DEG;
    joint_group_positions[2][1] = -1.45*RAD2DEG;
    joint_group_positions[2][2] = 0.0;
    //place position 1
    joint_group_positions[3][0] = 0.21*RAD2DEG;
    joint_group_positions[3][1] = -1.15*RAD2DEG;
    joint_group_positions[3][2] = 0.02;

    //Pick position
    joint_group_positions[4][0] = -0.44*RAD2DEG;
    joint_group_positions[4][1] = 1.30*RAD2DEG;
    joint_group_positions[4][2] = 0.01;
    //work position
    joint_group_positions[5][0] = -0.68*RAD2DEG;
    joint_group_positions[5][1] = -1.45*RAD2DEG;
    joint_group_positions[5][2] = 0.0;
    //place position 2
    joint_group_positions[6][0] = 0.54*RAD2DEG;
    joint_group_positions[6][1] = -0.67*RAD2DEG;
    joint_group_positions[6][2] = 0.03;

    //Pick position
    joint_group_positions[7][0] = -0.44*RAD2DEG;
    joint_group_positions[7][1] = 1.30*RAD2DEG;
    joint_group_positions[7][2] = 0.01;
    //work position
    joint_group_positions[8][0] = -0.68*RAD2DEG;
    joint_group_positions[8][1] = -1.45*RAD2DEG;
    joint_group_positions[8][2] = 0.0;
    //place position 3
    joint_group_positions[9][0] = 0.26*RAD2DEG;
    joint_group_positions[9][1] = -1.55*RAD2DEG;
    joint_group_positions[9][2] = 0.03;

    //Pick position
    joint_group_positions[10][0] = -0.44*RAD2DEG;
    joint_group_positions[10][1] = 1.30*RAD2DEG;
    joint_group_positions[10][2] = 0.01;
    //work position
    joint_group_positions[11][0] = -0.68*RAD2DEG;
    joint_group_positions[11][1] = -1.45*RAD2DEG;
    joint_group_positions[11][2] = 0.0;
    //place position 4
    joint_group_positions[12][0] = 0.49*RAD2DEG;
    joint_group_positions[12][1] = -1.28*RAD2DEG;
    joint_group_positions[12][2] = 0.03;
    ROS_INFO("Vector filled up");

}
void setPositions(){

    ROS_INFO("VECTOR SIZE %d x %d \n", defaultPositions.size(),defaultPositions[0].size());
    //Home position
    defaultPositions[0][0] = 0;
    defaultPositions[0][1] = 0;
    defaultPositions[0][2] = 0.00;
    //Pick position
    defaultPositions[1][0] = -0.44*RAD2DEG;
    defaultPositions[1][1] = 1.30*RAD2DEG;
    defaultPositions[1][2] = 0.01;
    //work position
    defaultPositions[2][0] = -0.68*RAD2DEG;
    defaultPositions[2][1] = -1.45*RAD2DEG;
    defaultPositions[2][2] = 0.0;

    //place position 1
    defaultPositions[3][0] = 0.21*RAD2DEG;
    defaultPositions[3][1] = -1.15*RAD2DEG;
    defaultPositions[3][2] = 0.02;
    //place position 2
    defaultPositions[4][0] = 0.54*RAD2DEG;
    defaultPositions[4][1] = -0.67*RAD2DEG;
    defaultPositions[4][2] = 0.03;
    //place position 3
    defaultPositions[5][0] = 0.23*RAD2DEG;
    defaultPositions[5][1] = -1.25*RAD2DEG;
    defaultPositions[5][2] = 0.03;
    //place position 4
    defaultPositions[6][0] = 0.50*RAD2DEG;
    defaultPositions[6][1] = -0.90*RAD2DEG;
    defaultPositions[6][2] = 0.03;
    //place position 5
    defaultPositions[7][0] = 0.21*RAD2DEG;
    defaultPositions[7][1] = -1.45*RAD2DEG;
    defaultPositions[7][2] = 0.03;
    //place position 6
    defaultPositions[8][0] = 0.45*RAD2DEG;
    defaultPositions[8][1] = -1.12*RAD2DEG;
    defaultPositions[8][2] = 0.03;
    //place position 7
    defaultPositions[9][0] = 0.26*RAD2DEG;
    defaultPositions[9][1] = -1.55*RAD2DEG;
    defaultPositions[9][2] = 0.03;
    //place position 8
    defaultPositions[10][0] = 0.49*RAD2DEG;
    defaultPositions[10][1] = -1.28*RAD2DEG;
    defaultPositions[10][2] = 0.03;
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
void jointModeControll (moveit::planning_interface::MoveGroupInterface *move_group, moveit::planning_interface::MoveGroupInterface::Plan my_plan, int mode, int number_of_place_position){

    bool success;
    if (mode == 0){         //Home position
        joint_group_position[0] = defaultPositions[0][0]*DEG2RAD;  // radians
        joint_group_position[1] = defaultPositions[0][1]*DEG2RAD;
        joint_group_position[2] = defaultPositions[0][2];
        ROS_INFO("moving to home");
    }else if (mode == 1){      //pick position
        joint_group_position[0] = defaultPositions[1][0]*DEG2RAD;  // radians
        joint_group_position[1] = defaultPositions[1][1]*DEG2RAD;
        joint_group_position[2] = defaultPositions[1][2];
        ROS_INFO("moving to pick");
    }else if (mode == 2){       //work position
        joint_group_position[0] = defaultPositions[2][0]*DEG2RAD;  // radians
        joint_group_position[1] = defaultPositions[2][1]*DEG2RAD;
        joint_group_position[2] = defaultPositions[2][2];
        ROS_INFO("moving to work");
    }
    else if (mode == 3){        //place position
        if (number_of_place_position == 1){
            joint_group_position[0] = defaultPositions[3][0]*DEG2RAD;  // radians
            joint_group_position[1] = defaultPositions[3][1]*DEG2RAD;
            joint_group_position[2] = defaultPositions[3][2];
        }else if (number_of_place_position == 2){
            joint_group_position[0] = defaultPositions[4][0]*DEG2RAD;  // radians
            joint_group_position[1] = defaultPositions[4][1]*DEG2RAD;
            joint_group_position[2] = defaultPositions[4][2];
        }else if (number_of_place_position == 3){
            joint_group_position[0] = defaultPositions[5][0]*DEG2RAD;  // radians
            joint_group_position[1] = defaultPositions[5][1]*DEG2RAD;
            joint_group_position[2] = defaultPositions[5][2];
        }else if (number_of_place_position == 4){
            joint_group_position[0] = defaultPositions[6][0]*DEG2RAD;  // radians
            joint_group_position[1] = defaultPositions[6][1]*DEG2RAD;
            joint_group_position[2] = defaultPositions[6][2];
        }else if (number_of_place_position == 5){
            joint_group_position[0] = defaultPositions[7][0]*DEG2RAD;  // radians
            joint_group_position[1] = defaultPositions[7][1]*DEG2RAD;
            joint_group_position[2] = defaultPositions[7][2];
        }else if (number_of_place_position == 6){
            joint_group_position[0] = defaultPositions[8][0]*DEG2RAD;  // radians
            joint_group_position[1] = defaultPositions[8][1]*DEG2RAD;
            joint_group_position[2] = defaultPositions[8][2];
        }else if (number_of_place_position == 7){
            joint_group_position[0] = defaultPositions[9][0]*DEG2RAD;  // radians
            joint_group_position[1] = defaultPositions[9][1]*DEG2RAD;
            joint_group_position[2] = defaultPositions[9][2];
        }else if (number_of_place_position == 8){
            joint_group_position[0] = defaultPositions[10][0]*DEG2RAD;  // radians
            joint_group_position[1] = defaultPositions[10][1]*DEG2RAD;
            joint_group_position[2] = defaultPositions[10][2];
        }else {
            ROS_INFO("NOT DEFINED position");
        }
        ROS_INFO("moving to place");
    }else{
        ROS_INFO("NOT DEFINED mode");
    }
    ROS_INFO("Desired joint values: %f  %f  %f",joint_group_position[0],joint_group_position[1],joint_group_position[2]);
    move_group->setJointValueTarget(joint_group_position);
    success = move_group->plan(my_plan);
    ROS_INFO_NAMED("Visualizing plan (joint space goal) %s", success ? "GOOD" : "FAILED");
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

    int counter = 1, mode = 0;
    bool success;
    static const std::string PLANNING_GROUP = "scara_arm";
    //static const std::string PLANNING_GROUP = "left_gripper";
    geometry_msgs::Pose target_pose1;

    geometry_msgs::PoseStamped ws1;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::core::RobotStatePtr current_state;

    //setDesiredAngles();
    setPositions();

    ros::init(argc, argv, "PICK_and_PLACE");
    ros::NodeHandle n, nn,n_rt;
    ros::Rate r(2);
    ros::AsyncSpinner spinner(1);
    spinner.start();
    //



    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

    ros::Publisher gripperState_pub = n.advertise<std_msgs::String>("gripper_state_topic", 1000);
    ros::Publisher grip_topic_pub =  nn.advertise<scara_v2_moveit_api::pose_and_gripperState>("gripper_state", 1000);
    ros::Publisher rt_pub = n_rt.advertise<std_msgs::String>("commandForRotaryTable", 1000);

    scara_v2_moveit_api::pose_and_gripperState gripperStates;
    gripperStates.gripperState = false;
    gripperStates.posX = 0.0;
    gripperStates.posY = 0.0;
    gripperStates.posZ = 0.0;

    std_msgs::String msg ;
    msg.data = "otoc_sa";


    bool initRT = false;


    while (ros::ok()) {


        //Get current pose of tool0
        target_pose1 = getTargetCoordinates(&move_group);
        ROS_INFO("[SCARA]: Actual joint values : x=%f  y=%f  z=%f",  target_pose1.position.x,target_pose1.position.y,target_pose1.position.z);
        //move to WS1
        current_state = move_group.getCurrentState();
        current_state->copyJointGroupPositions(joint_model_group, joint_group_position);

        if (mode == 3) {
            //ROS_INFO("mode : %d",mode);
            jointModeControll(&move_group, my_plan, mode, counter);
            counter++;
            if (counter > 8){
                counter = 1;
            }
            target_pose1 = getTargetCoordinates(&move_group);
            ROS_INFO ("[SCARA -> CUBE]: Gripper Place! and publish");
            gripperStates.gripperState = false;
            gripperStates.posX = target_pose1.position.x;
            gripperStates.posY = target_pose1.position.y;
            gripperStates.posZ = target_pose1.position.z;
            ROS_INFO_STREAM(gripperStates);
            grip_topic_pub.publish(gripperStates);

            mode = 0;
        }else {
            //tato cast nabehne len raz pri zaciatku
            jointModeControll(&move_group, my_plan, mode, 0);
            if (!initRT){
                rt_pub.publish(msg);
                ROS_INFO("[SCARA -> RT]: RT init : %s",msg.data.c_str());
                sleep(2);
                initRT=true;
            }
            //
            if (mode == 1){
                target_pose1 = getTargetCoordinates(&move_group);
                ROS_INFO ("[SCARA -> CUBE]: Gripper Pick! and publish");
                gripperStates.gripperState = true;
                gripperStates.posX = target_pose1.position.x;
                gripperStates.posY = target_pose1.position.y;
                gripperStates.posZ = target_pose1.position.z;
                grip_topic_pub.publish(gripperStates);
            }
            if (mode == 2){
                rt_pub.publish(msg);
                ROS_INFO("[SCARA -> RT]: RT turn : %s",msg.data.c_str());
                sleep(2);
            }
        }


        mode++;

        sleep(2);
    }



    return 0;
}
