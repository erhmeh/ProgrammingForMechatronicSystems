cmake_minimum_required(VERSION 2.8)

project(assignment2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(main Ranger Laser Radar Radar.cpp Laser.cpp main.cpp Ranger.cpp)
