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
#include <string>
#include <mutex>
#include <random>
#include <stack>
#include <queue>
#include <unistd.h>
#include <algorithm>

#include "instant.h"

namespace enc = sensor_msgs::image_encodings;

struct pixel { int x; int y; double distance = -1; int visibleFrontiers; };

struct goalPose { pixel p; int visibleFrontiers; double bearing;  };

void               callbackOdom(const nav_msgs::OdometryConstPtr& msg);
bool               sortByDist(const pixel& lhs,
                              const pixel& rhs);
void               sortFrontierPixels();
void               computeGoalPose();
void               addPossiblePose(int         x,
                                   int         y,
                                   cv::Point2f pt);
void               callbackImg(const sensor_msgs::ImageConstPtr& msg);
void               bufTh();
void               goalTh();
cv_bridge::CvImage generateNewImg(cv::Mat oldImg);

std::stack<instant> buf;
std::mutex          buf_mutex_;
std::mutex          inst_mutex_;
image_transport::Publisher image_pub_;
instant i;
cv::Mat oldImg;
cv::Mat newImg;
std::vector<pixel>    frontiers;
std::vector<goalPose> possibleGoalPose;

void callbackOdom(const nav_msgs::OdometryConstPtr& msg)
{
  i.convPose(msg);
}

bool sortByDist(const pixel& lhs, const pixel& rhs)
{
  return lhs.distance < rhs.distance;
}

void sortFrontierPixels()
{
  sort(frontiers.begin(), frontiers.end(), sortByDist);
}

void addPossiblePose(int x, int y, cv::Point2f pt)
{
  if (oldImg.at<uchar>(pt.y, pt.x) == 255) {
    goalPose pose;
    // pose.pixel.x = 
    std::queue<cv::Point2f> viewablePixels;

    if (x > pt.x) {
      if (y > pt.y) {
        pose.bearing = -45.0;
        viewablePixels.push(cv::Point2f(x, y));
        viewablePixels.push(cv::Point2f(x, y - 1));
        viewablePixels.push(cv::Point2f(x - 1, y));
      }

      if (y < pt.y) {
        pose.bearing = 45.0;
        viewablePixels.push(cv::Point2f(x, y));
        viewablePixels.push(cv::Point2f(x, y + 1));
        viewablePixels.push(cv::Point2f(x - 1, y));
      }
      else {
        pose.bearing = 0.0;
        viewablePixels.push(cv::Point2f(x, y));
        viewablePixels.push(cv::Point2f(x, y + 1));
        viewablePixels.push(cv::Point2f(x, y - 1));
      }
    }

    if (x == pt.x) {
      if (y > pt.y) {
        pose.bearing = -90.0;
        viewablePixels.push(cv::Point2f(x, y));
        viewablePixels.push(cv::Point2f(x + 1, y));
        viewablePixels.push(cv::Point2f(x - 1, y));
      }

      if (y < pt.y) {
        pose.bearing = 90.0;
        viewablePixels.push(cv::Point2f(x, y));
        viewablePixels.push(cv::Point2f(x + 1, y));
        viewablePixels.push(cv::Point2f(x - 1, y));
      }
    }

    if (x < pt.x) {
      if (y > pt.y) {
        pose.bearing = -135.0;
        viewablePixels.push(cv::Point2f(x, y));
        viewablePixels.push(cv::Point2f(x + 1, y));
        viewablePixels.push(cv::Point2f(x, y - 1));
      }

      if (y < pt.y) {
        pose.bearing = 135.0;
        viewablePixels.push(cv::Point2f(x, y));
        viewablePixels.push(cv::Point2f(x + 1, y));
        viewablePixels.push(cv::Point2f(x, y + 1));
      }
      else {
        pose.bearing = 180.0;
        viewablePixels.push(cv::Point2f(x, y));
        viewablePixels.push(cv::Point2f(x, y + 1));
        viewablePixels.push(cv::Point2f(x, y - 1));
      }
    }

    while (!viewablePixels.empty()) {
      cv::Point2f t = viewablePixels.front();
      if (oldImg.at<uchar>(t.y, t.x) == 127) { pose.visibleFrontiers++; }
      viewablePixels.pop();
    }
  }
}

