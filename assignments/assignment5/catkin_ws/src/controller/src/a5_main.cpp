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
#include <stack>

#include "instant.h"

std::stack<instant> buf;

instant i;

void callbackOdom(const nav_msgs::OdometryConstPtr& msg)
{
  i.convPose(msg);

  // geometry_msgs::Pose pose = msg->pose.pose;
  // double yaw               = tf::getYaw(pose.orientation);
  // double yawDegrees        = yaw * 180.0 / M_PI;
  //
  // if (yawDegrees < 0) yawDegrees += 360.0;
  // ROS_INFO("YAW: [%lf]",         yaw);
  ROS_INFO("YAW Degrees: [%lf]", i.angle_);
}

void callbackImg(const sensor_msgs::ImageConstPtr& msg)
{}

int  main(int argc, char **argv)
{
  ros::init(argc, argv, "a5_main");

  ros::NodeHandle n;
  ros::Subscriber sub1 = n.subscribe("odom", 1000, callbackOdom);
  ros::Subscriber sub2 = n.subscribe("map_image/full", 1000, callbackImg);

  ros::spin();

  return 0;
}
