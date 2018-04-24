//
// Created by viktor on 24/04/18.
//

#include "../include/multiple_cylinder_publisher_scara_v3.h"


int main(int argc, char **argv){
    ros::init(argc, argv, "cube_node");
    ros::NodeHandle n, node_gripper;
    //ros::Subscriber sub = n.subscribe("gripper_state_topic", 1000, chatterCallback);
    ros::Rate loop_rate(5);

    ros::NodeHandle nn, node_handle;
    ros::Publisher vis_pub = node_handle.advertise<visualization_msgs::Marker>( "visualization_marker", 1 );
    //ros::Subscriber grip_topic_sub = node_gripper.subscribe("gripper_state",1000,gripperCallback);


    while(ros::ok()) {




        ros::spinOnce();
        loop_rate.sleep();
    }


    return 0;
}