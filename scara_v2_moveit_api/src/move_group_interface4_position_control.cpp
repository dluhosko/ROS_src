//
//#include <ros/ros.h>
//#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
//#include <moveit/planning_scene_interface/planning_scene_interface.h>
//#include <moveit/move_group_interface/move_group_interface.h>
//#include <moveit_msgs/GetPositionIK.h>
//#include <moveit/robot_state/conversions.h>
//
//#include "sensor_msgs/JointState.h"
//
//
//
////#include "../../ikfast_kinematics_plugin/templates/ikfast.h"
//
//void printDefaultInformation(moveit::planning_interface::MoveGroupInterface *moveGroup){
//
//    ROS_INFO_NAMED("\nReference frame: %s", moveGroup->getPlanningFrame().c_str());
//    ROS_INFO_NAMED("End effector link: %s\n", moveGroup->getEndEffectorLink().c_str());
//}
//
//int main (int argc, char **argv){
//
//    bool success;
//    static const std::string PLANNING_GROUP = "scara_arm";
//    geometry_msgs::Pose target_pose;
//    geometry_msgs::PoseStamped ws1;
//    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
//    moveit::core::RobotStatePtr current_state;
//    //IKFAST
//    moveit_msgs::GetPositionIK IKposition;
//
//    //IKposition.request.
//
//    ros::init(argc, argv, "pose_control");
//    ros::NodeHandle n, nn;
//    ros::Rate r(2);
//    ros::AsyncSpinner spinner(1);
//    spinner.start();
//
//
//    //nejak to osetrit
//    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
//    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
//    const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);
//
//    printDefaultInformation(&move_group);
//
//
//    //0.34695; 0.19341; 0.97653
//
//
//    ros::ServiceClient service_client = n.serviceClient<moveit_msgs::GetPositionIK>("compute_ik");
//    while (!service_client.exists()){
//        ROS_INFO("waiting for service");
//        sleep(1.0);
//    }
//
//    //move_group.setEndEffector("tool0");
//    const geometry_msgs::PoseStamped position = move_group.getCurrentPose();
//    ROS_INFO_STREAM("REFERENCNY FRAME");
//    ROS_INFO_NAMED("tutorial", "Reference frame: %s", move_group.getPlanningFrame().c_str());
//    ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group.getEndEffectorLink().c_str());
//    //ROS_INFO_STREAM(move_group.getPoseReferenceFrame());
//    ROS_INFO_STREAM(position);
//    moveit_msgs::RobotState robot_state;
//    moveit::core::robotStateToRobotStateMsg(*move_group.getCurrentState(), robot_state, true);
//    //fill request message
////    moveit_msgs::GetPositionIK::Request service_request;
////    moveit_msgs::GetPositionIK::Response service_response;
////    service_request.ik_request.group_name = PLANNING_GROUP;
////    service_request.ik_request.pose_stamped.header.frame_id="/world";
////    service_request.ik_request.ik_link_name = "tool0";
////    service_request.ik_request.robot_state=robot_state;
//    std::vector<geometry_msgs::Pose> positions;
//
//    geometry_msgs::Pose positionaa;
//    positionaa.position.x = 0.34;
//    positionaa.position.y = 0.23;
//    positionaa.position.z = 1.05;
//    //0.98192; -0.1893; 7.5023e-05; 0.00038916
////    positionaa.orientation.x = 0.98;
////    positionaa.orientation.y = -0.189;
////    positionaa.orientation.z = 0;
////    positionaa.orientation.w = 0.00039;
//    positionaa.orientation.x = 0;
//    positionaa.orientation.y = 0;
//    positionaa.orientation.z = 0;
//    positionaa.orientation.w = 0;
//
//
//
///*
//    position:
//    x: 0.637025
//    y: 0.796651
//    z: 1.05641
//    orientation:
//    x: -0.288818
//    y: -0.644892
//    z: 0.645568
//    w: 0.289727
//
//
//*/
//    positions.resize(2);
//    moveit::planning_interface::MoveGroupInterface::Plan plan;
//    move_group.setApproximateJointValueTarget(positionaa,"tool0");
//   // move_group.setPositionTarget(positionaa.position.x,positionaa.position.y,positionaa.position.z,"tool0");
//
//    int a = move_group.plan(plan);
//    ROS_INFO_STREAM("PLAN:" << a);
//    if(a){
//
//        int size=plan.trajectory_.joint_trajectory.points.size();
//
//        ROS_INFO_STREAM("moje IK je");
//        ROS_INFO_STREAM(plan.trajectory_.joint_trajectory.points[size-1]);
//    }
//    move_group.execute(plan);
//    move_group.move();
//
//    ROS_INFO_STREAM(position);
//
//    /*ROS_INFO_STREAM(robot_state);
//    move_group.setStartState(robot_state);
//    move_group.setPositionTarget(position.pose.position.x,position.pose.position.y,position.pose.position.z,"tool0");
//    move_group.setGoalTolerance(0.1);
//    move_group.setPlannerId("RRTConnectkConfigDefault");
//    move_group.setPlanningTime(10);
//    move_group.allowReplanning(true);
//    move_group.setNumPlanningAttempts(10);
//    //move_group.setRandomTarget();
//    moveit::planning_interface::MoveGroupInterface::Plan plan;
//
//    int a = move_group.plan(plan);
//    ROS_INFO_STREAM("PLAN:" << a);
//    if(a){
//
//
//
//    int size=plan.trajectory_.joint_trajectory.points.size();
//
//    ROS_INFO_STREAM("moje IK je");
//    ROS_INFO_STREAM(plan.trajectory_.joint_trajectory.points[0]);
//    }
//*/
//    //0.70468; 0.58; 1.0196
////    service_request.ik_request.pose_stamped.pose.position.x = position.pose.position.x;
////    service_request.ik_request.pose_stamped.pose.position.y = position.pose.position.y;
////    service_request.ik_request.pose_stamped.pose.position.z = position.pose.position.z;
////
////    //-0.4996; -0.4996; 0.5004; 0.5004
////    service_request.ik_request.pose_stamped.pose.orientation.x = position.pose.orientation.x;
////    service_request.ik_request.pose_stamped.pose.orientation.y = position.pose.orientation.y;
////    service_request.ik_request.pose_stamped.pose.orientation.z = position.pose.orientation.z;
////    service_request.ik_request.pose_stamped.pose.orientation.w = position.pose.orientation.w;
////    //colision avoidance
////    service_request.ik_request.avoid_collisions = true;
////    service_request.ik_request.attempts = 10;
////
////    if (service_client.call(service_request, service_response)) {
////        ROS_INFO("good");
////    }
////    else
////        ROS_INFO("bad");
////
////    ROS_INFO_STREAM("IK zo servisu je");
////    ROS_INFO_STREAM(service_response);
//
///*
//    //Kinematic model tutorial
//    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
//    robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
//    ROS_INFO("Model frame: %s", kinematic_model->getModelFrame().c_str());
//    robot_state::RobotStatePtr kinematic_state(new robot_state::RobotState(kinematic_model));
//    kinematic_state->setToDefaultValues();
//    const std::vector<std::string> &joint_names = joint_model_group->getVariableNames();
//
//    std::vector<double> joint_values;
//    kinematic_state->copyJointGroupPositions(joint_model_group, joint_values);
//    for (std::size_t i = 0; i < joint_names.size(); ++i)
//    {
//        ROS_INFO("Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
//    }
//
//    //joint_model_group = kinematic_state-
//    //robot_state::JointStateGroup* joint_state_group = kinematic_state->getJointStateGroup(PLANNING_GROUP);
//    //service_request.ik_request.robot_state.joint_state.name = joint
//
//
//    ROS_INFO_ONCE("while");*/
//    spinner.stop();
//
//    /*while (ros::ok()){
//        ROS_INFO_ONCE("while");
//
//    }*/
//    ros::shutdown();
//
//    return 0;
//}




