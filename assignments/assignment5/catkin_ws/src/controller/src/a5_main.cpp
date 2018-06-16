/**
 * main.cpp
 * 41012 Autumn 2018 - Programming for Mechatronic systems
 * Assignment 5
 *
 * @author: Jamin Early 99133391
 * @date: Due 17th June 2018
 */

 #include "a5_main.h"
 #include "instant.h"

namespace enc = sensor_msgs::image_encodings;

// Callback for the odom subscriber
void callbackOdom(const nav_msgs::OdometryConstPtr& msg)
{
  i.convPosePx(msg); // Parses the message to the convPosePx function in the instant class
}

// Returns whether a defined point is a frontier cell or not
bool isFrontier(cv::Point2f pt) {
  int px = latest.img_.at<uchar>(pt.y, pt.x); // Extracts the pixel color from the queried cell

  if (px == 255) {                            // True if white cell
    // Creates eight point objects, each a different adjacent cell to the cell queried
    cv::Point2f neighbour1(pt.x + 1, pt.y);
    cv::Point2f neighbour2(pt.x + 1, pt.y + 1);
    cv::Point2f neighbour3(pt.x + 1, pt.y - 1);
    cv::Point2f neighbour4(pt.x - 1, pt.y);
    cv::Point2f neighbour5(pt.x - 1, pt.y + 1);
    cv::Point2f neighbour6(pt.x - 1, pt.y - 1);
    cv::Point2f neighbour7(pt.x, pt.y + 1);
    cv::Point2f neighbour8(pt.x, pt.y - 1);

    // Tests if any adjacent cells are grey
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
      return true; // If an adjacent cell is grey, the queried cell is a frontier cell
    }
  }
  return false;    // Otherwise its not
}

// Tests if one distance is greater than another for a sort function
bool sortByDist(const pixel& lhs, const pixel& rhs)
{
  return lhs.distance < rhs.distance;
}

// Sorts all the frontier pixels so that the first one has the smallest distance
void sortFrontierPixels()
{
  sort(frontiers.begin(), frontiers.end(), sortByDist);
}

// Tests if one potential goal cell has more visible frontier cells than another for a sort function
bool sortByViewableFrontiers(const goalPx& lhs, const goalPx& rhs)
{
  return lhs.visibleFrontiers.size() > rhs.visibleFrontiers.size();
}

bool sortByDistGoal(const goalPx& lhs, const goalPx& rhs)
{
  return lhs.p.distance < rhs.p.distance;
}

// Sorts all the possible goal cells so that the one with the most visible frontier cells is at the front. When there is a tie, the closest will be at the front
void sortGoalCandidates()
{
  sort(possiblegoalPx.begin(), possiblegoalPx.end(), sortByViewableFrontiers);
  unsigned int mostFrontiers = possiblegoalPx.at(0).viewablePixels.size();

  for (unsigned i = 0; i != possiblegoalPx.size(); i++) {
    if (possiblegoalPx.at(i).viewablePixels.size() != mostFrontiers) {
      possiblegoalPx.at(i).p.distance  = 1000;
      possiblegoalPx.at(i).p.distancex = 1000;
      possiblegoalPx.at(i).p.distancey = 1000;
    }
  }
  sort(possiblegoalPx.begin(), possiblegoalPx.end(), sortByDistGoal);
}

// Tests is a specified point is a possible goal cell
void addPossiblepxPose(int x, int y, cv::Point2f pt)
{
  if (oldImg.at<uchar>(pt.y, pt.x) == 255) { // A goal cell must be in known space so let's test for that
    goalPx pxPose;                           // Create a pixel pose object
    pxPose.p.x = pt.x;
    pxPose.p.y = pt.y;

    // These if statements determine what cells would be viewable from the canditates position.
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

      else if (y < pt.y) { buf.empty(); // Empty the buffer since we are done with these readings
                           pxPose.bearing = 135.0;
                           pxPose.viewablePixels.push(cv::Point2f(x, y));
                           pxPose.viewablePixels.push(cv::Point2f(x + 1, y));
                           pxPose.viewablePixels.push(cv::Point2f(x, y + 1)); }
      else {
        pxPose.bearing = 180.0;
        pxPose.viewablePixels.push(cv::Point2f(x, y));
        pxPose.viewablePixels.push(cv::Point2f(x, y + 1));
        pxPose.viewablePixels.push(cv::Point2f(x, y - 1));
      }
    }

    // Test how many viewable cells are frontier cells and if they are push them into the data structure
    while (!pxPose.viewablePixels.empty()) {
      cv::Point2f t = pxPose.viewablePixels.front();

      if (isFrontier(t)) pxPose.visibleFrontiers.push(t);
      pxPose.viewablePixels.pop();
    }

    // Push the canditate pose into a data structure for later use
    possiblegoalPx.push_back(pxPose);
  }
}

