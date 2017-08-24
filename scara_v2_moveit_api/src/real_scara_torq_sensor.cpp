//
// Created by viktor on 23/08/17.
//

#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Bool.h"
#include <boost/thread/thread.hpp>
#include <boost/thread.hpp>

double max_torque_value = 10.0, torque_value = 0.0;
bool colision_detection = false, colision_detection_ack = false;
bool pushbuttonInterupt = false;
int currentMode = 7;

void forceFeedbackThread(){

    ROS_INFO("forcefeedback thread start");
    int i=0;

    while (ros::ok()){

        if (i == 5000) {
            ROS_INFO("[forcefeedback thread] torque value=%f (max=%f)", torque_value, max_torque_value);
            i = 0;
        }
        i++;

        if (torque_value >= max_torque_value){
            ROS_ERROR("[forcefeedback thread] STOP %d",i++);
            colision_detection = true;

            break;
        }
    }
}
void torqueSensorCallback(const std_msgs::Float64 torqueValue){

    //ROS_INFO("torque CALLBACK %f",torqueValue);
    torque_value = torqueValue.data;
}
void pushbuttonCallback(const std_msgs::Bool pushbuttonValue){

    //ROS_INFO("torque CALLBACK %f",torqueValue);
    pushbuttonInterupt = pushbuttonValue.data;
    if (torque_value < max_torque_value){
        if (pushbuttonInterupt){
            colision_detection = false;
        }
    }else{
       pushbuttonInterupt = false;
    }

}

int main(int argc, char **argv){

    ros::init(argc, argv, "PICK_and_PLACE");
    ros::NodeHandle n1, n2,n3;
    ros::Rate r(2);
    ros::AsyncSpinner spinner(1);
    spinner.start();
    ros::Rate loop_rate(10);

    std_msgs::Int32 current_mode;
    current_mode.data = 7;


    ros::Publisher modeSelect = n1.advertise<std_msgs::Int32>("modeSelect",1000);
    ros::Subscriber pushbutton = n2.subscribe("scara_pushbutton",1000,pushbuttonCallback);
    ros::Subscriber torqueSensor= n3.subscribe("torqueSensor",1000,torqueSensorCallback);

    printf("\nSelect max_torque_value : ");
    scanf("%lf",&max_torque_value);
    ROS_WARN("Max torque value has been set to %f", max_torque_value);
    ROS_INFO("Hit any key to continue...");
    getchar();

    ROS_INFO("Started mode 7");
    for (int i=0;i<10;i++){
        modeSelect.publish(current_mode);    //pre istotu vypublikujem 10x
    }
    sleep(2);

    boost::thread fft{forceFeedbackThread}; //zapnutie paralelneho vlakna ktore bude sledovat torque_value

    while (1){

        if (colision_detection){
            current_mode.data = 2;
            ROS_INFO("mode 2");
            modeSelect.publish(current_mode);
        }
        if (pushbuttonInterupt){
            ROS_INFO("restart mode 7!!");
            current_mode.data = 7;
            for (int i=0;i<10;i++){
                modeSelect.publish(current_mode);    //pre istotu vypublikujem 10x
            }
            boost::thread fft{forceFeedbackThread};
            pushbuttonInterupt = false;
            sleep(2);
        }

        ros::spinOnce();
        loop_rate.sleep();

    }






    return 0;
}