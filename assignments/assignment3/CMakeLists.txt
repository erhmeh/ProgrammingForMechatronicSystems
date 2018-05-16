cmake_minimum_required(VERSION 2.8)

project(assignment2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(main ranger sonar radar data_fusion radar.cpp sonar.cpp main.cpp ranger.cpp data_fusion.cpp)
