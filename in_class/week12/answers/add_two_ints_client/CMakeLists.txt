cmake_minimum_required(VERSION 2.8.3)
project(ros_service_tutorial_part2)

#find_package(Boost REQUIRED COMPONENTS date_time thread)
find_package(catkin REQUIRED COMPONENTS message_generation rostime roscpp rosconsole roscpp_serialization ros_service_tutorial)

include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

#add_service_files(DIRECTORY srv FILES TwoInts.srv)
#generate_messages(DEPENDENCIES std_msgs)

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

add_executable(add_two_ints_client src/add_two_ints_client.cpp)
target_link_libraries(add_two_ints_client ${catkin_LIBRARIES})
install(TARGETS add_two_ints_client
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

