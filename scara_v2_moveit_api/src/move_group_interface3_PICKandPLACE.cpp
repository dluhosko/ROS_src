//
// Created by viktor on 09/05/17.
//

#include <ros/ros.h>

// MoveIt!
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/GetPositionIK.h>
#include <moveit_msgs/ExecuteTrajectoryActionResult.h>
#include <moveit/robot_state/conversions.h>
#include <geometric_shapes/solid_primitive_dims.h>
//msgs
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"
#include "scara_v2_moveit_api/pose_and_gripperState.h"
#include <sstream>






const double DEG2RAD=0.01745329252;
const double RAD2DEG=57.295779513;
std::vector<std::vector<double>> joint_group_positions(13, std::vector<double>(3));
std::vector<std::vector<double>> defaultPositions(11, std::vector<double>(3));
std::vector<std::vector<double>> defaultCartesianPosition(11, std::vector<double>(6));
std::vector<double> joint_group_position;
bool executionOK = false;
std::vector<geometry_msgs::Pose> waypoints(2);
int counter = 0;


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
bool setPositions(bool showAngles){

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
    if (showAngles) {
        ROS_INFO("VECTOR SIZE %d x %d \n", defaultPositions.size(), defaultPositions[0].size());
        ROS_INFO("default positions:");
        for (int i = 0; i < defaultCartesianPosition.size(); i++) {
            if (i == 0) {
                ROS_INFO("HOME pos:     x=%f  y=%f  z=%f", defaultPositions[i][0],
                         defaultPositions[i][1], defaultPositions[i][2]);
            } else if (i == 1) {
                ROS_INFO("PICK pos:     x=%f  y=%f  z=%f", defaultPositions[i][0],
                         defaultPositions[i][1], defaultPositions[i][2]);
            } else if (i == 2) {
                ROS_INFO("PLACE pos:    x=%f  y=%f  z=%f", defaultPositions[i][0],
                         defaultPositions[i][1], defaultPositions[i][2]);
            } else {
                ROS_INFO("PLACE pos %d: x=%f  y=%f  z=%f", i - 2, defaultPositions[i][0],
                         defaultPositions[i][1], defaultPositions[i][2]);
            }
        }
        sleep(2);
    }
  return true;
}
bool setCartesianPositions(bool showPositions){

//    defaultCartesianPosition.resize(11);
//    defaultCartesianPosition[0].resize(3);
    //Home position
        //xyz
            defaultCartesianPosition[0][0] = 0.704;
            defaultCartesianPosition[0][1] = 0.58;
            defaultCartesianPosition[0][2] = 1.02;
        //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;
    //Pick position
        //xyz
            defaultCartesianPosition[1][0] = 0.4;
            defaultCartesianPosition[1][1] = 0.24;
            defaultCartesianPosition[1][2] = 1.01;
    //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;
    //work position 0.57143; 0.6028; 1.02
            defaultCartesianPosition[2][0] = -0.57;
            defaultCartesianPosition[2][1] = 0.60;
            defaultCartesianPosition[2][2] = 1.04;
        //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;
    //place position 1 : 0.51; 0.87; 0.9735
        //xyz
            defaultCartesianPosition[3][0] = 0.51;
            defaultCartesianPosition[3][1] = 0.87;
            defaultCartesianPosition[3][2] = 1.01;
        //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;
    //place position 2 : 0.51; 0.93; 0.9735
        //xyz
            defaultCartesianPosition[4][0] = 0.51;
            defaultCartesianPosition[4][1] = 0.93;
            defaultCartesianPosition[4][2] = 1.01;
        //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;
    //place position 3 : 0.47; 0.87; 0.9735
        //xyz
            defaultCartesianPosition[5][0] = 0.47;
            defaultCartesianPosition[5][1] = 0.87;
            defaultCartesianPosition[5][2] = 1.01;
        //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;
    //place position 4 : 0.47; 0.93; 0.9735
        //xyz
            defaultCartesianPosition[6][0] = 0.47;
            defaultCartesianPosition[6][1] = 0.93;
            defaultCartesianPosition[6][2] = 1.01;
        //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;
    //place position 5 : 0.43; 0.87; 0.9735
        //xyz
            defaultCartesianPosition[7][0] = 0.43;
            defaultCartesianPosition[7][1] = 0.87;
            defaultCartesianPosition[7][2] = 1.01;
        //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;
    //place position 6 : 0.43; 0.93; 0.9735
        //xyz
            defaultCartesianPosition[8][0] = 0.43;
            defaultCartesianPosition[8][1] = 0.93;
            defaultCartesianPosition[8][2] = 1.01;
        //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;
    //place position 7 : 0.39; 0.87; 0.9735
        //xyz
            defaultCartesianPosition[9][0] = 0.39;
            defaultCartesianPosition[9][1] = 0.87;
            defaultCartesianPosition[9][2] = 1.01;
        //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;
    //place position 8 : 0.39; 0.87; 0.9735
        //xyz
            defaultCartesianPosition[10][0] = 0.39;
            defaultCartesianPosition[10][1] = 0.87;
            defaultCartesianPosition[10][2] = 1.01;
        //rpy
            defaultCartesianPosition[0][3] = 0.704;
            defaultCartesianPosition[0][4] = 0.58;
            defaultCartesianPosition[0][5] = 1.02;

    if (showPositions){
        ROS_INFO("VECTOR SIZE %d x %d \n", defaultCartesianPosition.size(),defaultCartesianPosition[0].size());
        ROS_INFO("default positions:");
        for (int i=0;i<defaultCartesianPosition.size();i++){
            if (i==0){
                ROS_INFO("HOME pos:     x=%f  y=%f  z=%f",defaultCartesianPosition[i][0],defaultCartesianPosition[i][1],defaultCartesianPosition[i][2]);
            }else if (i==1){
                ROS_INFO("PICK pos:     x=%f  y=%f  z=%f",defaultCartesianPosition[i][0],defaultCartesianPosition[i][1],defaultCartesianPosition[i][2]);
            }else if (i==2){
                ROS_INFO("PLACE pos:    x=%f  y=%f  z=%f",defaultCartesianPosition[i][0],defaultCartesianPosition[i][1],defaultCartesianPosition[i][2]);
            }else{
                ROS_INFO("PLACE pos %d: x=%f  y=%f  z=%f",i-2,defaultCartesianPosition[i][0],defaultCartesianPosition[i][1],defaultCartesianPosition[i][2]);
            }
        }
        sleep(2);
    }

    return 1;
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
void positionControll (moveit::planning_interface::MoveGroupInterface *move_group, moveit::planning_interface::MoveGroupInterface::Plan my_plan, int mode, int number_of_place_position){

    bool success;
    int numberOfAttempts =0;
    geometry_msgs::Pose position;

    position.orientation.x = 0.0;
    position.orientation.y = 0.0;
    position.orientation.z = 0.0;
    position.orientation.w = 0.0;

    if (mode == 0){         //Home position
        position.position.x = defaultCartesianPosition[0][0];
        position.position.y = defaultCartesianPosition[0][1];
        position.position.z = defaultCartesianPosition[0][2];
        ROS_INFO("moving to home");
    }else if (mode == 1){      //pick position
        position.position.x = defaultCartesianPosition[1][0];
        position.position.y = defaultCartesianPosition[1][1];
        position.position.z = defaultCartesianPosition[1][2];
        ROS_INFO("moving to pick");
    }else if (mode == 2){       //work position
        position.position.x = defaultCartesianPosition[2][0];
        position.position.y = defaultCartesianPosition[2][1];
        position.position.z = defaultCartesianPosition[2][2];
        ROS_INFO("moving to work");
    }
    else if (mode == 3){        //place position
        if (number_of_place_position == 1){
            position.position.x = defaultCartesianPosition[3][0];
            position.position.y = defaultCartesianPosition[3][1];
            position.position.z = defaultCartesianPosition[3][2];
        }else if (number_of_place_position == 2){
            position.position.x = defaultCartesianPosition[4][0];
            position.position.y = defaultCartesianPosition[4][1];
            position.position.z = defaultCartesianPosition[4][2];
        }else if (number_of_place_position == 3){
            position.position.x = defaultCartesianPosition[5][0];
            position.position.y = defaultCartesianPosition[5][1];
            position.position.z = defaultCartesianPosition[5][2];
        }else if (number_of_place_position == 4){
            position.position.x = defaultCartesianPosition[6][0];
            position.position.y = defaultCartesianPosition[6][1];
            position.position.z = defaultCartesianPosition[6][2];;
        }else if (number_of_place_position == 5){
            position.position.x = defaultCartesianPosition[7][0];
            position.position.y = defaultCartesianPosition[7][1];
            position.position.z = defaultCartesianPosition[7][2];
        }else if (number_of_place_position == 6){
            position.position.x = defaultCartesianPosition[8][0];
            position.position.y = defaultCartesianPosition[8][1];
            position.position.z = defaultCartesianPosition[8][2];
        }else if (number_of_place_position == 7){
            position.position.x = defaultCartesianPosition[9][0];
            position.position.y = defaultCartesianPosition[9][1];
            position.position.z = defaultCartesianPosition[9][2];
        }else if (number_of_place_position == 8){
            position.position.x = defaultCartesianPosition[10][0];
            position.position.y = defaultCartesianPosition[10][1];
            position.position.z = defaultCartesianPosition[10][2];
        }else {
            ROS_INFO("NOT DEFINED position");
        }
        ROS_INFO("moving to place pos:%d",number_of_place_position);
    }else{
        ROS_INFO("NOT DEFINED mode");
    }

    while (numberOfAttempts<3) {
        if (move_group->setApproximateJointValueTarget(position, "tool0")) {
            ROS_INFO("found IK solution");
            break;
        } else
            ROS_INFO("only aproximate IK solution");
        numberOfAttempts++;
    }
    success = move_group->plan(my_plan);
    ROS_INFO_STREAM("PLAN:" << success);
    if(success){

        int size=my_plan.trajectory_.joint_trajectory.points.size();

        ROS_INFO_STREAM("moje IK je");
        ROS_INFO_STREAM(my_plan.trajectory_.joint_trajectory.points[size-1]);
    }
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
void trajectoryExecutionCallback(const moveit_msgs::ExecuteTrajectoryActionResult result){
    ROS_INFO("Status = %d\n",result.status.status);
    if (result.status.status == 1 || result.status.status == 3){
        executionOK = true;
    }
}
void waitForSubscribers(ros::Publisher gripperState, ros::Publisher gripperTopic, ros::Publisher rotaryTable){

    //doladit nefunguje tak ako ma.. len ak dam rostopic echo
    while (gripperTopic.getNumSubscribers() <= 1){
        ROS_INFO("waiting for gripperTopic subscriber (%d)",gripperState.getNumSubscribers());
        sleep(1);
    }
    while (rotaryTable.getNumSubscribers() <= 1){
        ROS_INFO("waiting for rotary table subscriber (%d)",gripperState.getNumSubscribers());
        sleep(1);
    }
    ROS_INFO("Every subscriber OK");
    sleep(1);

}
int menu (){
    ROS_INFO("\n");
    ROS_INFO("************ SENSODRIVE SCARA *********************");
    ROS_INFO("**************       menu      **********************");
    ROS_INFO("Press 1 for:\t JOINT CONTROL");
    ROS_INFO("Press 2 for:\t POSITION CONTROL");
    ROS_INFO("Press 5 for:\t INFO");
    ROS_INFO("Press etc for:\t something");
    ROS_INFO("Press 9 for:\tEXIT");
    ROS_INFO("*****************************************************");
    int number;

    while (1){
        number = getchar() - 48;
        ROS_INFO("number = %d",number);
        if (number == 1){
            ROS_INFO("You have choosed %d - JOINT CONTROL",number);
            break;
        }else if (number == 2){
            ROS_INFO("You have choosed %d - POSITION CONTROL",number);
            break;
        }
        else if (number == 5){
            ROS_INFO("You have choosed %d - INFO",number);
            break;
        }
        else if (number == 9){
            ROS_INFO("You have choosed %d - EXIT",number);
            return -1;
        }else{
            ROS_INFO("NOT VALID");
        }
        sleep(1);
    }

    return number;


}

int main(int argc, char **argv){

    int counter = 1, mode = 0;
    bool success;
    static const std::string PLANNING_GROUP = "scara_arm";
    geometry_msgs::Pose target_pose1;
    geometry_msgs::PoseStamped ws1;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::core::RobotStatePtr current_state;
    moveit_msgs::RobotTrajectory trajectory;
    const double jump_threshold = 0.0;
    const double eef_step = 0.01;
    geometry_msgs::Pose selfPosition;
    geometry_msgs::PoseStamped position;
    moveit_msgs::RobotState robot_state;




    ros::init(argc, argv, "PICK_and_PLACE");
    ros::NodeHandle n, nn,n_rt;
    ros::Rate r(2);
    ros::AsyncSpinner spinner(1);
    spinner.start();
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

    int num = menu();
    if (num == 1){
        //setDesiredAngles();
        if (setPositions(false)){
            ROS_INFO("default positions for Joint control OK");
        }
    }else if (num == 2){
        if (setCartesianPositions(true)){
            ROS_INFO("default positions for Cartesian planning  OK");
            ros::ServiceClient service_client = n.serviceClient<moveit_msgs::GetPositionIK>("compute_ik");
            ros::Subscriber executeTrajectory = nn.subscribe("execute_trajectory/result",1000,trajectoryExecutionCallback);
            while (!service_client.exists()){
                ROS_INFO("waiting for service");
                sleep(1.0);
            }
            position = move_group.getCurrentPose();
            ROS_INFO_STREAM("REFERENCNY FRAME");
            ROS_INFO_NAMED("tutorial", "Reference frame: %s", move_group.getPlanningFrame().c_str());
            ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group.getEndEffectorLink().c_str());
            selfPosition.position = position.pose.position;
            selfPosition.orientation = position.pose.orientation;
            //ROS_INFO("Self position");
            //ROS_INFO_STREAM(selfPosition);
            moveit::core::robotStateToRobotStateMsg(*move_group.getCurrentState(), robot_state, true);
            move_group.setMaxVelocityScalingFactor(0.1);
            move_group.setMaxAccelerationScalingFactor(0.1);
        }
    }else if (num == 5){
        //doplnit

    }else if (num == -1){
        ROS_INFO("program END!");
        ros::shutdown();
        spinner.stop();
        return 0;
    }
    sleep(5);

    ros::Publisher gripperState_pub = n.advertise<std_msgs::String>("gripper_state_topic", 1000);
    ros::Publisher grip_topic_pub =  nn.advertise<scara_v2_moveit_api::pose_and_gripperState>("gripper_state", 1000);
    ros::Publisher rt_pub = n_rt.advertise<std_msgs::String>("commandForRotaryTable", 1000);
    //waitForSubscribers(gripperState_pub, grip_topic_pub, rt_pub);

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
            if (num == 1){
                jointModeControll(&move_group, my_plan, mode, counter);
            }else if (num == 2){
                positionControll(&move_group, my_plan, mode, counter);
            }else{
                ROS_ERROR("NOT VALID CONTROL MODE");
            }
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
            if (num == 1){
                jointModeControll(&move_group, my_plan, mode, 0);
            }else if (num == 2){
                positionControll(&move_group, my_plan, mode, 0);
            }else{
                ROS_ERROR("NOT VALID CONTROL MODE");
            }
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
