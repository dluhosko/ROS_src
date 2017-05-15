
#include <ros/ros.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/GetPositionIK.h>

#include "sensor_msgs/JointState.h"



//#include "../../ikfast_kinematics_plugin/templates/ikfast.h"

void printDefaultInformation(moveit::planning_interface::MoveGroupInterface *moveGroup){

    ROS_INFO_NAMED("\nReference frame: %s", moveGroup->getPlanningFrame().c_str());
    ROS_INFO_NAMED("End effector link: %s\n", moveGroup->getEndEffectorLink().c_str());
}

int main (int argc, char **argv){

    bool success;
    static const std::string PLANNING_GROUP = "scara_arm";
    geometry_msgs::Pose target_pose;
    geometry_msgs::PoseStamped ws1;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::core::RobotStatePtr current_state;
    //IKFAST
    moveit_msgs::GetPositionIK IKposition;

    //IKposition.request.

    ros::init(argc, argv, "pose_control");
    ros::NodeHandle n, nn;
    ros::Rate r(2);
    ros::AsyncSpinner spinner(1);
    spinner.start();


    //nejak to osetrit
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

    printDefaultInformation(&move_group);


    //0.34695; 0.19341; 0.97653


    ros::ServiceClient service_client = n.serviceClient<moveit_msgs::GetPositionIK>("compute_ik");
    while (!service_client.exists()){
        ROS_INFO("waiting for service");
        sleep(1.0);
    }

    //fill request message
    moveit_msgs::GetPositionIK::Request service_request;
    moveit_msgs::GetPositionIK::Response service_response;
    service_request.ik_request.group_name = PLANNING_GROUP;
    service_request.ik_request.pose_stamped.header.frame_id="tool0";
    service_request.ik_request.pose_stamped.pose.position.x = 0.34695;
    service_request.ik_request.pose_stamped.pose.position.y = 0.19341;
    service_request.ik_request.pose_stamped.pose.position.z = 0.97653;
    service_request.ik_request.pose_stamped.pose.orientation.x = 0.0;
    service_request.ik_request.pose_stamped.pose.orientation.y = 0.0;
    service_request.ik_request.pose_stamped.pose.orientation.z = 0.0;
    service_request.ik_request.pose_stamped.pose.orientation.w = 1.0;
    //colision avoidance
    service_request.ik_request.avoid_collisions = true;

    if (service_client.call(service_request, service_response)) {
        ROS_INFO("good");
    }
    else
        ROS_INFO("bad");

    //Kinematic model tutorial
    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
    robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
    ROS_INFO("Model frame: %s", kinematic_model->getModelFrame().c_str());
    robot_state::RobotStatePtr kinematic_state(new robot_state::RobotState(kinematic_model));
    kinematic_state->setToDefaultValues();
    const std::vector<std::string> &joint_names = joint_model_group->getVariableNames();

    std::vector<double> joint_values;
    kinematic_state->copyJointGroupPositions(joint_model_group, joint_values);
    for (std::size_t i = 0; i < joint_names.size(); ++i)
    {
        ROS_INFO("Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
    }

    //joint_model_group = kinematic_state-
    //robot_state::JointStateGroup* joint_state_group = kinematic_state->getJointStateGroup(PLANNING_GROUP);
    //service_request.ik_request.robot_state.joint_state.name = joint




    while (ros::ok()){
        ROS_INFO_ONCE("while");

    }


    return 0;
}