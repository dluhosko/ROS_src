#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


ros::NodeHandle n_talker, n_subscriber;
/*
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    receivedMsg->data = msg->data;

}*/
int main(int argc, char **argv)
{/*
    ros::init(argc, argv, "talker_and_listener");

    ros::Publisher chatter_pub = n_talker.advertise<std_msgs::String>("chatter_publisher", 1000);
    ros::Subscriber chatter_sub = n_subscriber.subscribe("chatter_subscriber", 1000, chatterCallback);


    ros::Rate loop_rate(10);

    int count = 0;
    ROS_INFO("started loop");
    while (ros::ok())
    {

        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();

        //ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

*/
    return 0;
}