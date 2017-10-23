//
// Created by viktor on 17/10/17.
//

#ifndef PROJECT_ROTARY_TABLE_MENU_H
#define PROJECT_ROTARY_TABLE_MENU_H

#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include "scara_v2_moveit_api/pose_velocity_direction.h"
#include "scara_v2_moveit_api/pose_and_gripperState.h"
#include "scara_v2_moveit_api/status_rt.h"
#include <can_interface/can_interface.h>

//*********************************** Global Variables ****************************************//
int i = 0;
std_msgs::Int32 int32_msg;
scara_v2_moveit_api::pose_velocity_direction posVelDir_msg;
scara_v2_moveit_api::status_rt status_msg;
ros::Publisher currentRotationInDeg_pub, currentVelocityInDeg_pub, currentWorkingState_pub, currentError_pub, tempAndCurrentStatus_pub;
ros::Subscriber rotateCommand_sub, workingStateCommand_sub;
Can_interface *can;

//************************************* Functions *********************************************//
void clearArray(uint8_t *array, int size_of_array){

    for (int i=0;i<size_of_array;i++){
        array[i] = 0;
    }

}

void sendDesiredWorkingState(int inputNumber){

    uint8_t data_to_send[8];            //Create data array to be send
    can_frame frame;                    //Create CAN frame
    frame.can_id = 0x200;               //Define ID of frame
    frame.can_dlc = 1;                  //Define Length of frame

    switch (inputNumber){
        case 1: //OFF
        {
            ROS_INFO("desired state OFF");
            clearArray(data_to_send,8);
            int data = 0x10;                                                  //10
            memcpy(data_to_send,&data,1*sizeof(uint8_t));                   //Fill data to be send to array of size 8
            memcpy(&frame.data, data_to_send,sizeof(data_to_send));         //Create can message (copy array of size 8 to can structure)
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame.data[i]);
            //can->writeCAN(&frame);                                                  //Write CAN message to CAN bus
            break;
        }
        case 2: //READY
        {
            ROS_INFO("desired state READY");
            clearArray(data_to_send,8);
            int data = 0x12;                                                   //12
            memcpy(data_to_send,&data,1*sizeof(uint8_t));                   //Fill data to by send to array of size 8
            memcpy(&frame.data, data_to_send,sizeof(data_to_send));         //Create can message (copy array of size 8 to can structure)
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame.data[i]);
            //can->writeCAN(&frame);                                                  //Write CAN message to CAN bus
            break;
        }
        case 3: //ON
        {
            ROS_INFO("desired state ON");
            clearArray(data_to_send,8);
            int data = 0x14;                                                //14
            memcpy(data_to_send,&data,1*sizeof(uint8_t));                   //Fill data to by send to array of size 8
            memcpy(&frame.data, data_to_send,sizeof(data_to_send));         //Create can message (copy array of size 8 to can structure)
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame.data[i]);
            //can->writeCAN(&frame);                                                  //Write CAN message to CAN bus
            break;
        }
        case 4: //ERROR
        {
            ROS_INFO("desired state ERROR");
            clearArray(data_to_send,8);
            int data = 0x1f;                                                //1f
            memcpy(data_to_send,&data,1*sizeof(uint8_t));                   //Fill data to by send to array of size 8
            memcpy(&frame.data, data_to_send,sizeof(data_to_send));         //Create can message (copy array of size 8 to can structure)
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame.data[i]);
            //can->writeCAN(&frame);                                                  //Write CAN message to CAN bus
            break;
        }
        default:
        {
            ROS_ERROR("Invalid number");
            clearArray(data_to_send,8);
            int data = 0x12;                                                //12 -> go back to ready
            memcpy(data_to_send,&data,1*sizeof(uint8_t));                   //Fill data to by send to array of size 8
            memcpy(&frame.data, data_to_send,sizeof(data_to_send));         //Create can message (copy array of size 8 to can structure)
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame.data[i]);
            //can->writeCAN(&frame);                                          //write CAN message to CAN bus
            sleep(1);

            clearArray(data_to_send,8);
            data = 0x10;                                                    //10 -> go back to stop
            memcpy(data_to_send,&data,1*sizeof(uint8_t));                   //Fill data to by send to array of size 8
            memcpy(&frame.data, data_to_send,sizeof(data_to_send));         //Create can message (copy array of size 8 to can structure)
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame.data[i]);
            //can->writeCAN(&frame);                                                  //Write CAN message to CAN bus
            break;
        }
    }

}   //Just uncomment can->writeCAN

