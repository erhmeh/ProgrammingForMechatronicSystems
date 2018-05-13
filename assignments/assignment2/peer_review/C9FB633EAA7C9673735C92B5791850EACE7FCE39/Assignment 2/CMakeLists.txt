cmake_minimum_required (VERSION 2.8)

project (Assignment_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(Assignment_2 main.cpp Ranger.cpp Laser.cpp Radar.cpp RangerFusion.cpp RangerFusionInterface.cpp)
