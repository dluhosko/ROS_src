cmake_minimum_required(VERSION 2.8.3)
project(scara_v2_with_gripper_moveit_config)

add_compile_options(-std=c++11)
find_package(Eigen3 REQUIRED)
# Eigen 3.2 (Wily) only provides EIGEN3_INCLUDE_DIR, not EIGEN3_INCLUDE_DIRSif(NOT EIGEN3_INCLUDE_DIRS)  set(EIGEN3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})endif()

find_package(catkin REQUIRED
        COMPONENTS
        roscpp
        moveit_core
        moveit_ros_planning_interface
        )

find_package(Boost REQUIRED system filesystem date_time thread)

generate_messages(DEPENDENCIES std_msgs)

catkin_package(
        CATKIN_DEPENDS
        moveit_core
        moveit_ros_planning_interface
)

include_directories(SYSTEM ${Boost_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIRS})
include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})