void decodeCANmsg(can_frame *frame){

    switch (frame->can_id){
        case 0x210:     //Status answer
        {
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame->data[i]);
            uint8_t data_from_can[8];
            clearArray(data_from_can,8);
            memcpy(data_from_can,frame->data,8*sizeof(uint8_t));

            int32_msg.data = 0;                                         //Send STATUS
            int32_msg.data = frame->data[1] << 4 | frame->data[0];      //Posibility 1 (Status msg)
            memcpy(&int32_msg.data,data_from_can,2*sizeof(uint8_t));    //Posibility 2 (Status msg)
            currentWorkingState_pub.publish(int32_msg);                       //Send status msg
            ROS_INFO("Sending STATUS msg dec=%d (hex=%x)",int32_msg.data,int32_msg.data);

            int32_msg.data = 0;                                         //Send ERROR
            int32_msg.data = frame->data[3] << 4 | frame->data[2];      //Posibility 1 (Error msg)
            memcpy(&int32_msg.data,data_from_can+2,2*sizeof(uint8_t));  //Posibility 2 (Error msg)
            currentError_pub.publish(int32_msg);
            ROS_INFO("Sending ERROR msg dec=%d (hex=%x)",int32_msg.data,int32_msg.data);
            break;
        }
        case 0x211:     //Position and Velocity answer
        {
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame->data[i]);
            uint8_t data_from_can[8];
            clearArray(data_from_can,8);
            memcpy(data_from_can,frame->data,8*sizeof(uint8_t));

            int32_msg.data = 0;                                         //Current Position
            memcpy(&int32_msg.data,data_from_can,2*sizeof(uint8_t));    //Posibility 2
            currentRotationInDeg_pub.publish(int32_msg);
            ROS_INFO("Sending current POSITION dec=%d (hex=%x) [inc]",int32_msg.data,int32_msg.data);

            int32_msg.data = 0;                                         //Current Difference to desired angle
            memcpy(&int32_msg.data,data_from_can+2,2*sizeof(uint8_t));  //Posibility 2
            ROS_INFO("Differece between current and desired angle dec=%d (hex=%x) [inc]",int32_msg.data,int32_msg.data);

            int32_msg.data = 0;                                         //Desired max velocity
            memcpy(&int32_msg.data,data_from_can+4,2*sizeof(uint8_t));  //Posibility 2
            //currentRotationInDeg_pub.publish(int32_msg);
            ROS_INFO("Desired max velocity dec=%d (hex=%x) [1/min]",int32_msg.data,int32_msg.data);

            int32_msg.data = 0;                                         //Current velocity
            memcpy(&int32_msg.data,data_from_can+6,2*sizeof(uint8_t));  //Posibility 2
            currentRotationInDeg_pub.publish(int32_msg);
            ROS_INFO("Desired max velocity dec=%d (hex=%x) [1/min]",int32_msg.data,int32_msg.data);
            break;
        }
        case 0x212:     //Basic Position and Revolution answer
        {
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame->data[i]);
            uint8_t data_from_can[8];
            clearArray(data_from_can,8);
            memcpy(data_from_can,frame->data,8*sizeof(uint8_t));

            int actualBasicPosition;                                    //Actual Basic Position
            memcpy(&actualBasicPosition, data_from_can, 4*sizeof(uint8_t));
            ROS_INFO("Actual Basic Position is %d",actualBasicPosition);

            int revolutionCounter;                                      //Revolution counter (not implemented in CAN)
            memcpy(&revolutionCounter,data_from_can+4,4*sizeof(uint8_t));
            ROS_INFO("Revolution counter is %d  [rev]",actualBasicPosition);
            break;
        }
        case 0x21e:
        {
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame->data[i]);
            uint8_t data_from_can[8];
            clearArray(data_from_can,8);
            memcpy(data_from_can,frame->data,8*sizeof(uint8_t));

            memcpy(&status_msg.power_stage_temperature, data_from_can, 2*sizeof(uint8_t));
            memcpy(&status_msg.microprocessor_temperature, data_from_can+2, 2*sizeof(uint8_t));
            memcpy(&status_msg.chopper_temperature, data_from_can+4, 2*sizeof(uint8_t));
            memcpy(&status_msg.filtered_motor_current, data_from_can+6, 2*sizeof(uint8_t));
            tempAndCurrentStatus_pub.publish(status_msg);
            break;
        }
        default:
        {
            ROS_ERROR("Not defined ID of message ... please check documentation for %x",frame->can_id);
            break;
        }
    }

}

