/**
 * instant.h
 * 41012 Autumn 2018 - Programming for Mechatronic systems
 * Assignment 5
 *
 * @author: Jamin Early 99133391
 * @date: Due 17th June 2018
 */

#ifndef INSTANT_H
#define INSTANT_H

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

/*  An instant is a specific reading taken at a specific instant in time. While a collection of readings is not taken at the
 *  same time, the purpose of this object is to hold the most recent available information. These instants are buffered in the
 *  main class for global use.
 */
class instant {
public:

  void convPosePx(nav_msgs::OdometryConstPtr i); // Converts odometry message to pose
  void storeCVImg();                             // Takes a copy of the image from the pointer
  cv::Mat img_;                                  // Latest image available at the instant
  double  angle_;                                // Angle of the robot in degrees
  float   x_;                                    // Position of the robot on x axis
  float   y_;                                    // Position of the robot on y axis
  cv_bridge::CvImagePtr currentImgPtr_;          // Holds pointer of current image

private:

  geometry_msgs::Pose pose_; // Current pose
};

#endif // ifndef INSTANT_H
