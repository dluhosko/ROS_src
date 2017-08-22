//
// Created by viktor on 22/08/17.
//


using namespace std;
#include "../include/menu_tryout_1.h"


int main(int argc, char **argv){

    ros::init(argc, argv, "gui_node");
    ros::NodeHandle n, node_gripper;
    ros::Rate loop_rate(10);

    printf("\nInput menu number:");
    scanf("%d",&input_number);

    while (1){


        if (!input_recognition())
        {
            ROS_WARN("program ended because of central stop");
            ros::shutdown();
            return 0;
        }
    }




}