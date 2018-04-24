//
// Created by viktor on 24/04/18.
//

#include "../include/multiple_cylinder_publisher_scara_v3.h"


int main(int argc, char **argv){
    ros::init(argc, argv, "cube_node");
    ros::NodeHandle n, node_gripper;
    //ros::Subscriber sub = n.subscribe("gripper_state_topic", 1000, chatterCallback);
    ros::Rate loop_rate(30);

    ros::NodeHandle nn, node_handle;
    ros::Publisher vis_pub = node_handle.advertise<visualization_msgs::Marker>( "visualization_marker", 1 );
    //ros::Subscriber grip_topic_sub = node_gripper.subscribe("gripper_state",1000,gripperCallback);


    while(ros::ok()) {
        ROS_INFO_ONCE("[CYLINDER PUBLISHER NODE]: Started publishing cylinders");

        for (int i=1;i<=8;i++){
            generate_pick_cylinders(&vis_pub,i,0);
            generate_place_cylinders(&vis_pub,i,0);
            generate_attached_cylinder(&vis_pub,true);
        }
        ros::spinOnce();
        loop_rate.sleep();
    }


    return 0;
}