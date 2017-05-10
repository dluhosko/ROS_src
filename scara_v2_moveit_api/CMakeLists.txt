cmake_minimum_required(VERSION 2.8.3)
project(scara_v2_moveit_api)

add_compile_options(-std=c++11)

#find_package(Eigen3 REQUIRED)
find_package(PkgConfig)
pkg_search_module(Eigen3 REQUIRED eigen3)

find_package(catkin REQUIRED COMPONENTS
        moveit_core
        moveit_ros_planning_interface
        moveit_ros_planning
        roscpp
        std_msgs
        genmsg
        message_generation
)
find_package(Boost REQUIRED system filesystem date_time thread)




add_message_files(
        FILES
        pose_and_gripperState.msg
)

generate_messages(
        DEPENDENCIES
        std_msgs
)

catkin_package(
        CATKIN_DEPENDS
        moveit_core
        moveit_ros_planning_interface
        message_runtime
        std_msgs
)





include_directories(SYSTEM ${Boost_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIRS})
include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})


add_executable(move_group_interface1 ../scara_v2_moveit_api/src/move_group_interface1.cpp)
target_link_libraries(move_group_interface1 ${catkin_LIBRARIES})

add_executable(move_group_interface2 ../scara_v2_moveit_api/src/move_group_interface2.cpp)
target_link_libraries(move_group_interface2 ${catkin_LIBRARIES})

add_executable(move_group_interface3_PICKandPLACE ../scara_v2_moveit_api/src/move_group_interface3_PICKandPLACE.cpp)
target_link_libraries(move_group_interface3_PICKandPLACE ${catkin_LIBRARIES})
add_dependencies(move_group_interface3_PICKandPLACE beginner_tutorials_generate_messages_cpp)


add_executable(cube_publisher ../scara_v2_moveit_api/src/cube_publisher.cpp)
target_link_libraries(cube_publisher ${catkin_LIBRARIES})
add_dependencies(cube_publisher beginner_tutorials_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener beginner_tutorials_generate_messages_cpp)
