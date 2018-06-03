#include "drawing_tools.h"



void drawing_tools::drawRedDot(cv::Mat &image)
{
        cv::circle(image, cv::Point((image.rows/2), (image.cols/2)), 7, CV_RGB(255, 0, 0), -1);
}
