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
//pridat include z CAN kniznice

const int SIZE_OF_1B_MESSAGE = 3, SIZE_OF_2B_MESSAGE=5, SIZE_OF_4B_MESSAGE = 9;
char *hexNum, *modifHexNum;
char char_1B[SIZE_OF_1B_MESSAGE];
char char_2B_position[SIZE_OF_2B_MESSAGE], char_2B_velocity[SIZE_OF_2B_MESSAGE], char_2B_position_modif[SIZE_OF_2B_MESSAGE], char_2B_velocity_modif[SIZE_OF_2B_MESSAGE];
uint8_t uint8_4B_message[SIZE_OF_4B_MESSAGE-1], uint8_1B_message[SIZE_OF_1B_MESSAGE-1];


std_msgs::Int32 int32_msg;
scara_v2_moveit_api::pose_velocity_direction posVelDir_msg;

ros::Publisher currentRotationInDeg_pub, currentWorkingState_pub;
ros::Subscriber rotateCommand_sub, workingStateCommand_sub;


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

void sendDesiredWorkingState(int inputNumber){

    switch (inputNumber){
        case 1: //OFF
        {
            ROS_INFO("desired state OFF");
            char word[] = "10";
            char2uint8_t(word,word,uint8_1B_message,SIZE_OF_1B_MESSAGE);
            for (int i=0;i<SIZE_OF_1B_MESSAGE-1;i++){
                ROS_WARN("[%d] char=%c => uint8_t=%d",i,word[i],uint8_1B_message[i]);
            }
            /************************** create CAN msg **********************************/



            break;
        }
        case 2: //READY
        {
            ROS_INFO("desired state READY");
            char word[] = "12";
            char2uint8_t(word,word,uint8_1B_message,SIZE_OF_1B_MESSAGE);
            for (int i=0;i<SIZE_OF_1B_MESSAGE-1;i++){
                ROS_WARN("[%d] char=%c => uint8_t=%d",i,word[i],uint8_1B_message[i]);
            }
            /************************** create CAN msg **********************************/




            break;
        }
        case 3: //ON
        {
            ROS_INFO("desired state ON");
            char word[] = "14";
            char2uint8_t(word,word,uint8_1B_message,SIZE_OF_1B_MESSAGE);
            for (int i=0;i<SIZE_OF_1B_MESSAGE-1;i++){
                ROS_WARN("[%d] char=%c => uint8_t=%d",i,word[i],uint8_1B_message[i]);
            }
            /************************** create CAN msg **********************************/




            break;
        }
        case 4: //ERROR
        {
            ROS_INFO("desired state ERROR");
            char word[] = "1f";
            char2uint8_t(word,word,uint8_1B_message,SIZE_OF_1B_MESSAGE);
            for (int i=0;i<SIZE_OF_1B_MESSAGE-1;i++){
                ROS_WARN("[%d] char=%c => uint8_t=%d",i,word[i],uint8_1B_message[i]);
            }
            /************************** create CAN msg **********************************/



            break;
        }
        default:
        {
            ROS_ERROR("Invalid number");
            char word[] = "12";
            char2uint8_t(word,word,uint8_1B_message,SIZE_OF_1B_MESSAGE);
            for (int i=0;i<SIZE_OF_1B_MESSAGE-1;i++){
                ROS_WARN("[%d] char=%c => uint8_t=%d",i,word[i],uint8_1B_message[i]);
            }
            /************************** create CAN msg **********************************/




            break;
        }
    }

}   /**********************Create CAN msg ***********************************/

//************************************** Callbacks ********************************************/
void rotateCommandCallback(const scara_v2_moveit_api::pose_velocity_direction desiredPositionVelocityDirection){

//    ROS_INFO("rotateCommandCallback : desired rotation=%d , desired velocity=%d desired direction =%s",desiredPositionVelocityDirection.rotation,
//             desiredPositionVelocityDirection.velocity, desiredPositionVelocityDirection.direction?"Right":"Left");
    posVelDir_msg = desiredPositionVelocityDirection;

    sprintf(char_2B_position,"%x", desiredPositionVelocityDirection.rotation);
    sprintf(char_2B_velocity,"%x", desiredPositionVelocityDirection.velocity);
    /************************** Dorobit smer otacania **************************/
    ROS_INFO("Rotation DEC=%d , rotation HEX=%s , Velocity DEC =%d , velocity HEX=%s",
             desiredPositionVelocityDirection.rotation,char_2B_position,desiredPositionVelocityDirection.velocity,char_2B_velocity);
    //Fill empty Bytes in HEX numbers

    fillEmptyBytesInCANmsg(char_2B_position,char_2B_position_modif,SIZE_OF_2B_MESSAGE);
    fillEmptyBytesInCANmsg(char_2B_velocity,char_2B_velocity_modif,SIZE_OF_2B_MESSAGE);
    ROS_INFO("NOT FILLED HEX numbers: position=%s velocity=%s FILLED HEX numbers: position=%s velocity=%s",
             char_2B_position,char_2B_velocity,char_2B_position_modif,char_2B_velocity_modif);
    //Convert HEX number to specific CAN format
    ROS_INFO("Standard CAN : %s(%d) %s(%d)",char_2B_position_modif,std::strlen(char_2B_position_modif),char_2B_velocity_modif,std::strlen(char_2B_velocity_modif));
    convertCANmsg(char_2B_position_modif,SIZE_OF_2B_MESSAGE);
    convertCANmsg(char_2B_velocity_modif,SIZE_OF_2B_MESSAGE);
    ROS_INFO("SENSO CAN : %s(%d) %s(%d)",char_2B_position_modif,std::strlen(char_2B_position_modif),char_2B_velocity_modif,std::strlen(char_2B_velocity_modif));

    char2uint8_t(char_2B_position_modif,char_2B_velocity_modif,uint8_4B_message,SIZE_OF_4B_MESSAGE);
    for (int i=0;i<SIZE_OF_4B_MESSAGE-1;i++){
        ROS_WARN("[%d] %d",i,uint8_4B_message[i]);
    }

    /************************** create CAN msg **********************************/




}   /************************** create CAN msg **********************************/

void workingStateCommandCallback(const std_msgs::Int32 mode){

    ROS_INFO("workingStateCommandCallback : desired mode=%d",mode.data);
    sendDesiredWorkingState(mode.data);

}






#endif //PROJECT_ROTARY_TABLE_MENU_H
