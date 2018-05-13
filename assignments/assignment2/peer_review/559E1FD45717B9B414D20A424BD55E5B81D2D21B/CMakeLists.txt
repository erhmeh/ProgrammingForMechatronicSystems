# The minimum version of CMake Required
cmake_minimum_required (VERSION 2.6)

# Any project name will suffice, this has connotaions when using advanced CMake Features
project (Assignment2_2)

# CMake will now create the Makefiles that are needed to make an executable "hello" that requires "hello.cpp"
add_executable(main main.cpp laser.cpp radarLeft.cpp radarRight.cpp ranger.cpp rangerFusion.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")