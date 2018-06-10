#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tf/transform_datatypes.h"

#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/image_encodings.h"
#include "nav_msgs/Odometry.h"

// #include <opencv2/imgproc/imgproc.hpp>
#include <image_transport/image_transport.h>

// #include <opencv2/highgui/highgui.hpp>
// #include <cv_bridge/cv_bridge.h>
//
// #include "a5_help/RequestGoal.h"

// #include "drawing_tools.h"

#include <sstream>
#include <iostream>
#include <string>

#include <thread>
#include <chrono>
#include <deque>
#include <mutex>
#include <random>

namespace enc = sensor_msgs::image_encodings;

struct DataBuffer
{
  std::deque<geometry_msgs::Pose>poseDeq;
  std::deque<ros::Time>          timeStampDeq;
  std::mutex                     buffer_mutex_;
};

DataBuffer buffer;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

void odomCallback(const nav_msgs::OdometryConstPtr& msg)
{
  // Let's get the pose out from odometry message
  // REMEBER: on command line you can view entier msg as
  // rosmsg show nav_msgs/Odometry
  geometry_msgs::Pose pose = msg->pose.pose;

  buffer.buffer_mutex_.lock();
  buffer.poseDeq.push_back(pose);
  buffer.timeStampDeq.push_back(msg->header.stamp);
  buffer.buffer_mutex_.unlock();
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "a5_main");

  ros::NodeHandle n;

  // ros::Subscriber sub   = n.subscribe("/odom", 1, odomCallback);
  ros::Subscriber sub1_ = n.subscribe("odom",
                                      1000,
                                      odomCallback);

  ros::spin();

  return 0;
}