void computeGoalPose()
{
  pixel p = frontiers[0];
  int   x = p.x;
  int   y = p.y;

  std::queue<cv::Point2f> neighbours;
  neighbours.push(cv::Point2f(x + 1, y));
  neighbours.push(cv::Point2f(x + 1, y + 1));
  neighbours.push(cv::Point2f(x + 1, y - 1));
  neighbours.push(cv::Point2f(x - 1, y));
  neighbours.push(cv::Point2f(x - 1, y + 1));
  neighbours.push(cv::Point2f(x - 1, y - 1));
  neighbours.push(cv::Point2f(x, y + 1));
  neighbours.push(cv::Point2f(x, y - 1));

  while (!neighbours.empty())
  {
    addPossiblePose(x, y, neighbours.front());
    neighbours.pop();
  }

  // cv::Point2f neighbour1(x + 1, y);
  // cv::Point2f neighbour2(x + 1, y + 1);
  // cv::Point2f neighbour3(x + 1, y - 1);
  // cv::Point2f neighbour4(x - 1, y);
  // cv::Point2f neighbour5(x - 1, y + 1);
  // cv::Point2f neighbour6(x - 1, y - 1);
  // cv::Point2f neighbour7(x, y + 1);
  // cv::Point2f neighbour8(x, y - 1);

  // if ((data.img_.at<uchar>(neighbour1.y,
  //                          neighbour1.x) == 127) ||
  //     (data.img_.at<uchar>(neighbour2.y,
  //                          neighbour2.x) == 127) ||
  //     (data.img_.at<uchar>(neighbour3.y,
  //                          neighbour3.x) == 127) ||
  //     (data.img_.at<uchar>(neighbour4.y,
  //                          neighbour4.x) == 127) ||
  //     (data.img_.at<uchar>(neighbour5.y,
  //                          neighbour5.x) == 127) ||
  //     (data.img_.at<uchar>(neighbour6.y,
  //                          neighbour6.x) == 127) ||
  //     (data.img_.at<uchar>(neighbour7.y,
  //                          neighbour7.x) == 127) ||
  //     (data.img_.at<uchar>(neighbour8.y, neighbour8.x) == 127)) {
  //   pixel frontier;
  //   frontier.x = x;
  //   frontier.y = y;
  //   frontiers.push_back(frontier);
  // }
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

void bufTh()
{
  ros::Rate rate_limiter(1.0);

  while (ros::ok()) {
    inst_mutex_.lock();
    buf_mutex_.lock();
    buf.push(i);
    inst_mutex_.unlock();
    buf_mutex_.unlock();
    rate_limiter.sleep();
  }
}

void goalTh()
{
  ros::Rate rate_limiter(1);

  while (ros::ok()) {
    buf_mutex_.lock();

    instant data = buf.top();
    buf_mutex_.unlock();

    if (data.img_.rows == 200) {
      oldImg = data.img_;
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
              frontier.x = x;
              frontier.y = y;
              frontiers.push_back(frontier);
            }
          }
        }
      }

      // std::cout << "Number of frontier pixels " << frontiers.size() <<
      // std::endl;

      for (unsigned int i = 0; i < frontiers.size(); i++) {
        pixel  q         = frontiers[i];
        double distancex = pow(q.x - 100.0, 2);
        double distancey = pow(q.y - 100.0, 2);
        double distance  = sqrt(distancex + distancey);
        q.distance   = distance;
        frontiers[i] = q;
      }

      sortFrontierPixels();
      pixel closestFrontier = frontiers[0];

      // std::cout << "Closest frontier pixel is located at " <<
      // closestFrontier.x <<
      // ", " << closestFrontier.y << " at a distance of " <<
      // closestFrontier.distance << std::endl;
      computeGoalPose();

      generateNewImg(oldImg);
    }
    buf.empty();
    rate_limiter.sleep();
  }
}

cv_bridge::CvImage generateNewImg(cv::Mat oldImg)
{
  cv_bridge::CvImage cv_image;

  cv::cvtColor(oldImg, cv_image.image, 8);

  for (unsigned int i = 0; i < frontiers.size(); i++) {
    pixel q = frontiers[i];
    cv_image.image.at<cv::Vec3b>(q.y, q.x) = { 0, 0, 255 };
  }

  cv_image.encoding = "bgr8";
  cv_image.header   = std_msgs::Header();
  image_pub_.publish(cv_image.toImageMsg());
  return cv_image;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "a5_main");

  ros::NodeHandle n;
  image_transport::ImageTransport it(n);
  ros::Subscriber sub1 = n.subscribe("odom", 1000, callbackOdom);
  ros::Subscriber sub2 = n.subscribe("map_image/full",
                                     1000,
                                     callbackImg);
  image_pub_ = it.advertise("map_image/fbe", 1);
  std::thread t1(bufTh);
  std::thread t2(goalTh);

  ros::spin();
  t1.join();
  t2.join();

  return 0;
}
