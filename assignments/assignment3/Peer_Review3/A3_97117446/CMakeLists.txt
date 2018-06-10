# The minimum version of CMake Required 
cmake_minimum_required (VERSION 2.6)

# Any poject name will suffice, this has connotaions when using advanced CMake Features
project (A3_97117446)

# Adds threads functionality to the project
find_package (Threads)

# Adds C++11 functionality to the project
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

# CMake will now create the Makefiles that are needed to make an executable "hello" that requires "hello.cpp"
add_executable(A3_97117446 A3.cpp DataFusion.cpp Radar.cpp Ranger.cpp SensorDataGenerator.cpp Sonar.cpp)

# add a target to generate API documentation with Doxygen
#########################################################
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)
#########################################################