// Function for determining the goal cell once the closest frontier cell has been found
void computegoalPx()
{
  pixel p = frontiers[0]; buf.empty(); // Empty the buffer since we are done with these readings

  int x = p.x;
  int y = p.y;

  // Add adjacent cells into a queue
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
    addPossiblepxPose(x, y, neighbours.front());                       // Check neighbour cells to see if they are viable poses
    neighbours.pop();
  }
  sortGoalCandidates();                                                // Sort the candidate cells by number of viewable frontier cells
  goal = possiblegoalPx.front();                                       // The goal pose pixel will be the front
  std::cout << "Goal Pixel- x: " << goal.p.x << " y: " << goal.p.y <<
  " Visible frontiers: " << goal.visibleFrontiers.size() << std::endl; // print out info about the next goal pose pixel
}

// Callback for image subsriber
void callbackImg(const sensor_msgs::ImageConstPtr& msg)
{
  inst_mutex_.lock(); // Lock the mutex for the instant

  // Copy the image into the instant
  if (sensor_msgs::image_encodings::isColor(msg->encoding)) i.currentImgPtr_ = cv_bridge::toCvCopy(msg, enc::BGR8);
  else i.currentImgPtr_ = cv_bridge::toCvCopy(msg, enc::MONO8);
  i.storeCVImg();       // Store the image as an open cv image
  inst_mutex_.unlock(); // unlock the mutex
}

void bufTh()
{
  ros::Rate rate_limiter(1.0); // Limit the buffering rate to 1Hz to prevent unessesary constant polling

  while (ros::ok()) {          // Loop while ros::ok returns true
    inst_mutex_.lock();        // Lock the instant
    buf_mutex_.lock();         // Lock the buffer
    buf.push(i);               // Push the latest instant onto the buffer
    inst_mutex_.unlock();      // Unlock the instant
    buf_mutex_.unlock();       // Unlock the buffer
    rate_limiter.sleep();      // Sleep for the rest of the cycle
  }
}

// Tests every pixel to determine if it is a frontier cell
void findFrontiers() {
  for (int x = 1; x < 200; x++) {
    for (int y = 1; y < 200; y++) {
      cv::Point2f pt(x, y);            // Create a point object

      if (isFrontier(pt)) {            // Test if the point in question is a frontier cell
        pixel frontier;
        frontier.x = x;
        frontier.y = y; buf.empty();   // Empty the buffer since we are done with these readings
        frontiers.push_back(frontier); // Store the frontier cell for later use
      }
    }
  }
}

void findGoal() {
  if ((latest.img_.rows == 200) && (latest.img_.rows == 200)) { // Only find the goal if the image is valid
    oldImg = latest.img_;                                       // store the image
    frontiers.clear();                                          // Clear any existing readings in the frontiers data structure

    // Let's test every pixel to determine if it is a frontier cell
    findFrontiers();

    // Calculate the distance for every fronter between it and the middle pixel (where the robot is)
    for (unsigned int i = 0; i < frontiers.size(); i++) {
      pixel q = frontiers[i];
      q.distancex  = q.x - 100.0;                                                            // X distance
      q.distancey  = q.y - 100.0;                                                            // Y distance
      q.distance   = sqrt(pow(q.distancex, 2) + pow(q.distancey, 2));                        // Square root of the sum of the two above values (pythag)
      frontiers[i] = q;                                                                      // Copy the frontier back into the data structure
    }
    sortFrontierPixels();                                                                    // Sort the frontier pixels by their
    computegoalPx();                                                                         // Calculate the goal posed based of the closest frontier cell
    generateNewImg(oldImg);                                                                  // Generate a new image taking into account the new calculated information
    geometry_msgs::Pose latestPose = pixelToPose(goal);                                      // Calculate the goal pose in global coordiance
    goalPoses.header.stamp    = ros::Time::now();                                            // append timestamp
    goalPoses.header.frame_id = "/path";                                                     // as /path to the header for
    goalPoses.poses.push_back(latestPose);                                                   // pushback the latest pose
    pathPosePub.publish(goalPoses);                                                          // publish to topic
    std::cout << "Goal Pose- x: " << latestPose.position.x << " y: "
              << latestPose.position.y << " Yaw: " << latestPose.orientation.z << std::endl; // Print info about the Goal pose to the console
  }
}

