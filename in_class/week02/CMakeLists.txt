# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

# Any project name will suffice, this has connotaions when using advanced CMake Features
project (week_02)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# To add executables provide the executable name followed by a list of source files
# There must be exactly one function called main in each executable
add_executable(classes classes.cpp)
add_executable(pointers pointers.cpp)
add_executable(functions functions.cpp)
