# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "a5_help: 0 messages, 1 services")

set(MSG_I_FLAGS "-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(a5_help_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv" NAME_WE)
add_custom_target(_a5_help_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "a5_help" "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(a5_help
  "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/a5_help
)

### Generating Module File
_generate_module_cpp(a5_help
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/a5_help
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(a5_help_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(a5_help_generate_messages a5_help_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv" NAME_WE)
add_dependencies(a5_help_generate_messages_cpp _a5_help_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(a5_help_gencpp)
add_dependencies(a5_help_gencpp a5_help_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS a5_help_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(a5_help
  "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/a5_help
)

### Generating Module File
_generate_module_eus(a5_help
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/a5_help
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(a5_help_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(a5_help_generate_messages a5_help_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv" NAME_WE)
add_dependencies(a5_help_generate_messages_eus _a5_help_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(a5_help_geneus)
add_dependencies(a5_help_geneus a5_help_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS a5_help_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(a5_help
  "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/a5_help
)

### Generating Module File
_generate_module_lisp(a5_help
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/a5_help
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(a5_help_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(a5_help_generate_messages a5_help_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv" NAME_WE)
add_dependencies(a5_help_generate_messages_lisp _a5_help_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(a5_help_genlisp)
add_dependencies(a5_help_genlisp a5_help_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS a5_help_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(a5_help
  "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/a5_help
)

### Generating Module File
_generate_module_nodejs(a5_help
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/a5_help
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(a5_help_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(a5_help_generate_messages a5_help_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv" NAME_WE)
add_dependencies(a5_help_generate_messages_nodejs _a5_help_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(a5_help_gennodejs)
add_dependencies(a5_help_gennodejs a5_help_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS a5_help_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(a5_help
  "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/a5_help
)

### Generating Module File
_generate_module_py(a5_help
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/a5_help
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(a5_help_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(a5_help_generate_messages a5_help_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/mnt/c/Users/Solo/Documents/Git/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv" NAME_WE)
add_dependencies(a5_help_generate_messages_py _a5_help_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(a5_help_genpy)
add_dependencies(a5_help_genpy a5_help_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS a5_help_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/a5_help)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/a5_help
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(a5_help_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(a5_help_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/a5_help)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/a5_help
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(a5_help_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(a5_help_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/a5_help)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/a5_help
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(a5_help_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(a5_help_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/a5_help)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/a5_help
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(a5_help_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(a5_help_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/a5_help)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/a5_help\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/a5_help
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(a5_help_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(a5_help_generate_messages_py std_msgs_generate_messages_py)
endif()
