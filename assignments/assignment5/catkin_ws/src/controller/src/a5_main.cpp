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
#include <unistd.h>

#include "instant.h"

namespace enc = sensor_msgs::image_encodings;

std::stack<instant> buf;
std::mutex          buf_mutex_;
std::mutex          inst_mutex_;

instant i;

struct pixel { int x; int y; bool isFrontier = 0; bool isFree = 0; bool isWall =
                 0;
               bool isUnknown = 0; double distance = -1; };
std::vector<pixel> frontiers;
pixel latestFrontier;

void callbackOdom(const nav_msgs::OdometryConstPtr& msg)
{
  i.convPose(msg);
}

void callbackImg(const sensor_msgs::ImageConstPtr& msg)
{
  inst_mutex_.lock();

  if (sensor_msgs::image_encodings::isColor(msg->encoding)) i.
    currentImgPtr_ = cv_bridge::toCvCopy(
      msg,
      enc::BGR8);
  else i.currentImgPtr_ = cv_bridge::toCvCopy(
      msg,
      enc::MONO8
      );
  i.storeCVImg();
  inst_mutex_.unlock();
}

void bufTh() {
  ros::Rate rate_limiter(1.0);

  while (ros::ok()) {
    inst_mutex_.lock();
    buf_mutex_.lock();
    buf.push(i);

    // ROS_INFO("Stack Size: %d", buf.size());
    inst_mutex_.unlock();
    buf_mutex_.unlock();
    rate_limiter.sleep();
  }
}

void frontierTh() {
  ros::Rate rate_limiter(1);

  while (ros::ok()) {
    buf_mutex_.lock();

    instant data = buf.top();
    buf_mutex_.unlock();

    if (data.img_.rows == 200) {
      frontiers.clear();

      for (int x = 1; x < 200; x++) {
        for (int y = 1; y < 200; y++) {
          cv::Point2f pt(x, y);
          int px = data.img_.at<uchar>(pt.y, pt.x);

          if (px == 255) {
            cv::Point2f neighbour1(x + 1, y);
            cv::Point2f neighbour2(x + 1, y + 1);
            cv::Point2f neighbour3(x + 1, y - 1);
            cv::Point2f neighbour4(x - 1, y);
            cv::Point2f neighbour5(x - 1, y + 1);
            cv::Point2f neighbour6(x - 1, y - 1);
            cv::Point2f neighbour7(x, y + 1);
            cv::Point2f neighbour8(x, y - 1);

            if ((data.img_.at<uchar>(neighbour1.y,
                                     neighbour1.x) == 127) ||
                (data.img_.at<uchar>(neighbour2.y,
                                     neighbour2.x) == 127) ||
                (data.img_.at<uchar>(neighbour3.y,
                                     neighbour3.x) == 127) ||
                (data.img_.at<uchar>(neighbour4.y,
                                     neighbour4.x) == 127) ||
                (data.img_.at<uchar>(neighbour5.y,
                                     neighbour5.x) == 127) ||
                (data.img_.at<uchar>(neighbour6.y,
                                     neighbour6.x) == 127) ||
                (data.img_.at<uchar>(neighbour7.y,
                                     neighbour7.x) == 127) ||
                (data.img_.at<uchar>(neighbour8.y, neighbour8.x) == 127)) {
              pixel frontier;
              frontier.x          = x;
              frontier.y          = y;
              frontier.isFrontier = 1;
              frontier.isFree     = 1;
              frontiers.push_back(frontier);
            }
          }
        }
      }
      std::cout << "Number of frontier pixels " << frontiers.size() << std::endl;

      for (unsigned int i = 0; i < frontiers.size(); i++) {
        pixel  q         = frontiers[i];
        double distancex = pow(q.x - 100.0, 2);
        double distancey = pow(q.y - 100.0, 2);
        double distance  = sqrt(distancex + distancey);
        q.distance   = distance;
        frontiers[i] = q;
      }

      while (frontiers.size() != 1) {
        pixel a = frontiers[0];
        pixel b = frontiers[1];

        if (a.distance <= b.distance) {
          frontiers.erase(frontiers.begin() + 1);
        }
        else {
          frontiers.erase(frontiers.begin());
        }
      }
      pixel latestFrontier = frontiers[0];
      std::cout << "Closest frontier pixel is located at " << latestFrontier.x <<
      ", " << latestFrontier.y << " at a distance of " <<
      latestFrontier.distance << std::endl;
    }
    buf.empty();
    rate_limiter.sleep();
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "a5_main");

  ros::NodeHandle n;


  ros::Subscriber sub1 = n.subscribe("odom", 1000, callbackOdom);
  ros::Subscriber sub2 = n.subscribe("map_image/full", 1000, callbackImg);
  std::thread     t1(bufTh);
  std::thread     t2(frontierTh);

  ros::spin();
  t1.join();
  t2.join();

  return 0;
}
