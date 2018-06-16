/**
 * main.h
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
 #include <geometry_msgs/PoseArray.h>
 #include <geometry_msgs/Pose.h>

// #include "a5_help/RequestGoal.h"
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

struct pixel { int x; int y; double distance = -1; double distancex = -1; double distancey = -1; }; // Basic structure for a pixel

struct goalPx { pixel                  p;
                std::queue<cv::Point2f>visibleFrontiers;
                double                 bearing;
                std::queue<cv::Point2f>viewablePixels; };

// Prototype Functions
void                callbackOdom(const nav_msgs::OdometryConstPtr& msg);
bool                sortByDist(const pixel& lhs,
                               const pixel& rhs);
void                sortFrontierPixels();
void                computegoalPx();
bool                sortByViewableFrontiers(const goalPx& lhs,
                                            const goalPx& rhs);
void                sortGoalCandidates();
void                addPossiblepxPose(int         x,
                                      int         y,
                                      cv::Point2f pt);
void                callbackImg(const sensor_msgs::ImageConstPtr& msg);
void                bufTh();
void                goalTh();
void                findFrontiers();
void                findGoal();
geometry_msgs::Pose pixelToPose(goalPx gPx);
cv_bridge::CvImage  generateNewImg(cv::Mat oldImg);

// Global variables and data structures that are shared between threads and nodes
std::stack<instant> buf;               // Buffer for several 'instants' stored as a stack. This way the most recent instant is always on the top
std::mutex          buf_mutex_;        // Mutex for buffer access
std::mutex          inst_mutex_;       // Mutex for instant access
image_transport::Publisher image_pub_; // Manages the image topic that is being published to
ros::Publisher pathPosePub;            // Manages publishing to the path topic
instant i;                             // Local instant for multi node access
cv::Mat oldImg;                        // Holds the last image recieved from the Og Map topic
cv::Mat newImg;                        // Manipulated version of the oldImg with changes made to show required information
std::vector<pixel>  frontiers;         // A vector of frontiers. It is stored as a vector as random access is required for searching and sorting
std::vector<goalPx> possiblegoalPx;    // A vector of possible goal cells adjacent to the closest frontier
instant latest;                        // The latest instant being processed. A copy is stored so that the buffer can be written to while processing is taking place
goalPx  goal;                          // Holds the latest calculated global variable
geometry_msgs::PoseArray goalPoses;    // Array of all goal poses
