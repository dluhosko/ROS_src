# Install script for directory: /home/viktor/catkin_ws/src/scara_v2_moveit_api

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_moveit_api/msg" TYPE FILE FILES
    "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg"
    "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_velocity_direction.msg"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_moveit_api/srv" TYPE FILE FILES "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_moveit_api/cmake" TYPE FILE FILES "/home/viktor/catkin_ws/src/cmake-build-debug/scara_v2_moveit_api/catkin_generated/installspace/scara_v2_moveit_api-msg-paths.cmake")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/viktor/catkin_ws/src/cmake-build-debug/devel/include/scara_v2_moveit_api")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/viktor/catkin_ws/src/cmake-build-debug/devel/share/roseus/ros/scara_v2_moveit_api")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/viktor/catkin_ws/src/cmake-build-debug/devel/share/common-lisp/ros/scara_v2_moveit_api")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/viktor/catkin_ws/src/cmake-build-debug/devel/share/gennodejs/ros/scara_v2_moveit_api")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/viktor/catkin_ws/src/cmake-build-debug/devel/lib/python2.7/dist-packages/scara_v2_moveit_api")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/viktor/catkin_ws/src/cmake-build-debug/devel/lib/python2.7/dist-packages/scara_v2_moveit_api")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/viktor/catkin_ws/src/cmake-build-debug/scara_v2_moveit_api/catkin_generated/installspace/scara_v2_moveit_api.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_moveit_api/cmake" TYPE FILE FILES "/home/viktor/catkin_ws/src/cmake-build-debug/scara_v2_moveit_api/catkin_generated/installspace/scara_v2_moveit_api-msg-extras.cmake")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_moveit_api/cmake" TYPE FILE FILES
    "/home/viktor/catkin_ws/src/cmake-build-debug/scara_v2_moveit_api/catkin_generated/installspace/scara_v2_moveit_apiConfig.cmake"
    "/home/viktor/catkin_ws/src/cmake-build-debug/scara_v2_moveit_api/catkin_generated/installspace/scara_v2_moveit_apiConfig-version.cmake"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/scara_v2_moveit_api" TYPE FILE FILES "/home/viktor/catkin_ws/src/scara_v2_moveit_api/package.xml")
endif()

