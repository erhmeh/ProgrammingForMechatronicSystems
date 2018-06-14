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

struct pixel { int x; int y; double distance = -1; };

struct goalPx { pixel                  p;
                std::queue<cv::Point2f>visibleFrontiers;
                double                 bearing;
                std::queue<cv::Point2f>viewablePixels; };

void               callbackOdom(const nav_msgs::OdometryConstPtr& msg);
bool               sortByDist(const pixel& lhs,
                              const pixel& rhs);
void               sortFrontierPixels();
void               computegoalPx();
bool               sortByViewableFrontiers(const goalPx& lhs,
                                           const goalPx& rhs);
void               sortGoalCandidates();
void               addPossiblepxPose(int         x,
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
std::vector<pixel>  frontiers;
std::vector<goalPx> possiblegoalPx;
instant latest;

void callbackOdom(const nav_msgs::OdometryConstPtr& msg)
{
  i.convPosePx(msg);
}

bool isFrontier(cv::Point2f pt) {
  int px = latest.img_.at<uchar>(pt.y, pt.x);

  if (px == 255) {
    cv::Point2f neighbour1(pt.x + 1, pt.y);
    cv::Point2f neighbour2(pt.x + 1, pt.y + 1);
    cv::Point2f neighbour3(pt.x + 1, pt.y - 1);
    cv::Point2f neighbour4(pt.x - 1, pt.y);
    cv::Point2f neighbour5(pt.x - 1, pt.y + 1);
    cv::Point2f neighbour6(pt.x - 1, pt.y - 1);
    cv::Point2f neighbour7(pt.x, pt.y + 1);
    cv::Point2f neighbour8(pt.x, pt.y - 1);

    if ((latest.img_.at<uchar>(neighbour1.y,
                               neighbour1.x) == 127) ||
        (latest.img_.at<uchar>(neighbour2.y,
                               neighbour2.x) == 127) ||
        (latest.img_.at<uchar>(neighbour3.y,
                               neighbour3.x) == 127) ||
        (latest.img_.at<uchar>(neighbour4.y,
                               neighbour4.x) == 127) ||
        (latest.img_.at<uchar>(neighbour5.y,
                               neighbour5.x) == 127) ||
        (latest.img_.at<uchar>(neighbour6.y,
                               neighbour6.x) == 127) ||
        (latest.img_.at<uchar>(neighbour7.y,
                               neighbour7.x) == 127) ||
        (latest.img_.at<uchar>(neighbour8.y, neighbour8.x) == 127)) {
      return true;
    }
  }
  return false;
}

bool sortByDist(const pixel& lhs, const pixel& rhs)
{
  return lhs.distance < rhs.distance;
}

void sortFrontierPixels()
{
  sort(frontiers.begin(), frontiers.end(), sortByDist);
}

bool sortByViewableFrontiers(const goalPx& lhs, const goalPx& rhs)
{
  return lhs.visibleFrontiers.size() > rhs.visibleFrontiers.size();
}

void sortGoalCandidates()
{
  sort(possiblegoalPx.begin(), possiblegoalPx.end(), sortByViewableFrontiers);
}

void addPossiblepxPose(int x, int y, cv::Point2f pt)
{
  if (oldImg.at<uchar>(pt.y, pt.x) == 255) {
    goalPx pxPose;
    pxPose.p.x = pt.x;
    pxPose.p.y = pt.y;

    if (x > pt.x) {
      if (y > pt.y) {
        pxPose.bearing = -45.0;
        pxPose.viewablePixels.push(cv::Point2f(x, y));
        pxPose.viewablePixels.push(cv::Point2f(x, y - 1));
        pxPose.viewablePixels.push(cv::Point2f(x - 1, y));
      }

      else if (y < pt.y) {
        pxPose.bearing = 45.0;
        pxPose.viewablePixels.push(cv::Point2f(x, y));
        pxPose.viewablePixels.push(cv::Point2f(x, y + 1));
        pxPose.viewablePixels.push(cv::Point2f(x - 1, y));
      }
      else {
        pxPose.bearing = 0.0;
        pxPose.viewablePixels.push(cv::Point2f(x, y));
        pxPose.viewablePixels.push(cv::Point2f(x, y + 1));
        pxPose.viewablePixels.push(cv::Point2f(x, y - 1));
      }
    }

    else if (x == pt.x) {
      if (y > pt.y) {
        pxPose.bearing = -90.0;
        pxPose.viewablePixels.push(cv::Point2f(x, y));
        pxPose.viewablePixels.push(cv::Point2f(x + 1, y));
        pxPose.viewablePixels.push(cv::Point2f(x - 1, y));
      }

      else if (y < pt.y) {
        pxPose.bearing = 90.0;
        pxPose.viewablePixels.push(cv::Point2f(x, y));
        pxPose.viewablePixels.push(cv::Point2f(x + 1, y));
        pxPose.viewablePixels.push(cv::Point2f(x - 1, y));
      }
    }

    else if (x < pt.x) {
      if (y > pt.y) {
        pxPose.bearing = -135.0;
        pxPose.viewablePixels.push(cv::Point2f(x, y));
        pxPose.viewablePixels.push(cv::Point2f(x + 1, y));
        pxPose.viewablePixels.push(cv::Point2f(x, y - 1));
      }

      else if (y < pt.y) {
        pxPose.bearing = 135.0;
        pxPose.viewablePixels.push(cv::Point2f(x, y));
        pxPose.viewablePixels.push(cv::Point2f(x + 1, y));
        pxPose.viewablePixels.push(cv::Point2f(x, y + 1));
      }
      else {
        pxPose.bearing = 180.0;
        pxPose.viewablePixels.push(cv::Point2f(x, y));
        pxPose.viewablePixels.push(cv::Point2f(x, y + 1));
        pxPose.viewablePixels.push(cv::Point2f(x, y - 1));
      }
    }

    while (!pxPose.viewablePixels.empty()) {
      cv::Point2f t = pxPose.viewablePixels.front();

      if (isFrontier(t)) pxPose.visibleFrontiers.push(t);
      pxPose.viewablePixels.pop();
    }
    possiblegoalPx.push_back(pxPose);
  }
}

void computegoalPx()
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

  possiblegoalPx.clear();

  while (!neighbours.empty())
  {
    addPossiblepxPose(x, y, neighbours.front());
    neighbours.pop();
  }
  sortGoalCandidates();
  goalPx goal = possiblegoalPx.front();
  std::cout << "Goal Pixel- x: " << goal.p.x << " y: " << goal.p.y <<
  " Visible frontiers: " << goal.visibleFrontiers.size() << std::endl;
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
  ros::Rate rate_limiter(1. / 10.);

  while (ros::ok()) {
    buf_mutex_.lock();

    latest = buf.top();
    buf_mutex_.unlock();

    if (latest.img_.rows == 200) {
      oldImg = latest.img_;
      frontiers.clear();

      for (int x = 1; x < 200; x++) {
        for (int y = 1; y < 200; y++) {
          cv::Point2f pt(x, y);

          if (isFrontier(pt)) {
            pixel frontier;
            frontier.x = x;
            frontier.y = y;
            frontiers.push_back(frontier);
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
      computegoalPx();

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

  cv_image.image.at<cv::Vec3b>(100, 100) = { 0, 255, 0 };

  for (unsigned int i = 0; i < frontiers.size(); i++) {
    pixel f = frontiers[i];
    cv_image.image.at<cv::Vec3b>(f.y, f.x) = { 0, 255, 255 };
  }
  goalPx g = possiblegoalPx.front();
  cv_image.image.at<cv::Vec3b>(g.p.y, g.p.x) = { 0, 0, 255 };

  while (!g.visibleFrontiers.empty()) {
    cv::Point2f f = g.visibleFrontiers.front();
    cv_image.image.at<cv::Vec3b>(f) = { 255, 0, 0 };
    g.visibleFrontiers.pop();
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
