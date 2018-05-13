cmake_minimum_required(VERSION 2.8)

project(Ass2)
add_executable(main main.cpp rangerfusioninterface.cpp ranger.cpp laser.cpp radar.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

