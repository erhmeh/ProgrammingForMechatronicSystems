# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.6)

# Any ppoject name will suffice, this has connotaions when using advanced CMake Features
project (rectangle)

# CMake will now create the Makefiles that are needed to make an executable "hello" that requires "hello.cpp" 
add_executable(shapes main.cpp rectangle.cpp)
