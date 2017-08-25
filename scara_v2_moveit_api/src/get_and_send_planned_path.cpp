//
// Created by viktor on 25/08/17.
//

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include "math.h"
#include <tf/transform_listener.h>
#include <moveit/robot_trajectory/robot_trajectory.h>
#include "moveit/robot_model_loader/robot_model_loader.h"
#include <moveit/trajectory_processing/iterative_time_parameterization.h>
#include <industrial_trajectory_filters/filter_base.h>
#include <industrial_trajectory_filters/uniform_sample_filter.h>
#include "control_msgs/FollowJointTrajectoryGoal.h"
#include "joint_limits_interface/joint_limits.h"
#include <joint_limits_interface/joint_limits_urdf.h>
#include <joint_limits_interface/joint_limits_rosparam.h>
#include "moveit_msgs/DisplayTrajectory.h"

moveit_msgs::DisplayTrajectory trajectory;


void displayPathCallback(const moveit_msgs::DisplayTrajectory dispTraj){

    ROS_INFO("%d",dispTraj.trajectory[0].joint_trajectory.points.size());
    ROS_INFO("trajectory 0");
    sleep(2);
    for (int i = 0; i< dispTraj.trajectory[0].joint_trajectory.points.size(); i++)
    {
        ROS_INFO_STREAM(dispTraj.trajectory[0].joint_trajectory.points[i]);
    }

}



int main(int argc, char **argv) {

    ros::init(argc, argv, "get_planned_path");
    ros::NodeHandle n1;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    ros::Subscriber trajectory_sub = n1.subscribe<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path",1000,displayPathCallback);


    while (ros::ok()){

        ros::spinOnce();
    }

    return 0;
}