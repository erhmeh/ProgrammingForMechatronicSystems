#ifndef INSTANT_H
#define INSTANT_H

#include "ros/ros.h"
#include "std_msgs/String.h"
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

#include <thread>
#include <chrono>
#include <deque>
#include <mutex>
#include <random>

class instant {
public:

  void convPose(nav_msgs::OdometryConstPtr i);
  void storeCVImg();
  cv::Mat img_;
  double  angle_;
  float   x_;
  float   y_;
  cv_bridge::CvImagePtr currentImgPtr_;

private:

  geometry_msgs::Pose pose_;
};

#endif // ifndef INSTANT_H
