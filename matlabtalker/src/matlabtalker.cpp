#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

    ros::init(argc, argv, "matlabtalker");
    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("matlabTalker", 1000);

    ros::Rate loop_rate(1);

    /**
     * A count of how many messages we have sent. This is used to create
     * a unique string for each message.
     */
    int count = 0;
    int max = 20;
    while (ros::ok())
    {
        geometry_msgs::Twist twistMsg;
        if (count <= max) {
            twistMsg.linear.x = count;
            twistMsg.linear.y = max - count ;
            twistMsg.linear.z = 2*count;
        }else{
            count = 0;
        }
        std_msgs::String msg;

        std::stringstream ss;
        ss << "Sent something to matlab.. " << count;
        msg.data = ss.str();
// %EndTag(FILL_MESSAGE)%

// %Tag(ROSCONSOLE)%
        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(twistMsg);
        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }


    return 0;
}