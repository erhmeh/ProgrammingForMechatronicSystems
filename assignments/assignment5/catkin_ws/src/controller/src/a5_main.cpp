#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tf/transform_datatypes.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/image_encodings.h"
#include "nav_msgs/Odometry.h"
#include <image_transport/image_transport.h>
#include <std_msgs/Float64.h>

#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include <thread>
#include <chrono>
#include <deque>
#include <mutex>
#include <random>

void callbackOdom(const nav_msgs::OdometryConstPtr& msg)
{
  float quaternionOrientationZ = msg->pose.pose.orientation.z;
  float quaternionOrientationW = msg->pose.pose.orientation.w;

  ROS_INFO("Z: [%f]", quaternionOrientationZ);
  ROS_INFO("W: [%f]", quaternionOrientationW);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "a5_main");

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("odom", 1000, callbackOdom);

  ros::spin();

  return 0;
}