void goalTh()
{
  ros::Rate rate_limiter(1. / 10.); // Limit the update rate to once every ten seconds

  while (ros::ok()) {               // Loop while ros::okay returns true
    buf_mutex_.lock();              // Lock the buffer
    latest = buf.top();             // take the latest reading from the top of the stack
    buf_mutex_.unlock();            // Unlock the buffer
    findGoal();
    buf.empty();                    // Empty the buffer since we are done with these readings
    rate_limiter.sleep();           // Sleep for the remaining cycle
  }
}

// Generates new image and publishes to topic
cv_bridge::CvImage generateNewImg(cv::Mat oldImg)
{
  cv_bridge::CvImage cv_image;                            // Create new image object

  cv::cvtColor(oldImg, cv_image.image, 8);                // The original image is usually in greyscale so we need to convert it to colour
  cv_image.image.at<cv::Vec3b>(100, 100) = { 0, 255, 0 }; // The robot is always in the middle of the image so let's make that pixel green for easy reference

  for (unsigned int i = 0; i < frontiers.size(); i++) {   // All of the possible frontiers are to be shown in yellow
    pixel f = frontiers[i];
    cv_image.image.at<cv::Vec3b>(f.y, f.x) = { 0, 255, 255 };
  }
  goalPx g = possiblegoalPx.front();
  cv_image.image.at<cv::Vec3b>(g.p.y, g.p.x) = { 0, 0, 255 }; // Our goal pose is to be shown in red

  while (!g.visibleFrontiers.empty()) {                       // All of the visible frontier cells from our goal pose are to be shown in blue
    cv::Point2f f = g.visibleFrontiers.front();
    cv_image.image.at<cv::Vec3b>(f) = { 255, 0, 0 };
    g.visibleFrontiers.pop();
  }
  cv_image.encoding = "bgr8";                // Encode the image in bgr8
  cv_image.header   = std_msgs::Header();    // Append the message header
  image_pub_.publish(cv_image.toImageMsg()); // Publish the image
  return cv_image;                           // Return the image
}

// This function takes in a goal pixel and returns a Pose message
geometry_msgs::Pose pixelToPose(goalPx gPx) {
  geometry_msgs::Pose output;
  double xDif = (gPx.p.distancex - 100.0) * 0.1;
  double yDif = (gPx.p.distancey - 100.0) * 0.1;

  output.position.x = latest.x_ + xDif;
  output.position.y = latest.y_ + yDif;
  tf::quaternionTFToMsg(tf::createQuaternionFromYaw(gPx.bearing), output.orientation);
  return output;
}

// Project main
int main(int argc, char **argv)
{
  ros::init(argc, argv, "a5_main");                                        // Initialise the node
  ros::NodeHandle n;                                                       // Init NodeHandle object
  image_transport::ImageTransport it(n);                                   // Declare the ImageTransport object for image publishing
  ros::Subscriber sub1 = n.subscribe("odom", 1000, callbackOdom);          // Odom subscriber
  ros::Subscriber sub2 = n.subscribe("map_image/full", 1000, callbackImg); // Image subscriber
  image_pub_  = it.advertise("map_image/fbe", 1);                          // Image publisher
  pathPosePub = n.advertise<geometry_msgs::PoseArray>("path", 1);          // Goal pose Publisher
  std::thread t1(bufTh);                                                   // Initialise the first thread
  std::thread t2(goalTh);                                                  // Initialise the second thread

  ros::spin();                                                             // Call ros::spin() to start callbacks
  t1.join();                                                               // Join thread 1
  t2.join();                                                               // Join thread 2

  return 0;
}
