//
// Created by viktor on 17/10/17.
//

#include "../include/rotary_table_menu.h"
#include "scara_v2_moveit_api/pose_velocity_direction.h"


int main(int argc, char **argv){


    ros::init(argc, argv, "menu_node");
    ros::NodeHandle n1,n2,n3,n4;
    ros::NodeHandle nn1,nn2,nn3,nn4;
    ros::Rate loop_rate(10);
    ros::AsyncSpinner spinner(1);
    spinner.start();

    uint8_t data[8];
    can_frame frame;

    can = new Can_interface();
    std::vector<int > ids;
    ids.push_back(0x210);
    ids.push_back(0x211);
    ids.push_back(0x212);
//    try {
//        can->initCAN("can0", ids, -1);
//    } catch(std::exception& e){
//            ROS_ERROR("%s", e.what());
//        return -1;
//    }

    ROS_WARN("Init publishers:");
        currentRotationInDeg_pub = n1.advertise<std_msgs::Int32>("currentAngleDeg_RT",1000);
        ROS_INFO("currentAngleDeg_RT");
        currentVelocityInDeg_pub = n2.advertise<std_msgs::Int32>("currentVelocityPerMinute_RT",1000);
        ROS_INFO("currentAngleDeg_RT");
        currentStatus_pub = n3.advertise<std_msgs::Int32>("currentWorkingState_RT",1000);
        ROS_INFO("currentWorkingState_RT");
        currentError_pub = n4.advertise<std_msgs::Int32>("currentWorkingError_RT",1000);
        ROS_INFO("currentWorkingError_RT");
    //dodat aj rychlost

    ROS_WARN("Init subscribers:");
        rotateCommand_sub = nn1.subscribe("rotate_DEC_RT",1000,rotateCommandCallback);
        ROS_INFO("rotate_DEC_RT");
        workingStateCommand_sub = nn2.subscribe("set_working_mode_RT",1000,workingStateCommandCallback);
        ROS_INFO("set_working_mode_RT");

    while (ros::ok()){

        can->readCAN(&frame);
        decodeCANmsg(&frame);

        ros::spinOnce();
        loop_rate.sleep();
    }


    return 0;
}