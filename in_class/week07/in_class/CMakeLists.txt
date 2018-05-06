cmake_minimum_required (VERSION 2.6)

project (threading)

# Needed to use threads
find_package (Threads)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(main dummy dummy.cpp main.cpp)
