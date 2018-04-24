//
// Created by viktor on 24/04/18.
//

#ifndef PROJECT_MULTIPLE_CYLINDER_PUBLISHER_SCARA_V3_H
#define PROJECT_MULTIPLE_CYLINDER_PUBLISHER_SCARA_V3_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometric_shapes/solid_primitive_dims.h>
#include <visualization_msgs/Marker.h>



std::string pick_frame (int number){

    if (number == 1){
        return "pickHole1";
    }else if (number == 2){
        return "pickHole2";
    }else if (number == 3){
        return "pickHole3";
    }else if (number == 4){
        return "pickHole4";
    }else if (number == 5){
        return "pickHole5";
    }else if (number == 6){
        return "pickHole6";
    }else if (number == 7){
        return "pickHole7";
    }else if (number == 8){
        return "pickHole8";
    }else{
        return "No valid index of cube!";
    }

}
std::string place_frame(int number){

    if (number == 1){
        return "placeHole1";
    }else if (number == 2){
        return "placeHole2";
    }else if (number == 3){
        return "placeHole3";
    }else if (number == 4){
        return "placeHole4";
    }else if (number == 5){
        return "placeHole5";
    }else if (number == 6){
        return "placeHole6";
    }else if (number == 7){
        return "placeHole7";
    }else if (number == 8){
        return "placeHole8";
    }else{
        return "No valid index of cube!";
    }
}

#endif //PROJECT_MULTIPLE_CYLINDER_PUBLISHER_SCARA_V3_H