void requestTemperature(){

    if (i == 20){
        uint8_t data[8];
        clearArray(data,8);
        can_frame frame;                //Create CAN frame
        frame.can_id = 0x20e;           //Define header of CAN message
        frame.can_dlc = 0;              //Define lenght of CAN message
        memcpy(&frame.data, data, sizeof(data));    //Copy data to CAN frame

        for (int i = 0; i < 8; i++) ROS_INFO("%X", frame.data[i]);
        //can->writeCAN(&frame);        //Send message via CAN
    }
    i++;

}

bool changeDirection(bool desiredDirection){

    /** Direction 0 - clockwise, 1 - anticlockwise **/
    static bool lastDirection = false;

    if (desiredDirection != lastDirection){
        ROS_INFO("Changing direction");

        lastDirection = desiredDirection;
        int direction = (int)desiredDirection;
        int angle = 360, cycleTime = 5000, stopTime = 5000;         //Angle????
        uint8_t data[8];
        clearArray(data,8);

        can_frame frame;                //Create CAN frame
        frame.can_id = 0x226;           //Define header of CAN message
        frame.can_dlc = 8;              //Define lenght of CAN message
        memcpy(data,&angle,2*sizeof(uint8_t));
        memcpy(data+2,&cycleTime,2*sizeof(uint8_t));
        memcpy(data+4,&stopTime,2*sizeof(uint8_t));
        memcpy(data+6,&direction,2*sizeof(uint8_t));

        for (int i=0;i<8;i++) ROS_INFO("%x",data[i]);
        return true;
    }else{
        return false;
    }

}   /** Zistit ako len jednoducho otocit smer otacania -> ake parametre pouzit **/

//************************************** Callbacks ********************************************//
void rotateCommandCallback(const scara_v2_moveit_api::pose_velocity_direction desiredPositionVelocityDirection){


    //Direction 0x226!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int rot = desiredPositionVelocityDirection.rotation;
    int vel = desiredPositionVelocityDirection.velocity;
    bool dir = desiredPositionVelocityDirection.direction;
    uint8_t data[8];
    if (changeDirection(dir)){
        ROS_INFO("sleep for 3 seconds");
        sleep(3);
    }

    memcpy(data,&rot,2*sizeof(uint8_t));
    memcpy(data+2,&vel,2*sizeof(uint8_t));

    can_frame frame;                //Create CAN frame
    frame.can_id = 0x201;           //Define header of CAN message
    frame.can_dlc = 4;              //Define lenght of CAN message
    memcpy(&frame.data, data, sizeof(data));    //Copy data to CAN frame

    //for (int i = 0; i < 8; i++) ROS_INFO("%X", frame.data[i]);
    //can->writeCAN(&frame);        //Send message via CAN

}   /**************    Direction to solve (225) !!!!   ****************/

void workingStateCommandCallback(const std_msgs::Int32 mode){

    ROS_INFO("workingStateCommandCallback : desired mode=%d",mode.data);
    sendDesiredWorkingState(mode.data);

}

#endif //PROJECT_ROTARY_TABLE_MENU_H
