cmake_minimum_required(VERSION 2.8.3)
project(testbot_description)

find_package(catkin REQUIRED COMPONENTS
  urdf
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES testbot_description
#  CATKIN_DEPENDS urdf
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)






 add_executable(parser src/parser.cpp)
 target_link_libraries(parser ${catkin_LIBRARIES})
