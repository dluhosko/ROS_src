//
// Created by viktor on 17/10/17.
//

#ifndef PROJECT_ROTARY_TABLE_MENU_H
#define PROJECT_ROTARY_TABLE_MENU_H

#include <ros/ros.h>



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

void fillEmptyBytesInCANmsg(char* inputCANmsg,char* outputCANmsg, int size_of_msg){

    ROS_INFO("input size %d , output size %d and entered size %d",std::strlen(inputCANmsg),std::strlen(outputCANmsg),size_of_msg);
    size_of_msg++;

    for (int i=0;i<size_of_msg+1;i++){
        if (i < (size_of_msg-1) -std::strlen(inputCANmsg)){
            outputCANmsg[i] = '0';
        }else{
            outputCANmsg[i] = inputCANmsg[i - ((size_of_msg-1) -std::strlen(inputCANmsg))];
        }
        //getchar();

    }
    outputCANmsg[size_of_msg] = '\0';

}

void convertCANmsg(char* inputCANmsg, int size_of_msg){

    char help1,help2;
    size_of_msg++;
    for (int i=0;i<std::strlen(inputCANmsg)-1-2;i+=4){
        help1= inputCANmsg[i];
        help2= inputCANmsg[i+1];
        inputCANmsg[i] = inputCANmsg[i+2];
        inputCANmsg[i+1] = inputCANmsg[i+3];
        inputCANmsg[i+2] = help1;
        inputCANmsg[i+3] = help2;
    }
    inputCANmsg[size_of_msg] = '\0';


}






#endif //PROJECT_ROTARY_TABLE_MENU_H
