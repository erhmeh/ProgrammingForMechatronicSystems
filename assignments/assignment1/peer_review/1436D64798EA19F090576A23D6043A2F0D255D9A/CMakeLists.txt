# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.8)

# Any project name will suffice, this has connotaions when using advanced CMake Features
project (assignment01)

# CMake will now create the Makefiles that are needed to make an executable "hello" that requires "hello.cpp" 
add_executable(main main.cpp sensor.cpp sensor.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# CMake will now amend the Makefiles so that an executable "hello-out" that requires "hello-out.cpp" can be created
#add_executable(hello-cout hello-cout.cpp)

