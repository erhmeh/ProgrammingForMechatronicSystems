cmake_minimum_required(VERSION 2.8)

project(assignment2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(main ranger laser radar rangerfusion rangerfusioninterface radar.cpp laser.cpp main.cpp ranger.cpp rangerfusion.cpp rangerfusioninterface.cpp)
