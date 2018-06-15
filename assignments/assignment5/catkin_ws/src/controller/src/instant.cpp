/**
 * instant.cpp
 * 41012 Autumn 2018 - Programming for Mechatronic systems
 * Assignment 5
 *
 * @author: Jamin Early 99133391
 * @date: Due 17th June 2018
 */

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Float64.h>
#include "tf/transform_datatypes.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/image_encodings.h"
#include "nav_msgs/Odometry.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include <thread>
#include <chrono>
#include <deque>
#include <string>
#include <mutex>
#include <random>
#include <stack>
#include <queue>
#include <unistd.h>
#include <algorithm>
#include "instant.h"

// Extracts needed information out of the odom message
void instant::convPosePx(nav_msgs::OdometryConstPtr i) {
  pose_  = i->pose.pose;                                 // extracts pose
  angle_ = tf::getYaw(pose_.orientation) * 180.0 / M_PI; // Converts the quaternion yaw to a simple angle in degrees
  x_     = pose_.position.x;                             // Holds x coordiance
  y_     = pose_.position.y;                             // Holds y coordinance
}

// Stores the latest image
void instant::storeCVImg() {
  img_ = currentImgPtr_->image;
}
