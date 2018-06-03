#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_publisher");

  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("image_topic", 1);

  ros::NodeHandle pnh("~");
  std::string     imageName;

  if (!pnh.getParam("image", imageName)) {
    ROS_ERROR(
      "No image provided \n RUN AS: rosrun opencv_example image_publisher _image:=path/to/image.jpg");
  }

  cv::Mat image = cv::imread(imageName.c_str(), CV_LOAD_IMAGE_GRAYSCALE);

  ros::Rate loop_rate(5);

  ROS_INFO("Start publishing image");

  while (nh.ok() && image.cols > 0 && image.rows > 0) {
    sensor_msgs::ImagePtr msg =
      cv_bridge::CvImage(std_msgs::Header(), "mono8", image).toImageMsg();
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
