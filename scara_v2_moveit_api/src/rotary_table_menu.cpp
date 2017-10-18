//
// Created by viktor on 17/10/17.
//

#include "../include/rotary_table_menu.h"
#include "scara_v2_moveit_api/pose_velocity_direction.h"


int main(int argc, char **argv){

    char hexaNumber[20];
    char modifHexaNumber[24];
    hexNum = hexaNumber;
    modifHexNum = modifHexaNumber;

    ros::init(argc, argv, "menu_node");
    ros::NodeHandle n1,n2,n3,n4;
    ros::NodeHandle nn1,nn2,nn3,nn4;
    ros::Rate loop_rate(10);
    ros::AsyncSpinner spinner(1);
    spinner.start();


    ROS_WARN("Init publishers:");
    currentRotationInDeg_pub = n1.advertise<std_msgs::Int32>("currentAngleDeg_RT",1000);
    ROS_INFO("currentAngleDeg_RT");
    currentWorkingState_pub = n2.advertise<std_msgs::Int32>("currentWorkingState_RT",1000);
    ROS_INFO("currentWorkingState_RT");

    ROS_WARN("Init subscribers:");
    rotateCommand_sub = nn1.subscribe("rotate_DEC_RT",1000,rotateCommandCallback);
    ROS_INFO("rotate_DEC_RT");
    workingStateCommand_sub = nn2.subscribe("set_working_mode_RT",1000,workingStateCommandCallback);
    ROS_INFO("set_working_mode_RT");

    while (ros::ok()){


        /********************** test of convesion *********************/
        /*int inputNumber;
        ROS_INFO("enter decimal number");
        scanf("%d",&inputNumber);

        sprintf(hexaNumber,"%x",inputNumber);
        ROS_INFO("DEC (%d) -> HEX (%s)",inputNumber,hexaNumber);

        fillEmptyBytesInCANmsg(hexaNumber,modifHexaNumber,8);
        ROS_INFO("Fill missing bytes (%s) -> (%s)",hexaNumber,modifHexaNumber);

        ROS_WARN("hexaNumber=%s /*hexNum=%s  (size %d/%d)",hexaNumber,hexNum,std::strlen(hexaNumber),std::strlen(hexNum));
        ROS_WARN("modifHexaNumber=%s /*modifHexNum=%s",modifHexaNumber,modifHexNum);
        sleep(2);

        convertCANmsg(modifHexaNumber,8);
        ROS_INFO("convert hexa number CAN clasic to CAN SENSODRIVE (%s)",modifHexaNumber);

        convertCANmsg(modifHexaNumber,8);
        ROS_INFO("convert hexa number CAN SENSODRIVE to CAN clasic (%s)",modifHexaNumber);


        ROS_INFO("hexa(%s) to decimal(%d)",modifHexaNumber,hex2dec(modifHexaNumber));*/
        /*********************** end of test *************************/


        ros::spinOnce();
        loop_rate.sleep();


    }


    return 0;
}