
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

#include "a5_help/RequestGoal.h"
#include "drawing_tools.h"

#include <sstream>
#include <iostream>
#include <string>

#include <thread>
#include <chrono>
#include <deque>
#include <mutex>
#include <random>

namespace enc = sensor_msgs::image_encodings;

/**
 * This node shows some connections and publishing images
 */


class GazeboRetrieve {
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Publisher image_pub_;
  ros::Subscriber sub1_;
  ros::Subscriber sub2_;
  image_transport::Subscriber sub3_;
  cv_bridge::CvImagePtr cvPtr_;
  ros::ServiceServer    service_;

  int count_;         // ! A counter to allow executing items on N iterations
  double resolution_; // ! size of OgMap in pixels

  struct DataBuffer
  {
    std::deque<geometry_msgs::Pose>poseDeq;
    std::deque<ros::Time>          timeStampDeq;
    std::mutex                     buffer_mutex_;
  };
  DataBuffer buffer; // ! And now we have our container

  struct ImageDataBuffer
  {
    std::deque<cv::Mat>  imageDeq;
    std::deque<ros::Time>timeStampDeq;
    std::mutex           buffer_mutex_;
  };
  ImageDataBuffer imageBuffer; // ! And now we have our container

public:

  GazeboRetrieve(ros::NodeHandle nh)
    : nh_(nh), it_(nh)
  {
    sub1_ = nh_.subscribe("odom", 1000, &GazeboRetrieve::odomCallback, this);
    sub2_ = nh_.subscribe("scan", 10, &GazeboRetrieve::laserCallback, this);
    image_transport::ImageTransport it(nh);
    sub3_ = it.subscribe("map_image/full",
                         1,
                         &GazeboRetrieve::imageCallback,
                         this);

    // Publishing an image ... just to show how
    image_pub_ = it_.advertise("test/image", 1);

    // Allowing an incoming service
    service_ = nh_.advertiseService("request_goal",
                                    &GazeboRetrieve::requestGoal,
                                    this);

    // Below is how to get parameters from command line, on command line they
    // need to be _param:=value
    ros::NodeHandle pn("~");
    double mapSize;
    double resolution;
    pn.param<double>("map_size", mapSize, 20.0);
    pn.param<double>("resolution", resolution_, 0.1);

    count_ = 0;

    //        cv::namedWindow("view",CV_WINDOW_NORMAL);
    //        cv::startWindowThread();
    //        cv::waitKey(5);
  }

  ~GazeboRetrieve()
  {
    cv::destroyWindow("view");
  }

  bool requestGoal(a5_help::RequestGoal::Request & req,
                   a5_help::RequestGoal::Response& res)
  {
    ROS_INFO("request: x=%6.4f, y=%6.4f",   (double)req.x, (double)req.y);
    res.ack = true;
    ROS_INFO("sending back response: [%d]", res.ack);
    return true;
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

  void laserCallback(const sensor_msgs::LaserScanConstPtr& msg)
  {
    // ! Below sample cicrulates through the scan and finds closest point to
    // robot
    double closest_point = msg->range_max;
    double angle         = 0;
    double x, y;

    for (unsigned int idx = 0; idx < msg->ranges.size(); idx++) {
      if (msg->ranges.at(idx) < closest_point) {
        closest_point = msg->ranges.at(idx);
        angle         = msg->angle_min + (idx * msg->angle_increment);
      }
    }
    ros::Time timeLaser = msg->header.stamp;
    x = closest_point * cos(angle);
    y = closest_point * sin(angle);
    std::cout << timeLaser << " L: [d,theta,x,y]=[" << closest_point << "," <<
    angle << "," << x << "," << y << "]" << std::endl;
  }

  void imageCallback(const sensor_msgs::ImageConstPtr& msg)
  {
    // ! Below code pushes the image and time to a deque, to share across
    // threads
    try
    {
      if (enc::isColor(msg->encoding)) cvPtr_ = cv_bridge::toCvCopy(msg,
                                                                    enc::BGR8);
      else cvPtr_ = cv_bridge::toCvCopy(msg, enc::MONO8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    imageBuffer.buffer_mutex_.lock();
    imageBuffer.imageDeq.push_back(cvPtr_->image);
    imageBuffer.timeStampDeq.push_back(msg->header.stamp);

    if (imageBuffer.imageDeq.size() > 2) {
      imageBuffer.imageDeq.pop_front();
      imageBuffer.timeStampDeq.pop_front();
    }
    imageBuffer.buffer_mutex_.unlock();
  }

  void seperateThread() {
    /**
     * The below loop runs until ros is shutdown, to ensure this thread does not
     *remain
     * a zombie thread
     *
     * The loop locks the buffer, checks the size
     * And then pulls items: the pose and timer_t
     * You can contemplate weather these could have been combined into one ...
     */

    double yaw, x, y;

    // / The below gets the current Ros Time
    ros::Time timeOdom  = ros::Time::now();
    ros::Time timeImage = ros::Time::now();
    cv::Mat   image;


    ros::Rate rate_limiter(1.0);

    while (ros::ok()) {
      int deqSz = -1;

      buffer.buffer_mutex_.lock();
      deqSz = buffer.poseDeq.size();

      if (deqSz > 0) {
        geometry_msgs::Pose pose = buffer.poseDeq.front();
        yaw      = tf::getYaw(pose.orientation);
        x        = pose.position.x;
        y        = pose.position.y;
        timeOdom = buffer.timeStampDeq.front();
        buffer.poseDeq.pop_front();
        buffer.timeStampDeq.pop_front();
      }
      buffer.buffer_mutex_.unlock();

      // ! Lock image buffer, take one message from deque and unlock it
      imageBuffer.buffer_mutex_.lock();

      if (imageBuffer.imageDeq.size() > 0) {
        image     = imageBuffer.imageDeq.front();
        timeImage = imageBuffer.timeStampDeq.front();
        imageBuffer.imageDeq.pop_front();
        imageBuffer.timeStampDeq.pop_front();
      }
      imageBuffer.buffer_mutex_.unlock();

      std::cout << timeOdom  << " O: [x,y,yaw]=[" <<
      x << "," << y << "," << yaw << "]" << std::endl;
      std::cout << " pos [x,y]=[" <<
      (x / resolution_) << ","  << (y / resolution_) << "] " <<
      " pos [x,y]=[" <<
      (x /
      resolution_) +
      (image.rows /
      2) << "," << (y / resolution_) + (image.cols / 2) << "]" << std::endl;

      if (!image.empty()) {
        cv_bridge::CvImage cv_image;
        cv::cvtColor(image, cv_image.image, CV_GRAY2RGB);
        drawing_tools::drawRedDot(cv_image.image);

        //                cv::imshow("view", cv_image.image);
        //                cv::waitKey(5);
        cv_image.encoding = "bgr8";
        cv_image.header   = std_msgs::Header();
        image_pub_.publish(cv_image.toImageMsg());
      }
      rate_limiter.sleep();
    }
  }
};


int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command
   *line. For programmatic
   * remappings you can use a different version of init() which takes remappings
   * directly, but for most command-line programs, passing argc and argv is the
   *easiest
   * way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "a5_help");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the
   *last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle nh;

  /**
   * Let's start seperate thread first, to do that we need to create object
   * and thereafter start the thread on teh function desired
   */
  std::shared_ptr<GazeboRetrieve> gc(new GazeboRetrieve(nh));
  std::thread t(&GazeboRetrieve::seperateThread, gc);

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).
   * ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  /**
   * Let's cleanup everything, shutdown ros and join the thread
   */
  ros::shutdown();
  t.join();

  return 0;
}
