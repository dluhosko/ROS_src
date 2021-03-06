# Install script for directory: /home/viktor/catkin_ws/src/gazebo_scara_and_rt/scara_v2_full_description

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/viktor/catkin_ws/src/cmake-build-debug/gazebo_scara_and_rt/scara_v2_full_description/catkin_generated/installspace/scara_v2_full_description.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_full_description/cmake" TYPE FILE FILES
    "/home/viktor/catkin_ws/src/cmake-build-debug/gazebo_scara_and_rt/scara_v2_full_description/catkin_generated/installspace/scara_v2_full_descriptionConfig.cmake"
    "/home/viktor/catkin_ws/src/cmake-build-debug/gazebo_scara_and_rt/scara_v2_full_description/catkin_generated/installspace/scara_v2_full_descriptionConfig-version.cmake"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_full_description" TYPE FILE FILES "/home/viktor/catkin_ws/src/gazebo_scara_and_rt/scara_v2_full_description/package.xml")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_full_description" TYPE DIRECTORY FILES "/home/viktor/catkin_ws/src/gazebo_scara_and_rt/scara_v2_full_description/launch")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_full_description" TYPE DIRECTORY FILES "/home/viktor/catkin_ws/src/gazebo_scara_and_rt/scara_v2_full_description/meshes")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_full_description" TYPE DIRECTORY FILES "/home/viktor/catkin_ws/src/gazebo_scara_and_rt/scara_v2_full_description/urdf")
endif()

