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
#include "instant.h"

void instant::convPosePx(nav_msgs::OdometryConstPtr i) {
  pose_  = i->pose.pose;
  angle_ = tf::getYaw(pose_.orientation) * 180.0 / M_PI;

  if (angle_ < 0) angle_ += 360.0;
  x_ = pose_.position.x;
  y_ = pose_.position.y;
}

void instant::storeCVImg() {
  img_ = currentImgPtr_->image;
}
