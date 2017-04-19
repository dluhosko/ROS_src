cmake_minimum_required(VERSION 2.8.3)
project(training)

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs genmsg
)

generate_messages(DEPENDENCIES std_msgs)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(train src/train.cpp)
target_link_libraries(train ${catkin_LIBRARIES})