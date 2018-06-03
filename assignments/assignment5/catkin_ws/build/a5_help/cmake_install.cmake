# Install script for directory: /home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/a5_help/srv" TYPE FILE FILES "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/srv/RequestGoal.srv")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/a5_help/cmake" TYPE FILE FILES "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/build/a5_help/catkin_generated/installspace/a5_help-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/devel/include/a5_help")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/devel/share/roseus/ros/a5_help")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/devel/share/common-lisp/ros/a5_help")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/devel/share/gennodejs/ros/a5_help")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/devel/lib/python2.7/dist-packages/a5_help")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/devel/lib/python2.7/dist-packages/a5_help")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/build/a5_help/catkin_generated/installspace/a5_help.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/a5_help/cmake" TYPE FILE FILES "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/build/a5_help/catkin_generated/installspace/a5_help-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/a5_help/cmake" TYPE FILE FILES
    "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/build/a5_help/catkin_generated/installspace/a5_helpConfig.cmake"
    "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/build/a5_help/catkin_generated/installspace/a5_helpConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/a5_help" TYPE FILE FILES "/home/yoda/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/src/a5_help/package.xml")
endif()

