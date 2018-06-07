#include <gtest/gtest.h>
#include <climits>
#include <iostream>
#include <algorithm>

#include "ros/ros.h"
#include "ros_listener_tutorial/listener_class.h"

//! Instructions for running the tests
//! student@ote:~/catkin_ws$ catkin_make tests
//! student@ote:~/catkin_ws$ ./devel/lib/ros_listener_tutorial/ros_listener_tutorial-test


TEST(StringsPrune,ShouldPass){

    //! Checking each element

    RosListenerTutorial::Listener listener;

    listener.process("A 01");
    listener.process("B 02");
    listener.process("C 03");
    listener.process("D 04");
    listener.process("E 05");
    listener.process("F 06");
    listener.process("G 07");
    listener.process("H 08");
    listener.process("I 09");
    listener.process("J 10");
    listener.process("K 11");

    std::string last_str = listener.query_last();

    std::cout << "LAST:" ;
    std::cout << last_str;
    std::cout << std::endl;

    ASSERT_TRUE(last_str.compare("K 11") == 0);

}


int main(int argc, char **argv) {
    ros::init(argc, argv, "ros_listener_tutorial_tests");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

