#include <gtest/gtest.h>
#include <climits>

#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>
#include "../src/a5_main.h"
#include "../src/instant.h"

TEST(GoalPoseCalc, case1) {
  double mapSize    = 20.0;
  double resolution = 0.1;

  int pixels = (int)mapSize / resolution;

  // Create an OgMap which is a grayscale (mono) image of size pixels
  cv::Mat image = cv::Mat::zeros(pixels, pixels, CV_8UC1);

  cv::rectangle(image, cv::Point2f(0, 0), cv::Point2f(pixels, pixels), cv::Scalar(128, 128, 128), -1, 4, 0); // set all pixels to grey
  cv::rectangle(image, cv::Point2f(50, 50), cv::Point2f(150, 150), cv::Scalar(0, 0, 0), -1, 4, 0);           // make a white square in the middle
  image.at<uchar>(125, 125) = 128;                                                                           // make a random frontier in the white square
  latest.img_               = image;                                                                         // Apply the image
  findGoal();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