#include <ros/ros.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/GetPositionIK.h>
#include <moveit_msgs/ExecuteTrajectoryActionResult.h>
#include <moveit/robot_state/conversions.h>

#include "sensor_msgs/JointState.h"


bool executionOK = false;

void printDefaultInformation(moveit::planning_interface::MoveGroupInterface *moveGroup){

    ROS_INFO_NAMED("\nReference frame: %s", moveGroup->getPlanningFrame().c_str());
    ROS_INFO_NAMED("End effector link: %s\n", moveGroup->getEndEffectorLink().c_str());
}
void trajectoryExecutionCallback(const moveit_msgs::ExecuteTrajectoryActionResult result){
    ROS_INFO("Status = %d\n",result.status.status);
    if (result.status.status == 1 || result.status.status == 3){
        executionOK = true;
    }
}

int main (int argc, char **argv){

    bool success;
    static const std::string PLANNING_GROUP = "scara_arm";
    geometry_msgs::Pose target_pose;
    geometry_msgs::PoseStamped ws1;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::core::RobotStatePtr current_state;
    moveit_msgs::RobotTrajectory trajectory;
    const double jump_threshold = 0.0;
    const double eef_step = 0.01;
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
    //add and remove collision objects
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

    printDefaultInformation(&move_group);


    //0.34695; 0.19341; 0.97653


    ros::ServiceClient service_client = n.serviceClient<moveit_msgs::GetPositionIK>("compute_ik");
    ros::Subscriber executeTrajectory = nn.subscribe("execute_trajectory/result",1000,trajectoryExecutionCallback);
    while (!service_client.exists()){
        ROS_INFO("waiting for service");
        sleep(1.0);
    }

    //move_group.setEndEffector("tool0");
    const geometry_msgs::PoseStamped position = move_group.getCurrentPose();
    ROS_INFO_STREAM("REFERENCNY FRAME");
    ROS_INFO_NAMED("tutorial", "Reference frame: %s", move_group.getPlanningFrame().c_str());
    ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group.getEndEffectorLink().c_str());


