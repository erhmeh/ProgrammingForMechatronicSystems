#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

void printHistogram(const std::vector<int> &histogram, int bin_width) {

    int max_val = 0;
    for (std::vector<int>::const_iterator it = histogram.begin(); it != histogram.end(); it++) {
        max_val = (*it > max_val) ? *it : max_val;
    }
    int hist_scale = max_val / 60;

    for (int i = 0; i<histogram.size(); i++) {
        std::cout << i*bin_width << " - " << (i+1)*bin_width  << ":";
        for (int count = 0; count<histogram.at(i); count+=hist_scale) {
            std::cout << "|";
        }
        std::cout << std::endl;
    }
}

std::vector<int> computeHistogram(const cv::Mat &image, int bin_width, int image_depth) {

    int num_bins = (image_depth / bin_width)+1;

    std::vector<int> histogram(num_bins,0);

    for (int i = 0; i<image.rows; i++) {
        for (int j = 0; j<image.cols; j++) {
            histogram.at(image.at<uchar>(i,j)/bin_width)++;
        }
    }
    return histogram;
}

void imageCallback(const sensor_msgs::ImageConstPtr& msg) {
    ROS_INFO_STREAM("Received image: height:" << msg->height << ", width:" << msg->width);
    const int bin_width = 10;
    const int image_depth = 256;
    cv_bridge::CvImageConstPtr cv_img_ptr = cv_bridge::toCvShare(msg);

    std::vector<int> histogram = computeHistogram(cv_img_ptr->image, bin_width, image_depth);

    printHistogram(histogram, bin_width);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "image_subscriber");

    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    image_transport::Subscriber sub = it.subscribe("image_topic", 1, imageCallback);

    ros::spin();
}
