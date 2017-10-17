//
// Created by viktor on 17/10/17.
//

#include "../include/rotary_table_menu.h"


int main(int argc, char **argv){

    char hexaNumber[20];
    char modifHexaNumber[24];

    ros::init(argc, argv, "menu_node");
    ros::NodeHandle n1;
    ros::Rate loop_rate(10);
    ros::AsyncSpinner spinner(1);
    spinner.start();


    while (ros::ok()){

        int inputNumber;
        ROS_INFO("enter decimal number");
        scanf("%d",&inputNumber);

        sprintf(hexaNumber,"%x",inputNumber);
        ROS_INFO("DEC (%d) -> HEX (%s)",inputNumber,hexaNumber);

        fillEmptyBytesInCANmsg(hexaNumber,modifHexaNumber,8);
        ROS_INFO("Fill missing bytes (%s) -> (%s)",hexaNumber,modifHexaNumber);

        convertCANmsg(modifHexaNumber,8);
        ROS_INFO("convert hexa number CAN clasic to CAN SENSODRIVE (%s)",modifHexaNumber);

        convertCANmsg(modifHexaNumber,8);
        ROS_INFO("convert hexa number CAN SENSODRIVE to CAN clasic (%s)",modifHexaNumber);


        ROS_INFO("hexa(%s) to decimal(%d)",modifHexaNumber,hex2dec(modifHexaNumber));


    }


    return 0;
}