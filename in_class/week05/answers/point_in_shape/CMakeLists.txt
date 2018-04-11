cmake_minimum_required (VERSION 3.2)
project (point_in_shape)
set(CMAKE_CXX_STANDARD 11)
add_executable(point_in_shape main.cpp shape.cpp rectangle.cpp circle.cpp shape_functions.cpp)
