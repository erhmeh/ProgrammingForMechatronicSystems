# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.6)

# Any project name will suffice, this has connotaions when using advanced CMake Features
project (PSM_A1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# CMake will now create the Makefiles that are needed to make an executable
add_executable(main main.cpp Accelerometer.cpp VAccelerometer.cpp)


