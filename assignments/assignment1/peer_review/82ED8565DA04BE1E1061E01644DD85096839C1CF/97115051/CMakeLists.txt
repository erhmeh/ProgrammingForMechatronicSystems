# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using advanced CMake Features
project (Assignment1)

# CMake will now ammend the Makefiles so that an executable "hello-out" that requires "hello-out.cpp" can be created
add_executable(main main.cpp axis_accelerometer_sensor.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