//    robot_model_loader::RobotModelLoader robot_model_loader("scara_arm");
//    robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
//    planning_scene::PlanningScenePtr planning_scene(new planning_scene::PlanningScene(kinematic_model));


    geometry_msgs::Pose selfPosition;
    std::vector<geometry_msgs::Pose> waypoints;
    selfPosition.position = position.pose.position;
    selfPosition.orientation = position.pose.orientation;
    ROS_INFO("Self position");
    ROS_INFO_STREAM(selfPosition);


    sleep(5);
    moveit_msgs::RobotState robot_state;
    moveit::core::robotStateToRobotStateMsg(*move_group.getCurrentState(), robot_state, true);


    std::vector<geometry_msgs::Pose> positions;

    geometry_msgs::Pose positionaa;

    /*Default*/
    //0.4; 0.24; 1
    positionaa.position.x = 0.48;
    positionaa.position.y = 0.90;
    positionaa.position.z =  1.03;

    positionaa.orientation.x = 0;
    positionaa.orientation.y = 0;
    positionaa.orientation.z = 0;
    positionaa.orientation.w = 0;
    /*_________*/

//    waypoints.push_back(selfPosition);
//    waypoints.push_back(positionaa);

//    geometry_msgs::Pose positionaaa;
//    //0.51698; 0.49114; 0.97059
//    //0.37654; 0.36284; 1.0353
//    //0.70476; 0.58; 1.0196
//    positionaaa.position.x = 0.63;
//    positionaaa.position.y = 0.79;
//    positionaaa.position.z = 1.05;
//    //0.46503; 0.88529; -0.00035087; 0.00018431
//    positionaaa.orientation.x = 0;
//    positionaaa.orientation.y = 0;
//    positionaaa.orientation.z = 0;
//    positionaaa.orientation.w = 0;
//    waypoints.push_back(positionaaa);

//    ROS_INFO("Waypoints");
//    for (int i=0;i<waypoints.size();i++){
//        ROS_INFO_STREAM(waypoints[i]);
//    }
//    sleep(3);


    positions.resize(2);
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    if(move_group.setApproximateJointValueTarget(positionaa,"tool0")){
        ROS_INFO("found IK solution");
    }else
        ROS_INFO("only aproximate IK solution");

    move_group.setMaxVelocityScalingFactor(0.1);
    move_group.setMaxAccelerationScalingFactor(0.1);

    //***********************  MIRKO SI SEXY AKO RIT ********************************//

   double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold,trajectory);
    ROS_INFO("kokot");
   ROS_INFO_STREAM(fraction);
    //*******************************************************************************//

 sleep(3);


    int a = move_group.plan(plan);
    ROS_INFO_STREAM("PLAN:" << a);
    if(a){

        int size=plan.trajectory_.joint_trajectory.points.size();

        ROS_INFO_STREAM("moje IK je");
        ROS_INFO_STREAM(plan.trajectory_.joint_trajectory.points[size-1]);
    }
    move_group.execute(plan);

    selfPosition.position = position.pose.position;
    selfPosition.orientation = position.pose.orientation;
    ROS_INFO("Self position");
    ROS_INFO_STREAM(selfPosition);
    // move_group.move();



//    move_group.asyncExecute(plan);
//
//    while (ros::ok()){
//       ROS_INFO_ONCE("async while");
//        if (executionOK){
//            ROS_INFO("while break");
//            break;
//        }
//        //sleep(0.5);
//        move_group.stop();
//        geometry_msgs::PoseStamped pos = move_group.getCurrentPose();
//        ROS_INFO_STREAM(pos);
//        break;
//
//
//    }

    spinner.stop();
    ros::shutdown();

    return 0;
}