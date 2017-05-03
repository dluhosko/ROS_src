cmake_minimum_required(VERSION 2.8.3)
project(scara_v2_moveit_api)

add_compile_options(-std=c++11)

find_package(Eigen3 REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  moveit_core
  moveit_ros_planning_interface
  roscpp
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


add_executable(move_group_interface1 ../scara_v2_moveit_api/src/move_group_interface1.cpp)
target_link_libraries(move_group_interface1 ${catkin_LIBRARIES})