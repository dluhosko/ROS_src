# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "scara_msgs: 4 messages, 0 services")

set(MSG_I_FLAGS "-Iscara_msgs:/home/viktor/catkin_ws/src/scara_msgs/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genjava REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(scara_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg" NAME_WE)
add_custom_target(_scara_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "scara_msgs" "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg" ""
)

get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg" NAME_WE)
add_custom_target(_scara_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "scara_msgs" "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg" ""
)

get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg" NAME_WE)
add_custom_target(_scara_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "scara_msgs" "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg" ""
)

get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg" NAME_WE)
add_custom_target(_scara_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "scara_msgs" "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg" ""
)

#
#  langs = gencpp;geneus;genjava;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_msgs
)
_generate_msg_cpp(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_msgs
)
_generate_msg_cpp(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_msgs
)
_generate_msg_cpp(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(scara_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(scara_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(scara_msgs_generate_messages scara_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_cpp _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_cpp _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_cpp _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_cpp _scara_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_msgs_gencpp)
add_dependencies(scara_msgs_gencpp scara_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_msgs
)
_generate_msg_eus(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_msgs
)
_generate_msg_eus(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_msgs
)
_generate_msg_eus(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(scara_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(scara_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(scara_msgs_generate_messages scara_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_eus _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_eus _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_eus _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_eus _scara_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_msgs_geneus)
add_dependencies(scara_msgs_geneus scara_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_msgs_generate_messages_eus)

### Section generating for lang: genjava
### Generating Messages
_generate_msg_java(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/scara_msgs
)
_generate_msg_java(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/scara_msgs
)
_generate_msg_java(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/scara_msgs
)
_generate_msg_java(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/scara_msgs
)

### Generating Services

### Generating Module File
_generate_module_java(scara_msgs
  ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/scara_msgs
  "${ALL_GEN_OUTPUT_FILES_java}"
)

add_custom_target(scara_msgs_generate_messages_java
  DEPENDS ${ALL_GEN_OUTPUT_FILES_java}
)
add_dependencies(scara_msgs_generate_messages scara_msgs_generate_messages_java)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_java _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_java _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_java _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_java _scara_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_msgs_genjava)
add_dependencies(scara_msgs_genjava scara_msgs_generate_messages_java)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_msgs_generate_messages_java)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_msgs
)
_generate_msg_lisp(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_msgs
)
_generate_msg_lisp(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_msgs
)
_generate_msg_lisp(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(scara_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(scara_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(scara_msgs_generate_messages scara_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_lisp _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_lisp _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_lisp _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_lisp _scara_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_msgs_genlisp)
add_dependencies(scara_msgs_genlisp scara_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_msgs
)
_generate_msg_nodejs(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_msgs
)
_generate_msg_nodejs(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_msgs
)
_generate_msg_nodejs(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(scara_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(scara_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(scara_msgs_generate_messages scara_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_nodejs _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_nodejs _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_nodejs _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_nodejs _scara_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_msgs_gennodejs)
add_dependencies(scara_msgs_gennodejs scara_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_msgs
)
_generate_msg_py(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_msgs
)
_generate_msg_py(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_msgs
)
_generate_msg_py(scara_msgs
  "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(scara_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(scara_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(scara_msgs_generate_messages scara_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/robot_info.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_py _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_velocity_direction.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_py _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/pose_and_gripperState.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_py _scara_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/viktor/catkin_ws/src/scara_msgs/msg/status_rt.msg" NAME_WE)
add_dependencies(scara_msgs_generate_messages_py _scara_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scara_msgs_genpy)
add_dependencies(scara_msgs_genpy scara_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scara_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scara_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(scara_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scara_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(scara_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genjava_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/scara_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/scara_msgs
    DESTINATION ${genjava_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_java)
  add_dependencies(scara_msgs_generate_messages_java std_msgs_generate_messages_java)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scara_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(scara_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scara_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(scara_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scara_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(scara_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
