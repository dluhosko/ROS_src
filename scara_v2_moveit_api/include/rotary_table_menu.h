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
#include <can_interface/can_interface.h>
//pridat include z CAN kniznice

std_msgs::Int32 int32_msg;
scara_v2_moveit_api::pose_velocity_direction posVelDir_msg;

ros::Publisher currentRotationInDeg_pub, currentStatus_pub, currentError_pub;
ros::Subscriber rotateCommand_sub, workingStateCommand_sub;
Can_interface *can;

int hex2dec(char hex_value[]){

    int length = std::strlen(hex_value);
    int power = 1;
    int dec_value = 0;

    for (int i=length-1;i>=0;i--){

        if (hex_value[i]>='0' && hex_value[i]<='9'){
            dec_value += (hex_value[i] - 48) * power;
            power = power * 16;
        }else if (hex_value[i]>='A' && hex_value[i]<='F'){
            dec_value += (hex_value[i] - 55) * power;
            power = power * 16;
        }else if (hex_value[i]>='a' && hex_value[i]<='f'){
            dec_value += (hex_value[i] - 87) * power;
            power = power * 16;
        }
        ROS_INFO("hex value =%c dec value=%d , power = %d",hex_value[i],dec_value,power);
        sleep(2);
    }

    return dec_value;
}

void char2uint8_t(char* input1, char* input2, uint8_t* output,int size_of_output){

    for (int i=0;i<size_of_output-1;i++){
        ROS_INFO_STREAM(i);
        ROS_INFO_STREAM(strlen(input1));
        if (i < 4){
            output[i] = (uint8_t)(input1[i]);
        }else{
            output[i] = (uint8_t)(input2[i-4]);
        }
    }

}

void fillEmptyBytesInCANmsg(char* inputCANmsg,char* outputCANmsg, int size_of_msg){

    ROS_INFO("input size %d , output size %d and entered size %d",std::strlen(inputCANmsg),std::strlen(outputCANmsg),size_of_msg);

    for (int i=0;i<size_of_msg-1;i++){
        if (i < (size_of_msg-1) -std::strlen(inputCANmsg)){
            outputCANmsg[i] = '0';
        }else{
            outputCANmsg[i] = inputCANmsg[i - ((size_of_msg-1) -std::strlen(inputCANmsg))];
        }
    }
    outputCANmsg[size_of_msg] = '\0';

}

void convertCANmsg(char* inputCANmsg, int size_of_msg){

    char help1,help2;
    for (int i=0;i<std::strlen(inputCANmsg)-1-2;i+=4){
        help1= inputCANmsg[i];
        help2= inputCANmsg[i+1];
        inputCANmsg[i] = inputCANmsg[i+2];
        inputCANmsg[i+1] = inputCANmsg[i+3];
        inputCANmsg[i+2] = help1;
        inputCANmsg[i+3] = help2;
    }

}

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

}

void decodeCANmsg(can_frame *frame){

    switch (frame->can_id){
        case 0x210:
        {
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame->data[i]);
            //uint8_t data_from_can[4];
            //clearArray(data_from_can,4);
            //memcpy(data_from_can,frame->data, 4*sizeof(uint8_t));
            int32_msg.data = 0;
            int32_msg.data = frame->data[1] << 4 | frame->data[0];  //Status msg
            currentStatus_pub.publish(int32_msg);                 //Send status msg
            ROS_INFO("Sending STATUS msg dec=%d (hex=%x)",int32_msg.data,int32_msg.data);

            int32_msg.data = 0;
            int32_msg.data = frame->data[3] << 4 | frame->data[2];  //Status msg
            currentError_pub





            break;
        }
        case 0x211:
        {
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame->data[i]);
            uint8_t data_from_can[8];
            clearArray(data_from_can,8);
            for (int i=0;i<8;i+=2){
                data_from_can[i]= frame->data[i+1];
                data_from_can[i+1]= frame->data[i];
            }

            break;
        }
        case 0x212:
        {
            for (int i = 0; i < 8; i++) ROS_INFO("%X", frame->data[i]);
            uint8_t data_from_can[8];
            clearArray(data_from_can,8);
            for (int i=0;i<8;i+=2){
                data_from_can[i]= frame->data[i+1];
                data_from_can[i+1]= frame->data[i];
            }

            break;
        }
        default:{
            break;
        }
    }

}

//************************************** Callbacks ********************************************/
void rotateCommandCallback(const scara_v2_moveit_api::pose_velocity_direction desiredPositionVelocityDirection){


    //Direction 0x226!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int rot = desiredPositionVelocityDirection.rotation;
    int vel = desiredPositionVelocityDirection.velocity;
    bool dir = desiredPositionVelocityDirection.direction;
    uint8_t data[8];

    memcpy(data,&rot,2*sizeof(uint8_t));
    memcpy(data+2,&vel,2*sizeof(uint8_t));

    can_frame frame;                //Create CAN frame
    frame.can_id = 0x201;           //Define header of CAN message
    frame.can_dlc = 4;              //Define lenght of CAN message
    memcpy(&frame.data, data, sizeof(data));    //Copy data to CAN frame

    for (int i = 0; i < 8; i++) ROS_INFO("%X", frame.data[i]);
    //can->writeCAN(&frame);        //Send message via CAN

}   /**************Direction****************/

void workingStateCommandCallback(const std_msgs::Int32 mode){

    ROS_INFO("workingStateCommandCallback : desired mode=%d",mode.data);
    sendDesiredWorkingState(mode.data);

}






#endif //PROJECT_ROTARY_TABLE_MENU_H
