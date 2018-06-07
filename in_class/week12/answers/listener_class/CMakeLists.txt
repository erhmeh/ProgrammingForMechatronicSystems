cmake_minimum_required(VERSION 2.8.3)
project(ros_listener_tutorial)

# check c++11 / c++0x ==> See http://answers.ros.org/question/152276/is-there-a-way-to-enable-c11-support-for-catkin-packages/
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "-std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "-std=c++0x")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


find_package(catkin REQUIRED COMPONENTS rostime roscpp rosconsole roscpp_serialization)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

link_directories(${catkin_LIBRARY_DIRS})

catkin_package(CATKIN_DEPENDS std_msgs)

add_library(listener_lib
  src/listener_class.cpp
)
#
### Add cmake target dependencies of the library
#add_dependencies(ekf ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS} )

add_executable(talker src/talker.cpp )
target_link_libraries(talker ${catkin_LIBRARIES} )


add_executable(listener_class src/main.cpp )
target_link_libraries(listener_class ${catkin_LIBRARIES} listener_lib)

install(TARGETS listener_class
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})


#############
## Testing ##
#############
catkin_add_gtest(${PROJECT_NAME}-test test/utest.cpp)
if(TARGET ${PROJECT_NAME}-test)
   target_link_libraries(${PROJECT_NAME}-test ${catkin_LIBRARIES} listener_lib)
endif()

