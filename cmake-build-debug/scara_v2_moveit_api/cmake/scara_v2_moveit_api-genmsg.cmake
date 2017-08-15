# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "scara_v2_moveit_api: 1 messages, 1 services")

set(MSG_I_FLAGS "-Iscara_v2_moveit_api:/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg;-Iscara_msgs:/home/viktor/catkin_ws/src/scara_msgs/msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(scara_v2_moveit_api_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg" NAME_WE)
add_custom_target(_scara_v2_moveit_api_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "scara_v2_moveit_api" "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg" ""
)

get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv" NAME_WE)
add_custom_target(_scara_v2_moveit_api_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "scara_v2_moveit_api" "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(scara_v2_moveit_api
  "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_v2_moveit_api
)

### Generating Services
_generate_srv_cpp(scara_v2_moveit_api
  "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_v2_moveit_api
)

### Generating Module File
_generate_module_cpp(scara_v2_moveit_api
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_v2_moveit_api
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(scara_v2_moveit_api_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(scara_v2_moveit_api_generate_messages scara_v2_moveit_api_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_v2_moveit_api_generate_messages_cpp _scara_v2_moveit_api_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv" NAME_WE)
add_dependencies(scara_v2_moveit_api_generate_messages_cpp _scara_v2_moveit_api_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_v2_moveit_api_gencpp)
add_dependencies(scara_v2_moveit_api_gencpp scara_v2_moveit_api_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_v2_moveit_api_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(scara_v2_moveit_api
  "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_v2_moveit_api
)

### Generating Services
_generate_srv_eus(scara_v2_moveit_api
  "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_v2_moveit_api
)

### Generating Module File
_generate_module_eus(scara_v2_moveit_api
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_v2_moveit_api
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(scara_v2_moveit_api_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(scara_v2_moveit_api_generate_messages scara_v2_moveit_api_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_v2_moveit_api_generate_messages_eus _scara_v2_moveit_api_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv" NAME_WE)
add_dependencies(scara_v2_moveit_api_generate_messages_eus _scara_v2_moveit_api_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_v2_moveit_api_geneus)
add_dependencies(scara_v2_moveit_api_geneus scara_v2_moveit_api_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_v2_moveit_api_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(scara_v2_moveit_api
  "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_v2_moveit_api
)

### Generating Services
_generate_srv_lisp(scara_v2_moveit_api
  "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_v2_moveit_api
)

### Generating Module File
_generate_module_lisp(scara_v2_moveit_api
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_v2_moveit_api
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(scara_v2_moveit_api_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(scara_v2_moveit_api_generate_messages scara_v2_moveit_api_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_v2_moveit_api_generate_messages_lisp _scara_v2_moveit_api_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv" NAME_WE)
add_dependencies(scara_v2_moveit_api_generate_messages_lisp _scara_v2_moveit_api_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_v2_moveit_api_genlisp)
add_dependencies(scara_v2_moveit_api_genlisp scara_v2_moveit_api_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_v2_moveit_api_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(scara_v2_moveit_api
  "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_v2_moveit_api
)

### Generating Services
_generate_srv_nodejs(scara_v2_moveit_api
  "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_v2_moveit_api
)

### Generating Module File
_generate_module_nodejs(scara_v2_moveit_api
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_v2_moveit_api
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(scara_v2_moveit_api_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(scara_v2_moveit_api_generate_messages scara_v2_moveit_api_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_v2_moveit_api_generate_messages_nodejs _scara_v2_moveit_api_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv" NAME_WE)
add_dependencies(scara_v2_moveit_api_generate_messages_nodejs _scara_v2_moveit_api_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_v2_moveit_api_gennodejs)
add_dependencies(scara_v2_moveit_api_gennodejs scara_v2_moveit_api_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_v2_moveit_api_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(scara_v2_moveit_api
  "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_v2_moveit_api
)

### Generating Services
_generate_srv_py(scara_v2_moveit_api
  "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_v2_moveit_api
)

### Generating Module File
_generate_module_py(scara_v2_moveit_api
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_v2_moveit_api
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(scara_v2_moveit_api_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(scara_v2_moveit_api_generate_messages scara_v2_moveit_api_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_v2_moveit_api_generate_messages_py _scara_v2_moveit_api_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_v2_moveit_api/srv/SimpleService.srv" NAME_WE)
add_dependencies(scara_v2_moveit_api_generate_messages_py _scara_v2_moveit_api_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_v2_moveit_api_genpy)
add_dependencies(scara_v2_moveit_api_genpy scara_v2_moveit_api_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_v2_moveit_api_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_v2_moveit_api)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_v2_moveit_api
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(scara_v2_moveit_api_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(scara_v2_moveit_api_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET actionlib_msgs_generate_messages_cpp)
  add_dependencies(scara_v2_moveit_api_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
endif()
if(TARGET scara_msgs_generate_messages_cpp)
  add_dependencies(scara_v2_moveit_api_generate_messages_cpp scara_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_v2_moveit_api)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_v2_moveit_api
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(scara_v2_moveit_api_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(scara_v2_moveit_api_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET actionlib_msgs_generate_messages_eus)
  add_dependencies(scara_v2_moveit_api_generate_messages_eus actionlib_msgs_generate_messages_eus)
endif()
if(TARGET scara_msgs_generate_messages_eus)
  add_dependencies(scara_v2_moveit_api_generate_messages_eus scara_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_v2_moveit_api)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_v2_moveit_api
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(scara_v2_moveit_api_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(scara_v2_moveit_api_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET actionlib_msgs_generate_messages_lisp)
  add_dependencies(scara_v2_moveit_api_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
endif()
if(TARGET scara_msgs_generate_messages_lisp)
  add_dependencies(scara_v2_moveit_api_generate_messages_lisp scara_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_v2_moveit_api)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_v2_moveit_api
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(scara_v2_moveit_api_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(scara_v2_moveit_api_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET actionlib_msgs_generate_messages_nodejs)
  add_dependencies(scara_v2_moveit_api_generate_messages_nodejs actionlib_msgs_generate_messages_nodejs)
endif()
if(TARGET scara_msgs_generate_messages_nodejs)
  add_dependencies(scara_v2_moveit_api_generate_messages_nodejs scara_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_v2_moveit_api)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_v2_moveit_api\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_v2_moveit_api
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(scara_v2_moveit_api_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(scara_v2_moveit_api_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET actionlib_msgs_generate_messages_py)
  add_dependencies(scara_v2_moveit_api_generate_messages_py actionlib_msgs_generate_messages_py)
endif()
if(TARGET scara_msgs_generate_messages_py)
  add_dependencies(scara_v2_moveit_api_generate_messages_py scara_msgs_generate_messages_py)
endif()
