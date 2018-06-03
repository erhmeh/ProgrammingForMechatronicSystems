# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "lama_msgs: 6 messages, 7 services")

set(MSG_I_FLAGS "-Ilama_msgs:/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(lama_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv" "geometry_msgs/Polygon:geometry_msgs/Point32:lama_msgs/PlaceProfile:std_msgs/Header"
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv" "lama_msgs/InterfaceInfo"
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg" ""
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv" "lama_msgs/Frontier:lama_msgs/Crossing:geometry_msgs/Point"
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv" "lama_msgs/LamaObject"
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg" ""
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv" "lama_msgs/LamaObject"
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg" "geometry_msgs/Point32:std_msgs/Header:geometry_msgs/Polygon"
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv" "geometry_msgs/Polygon:geometry_msgs/Point32:lama_msgs/PlaceProfile:std_msgs/Header"
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg" "geometry_msgs/Point"
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg" ""
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv" "lama_msgs/Frontier:lama_msgs/Crossing:geometry_msgs/Point"
)

get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg" NAME_WE)
add_custom_target(_lama_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lama_msgs" "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg" "geometry_msgs/Point:lama_msgs/Frontier"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_msg_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_msg_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_msg_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_msg_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_msg_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)

### Generating Services
_generate_srv_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_srv_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_srv_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_srv_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_srv_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_srv_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)
_generate_srv_cpp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
)

### Generating Module File
_generate_module_cpp(lama_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(lama_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(lama_msgs_generate_messages lama_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_cpp _lama_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lama_msgs_gencpp)
add_dependencies(lama_msgs_gencpp lama_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lama_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_msg_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_msg_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_msg_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_msg_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_msg_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)

### Generating Services
_generate_srv_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_srv_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_srv_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_srv_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_srv_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_srv_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)
_generate_srv_eus(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
)

### Generating Module File
_generate_module_eus(lama_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(lama_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(lama_msgs_generate_messages lama_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_eus _lama_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lama_msgs_geneus)
add_dependencies(lama_msgs_geneus lama_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lama_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_msg_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_msg_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_msg_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_msg_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_msg_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)

### Generating Services
_generate_srv_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_srv_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_srv_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_srv_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_srv_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_srv_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)
_generate_srv_lisp(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
)

### Generating Module File
_generate_module_lisp(lama_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(lama_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(lama_msgs_generate_messages lama_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_lisp _lama_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lama_msgs_genlisp)
add_dependencies(lama_msgs_genlisp lama_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lama_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_msg_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_msg_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_msg_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_msg_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_msg_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)

### Generating Services
_generate_srv_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_srv_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_srv_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_srv_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_srv_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_srv_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)
_generate_srv_nodejs(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
)

### Generating Module File
_generate_module_nodejs(lama_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(lama_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(lama_msgs_generate_messages lama_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_nodejs _lama_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lama_msgs_gennodejs)
add_dependencies(lama_msgs_gennodejs lama_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lama_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_msg_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_msg_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_msg_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_msg_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_msg_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)

### Generating Services
_generate_srv_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_srv_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_srv_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_srv_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_srv_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_srv_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)
_generate_srv_py(lama_msgs
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv"
  "${MSG_I_FLAGS}"
  "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg;/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
)

### Generating Module File
_generate_module_py(lama_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(lama_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(lama_msgs_generate_messages lama_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetPlaceProfile.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetInterfaceInfo.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/InterfaceInfo.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetCrossing.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetLamaObject.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/DescriptorLink.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetLamaObject.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/PlaceProfile.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/GetPlaceProfile.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Frontier.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/LamaObject.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/srv/SetCrossing.srv" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_support/lama_msgs/msg/Crossing.msg" NAME_WE)
add_dependencies(lama_msgs_generate_messages_py _lama_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lama_msgs_genpy)
add_dependencies(lama_msgs_genpy lama_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lama_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lama_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(lama_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lama_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(lama_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lama_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(lama_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lama_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(lama_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lama_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(lama_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
