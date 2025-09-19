#include <chrono>
#include <cstdio>
#include <memory>
#include <utility>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class MyNode : public rclcpp::Node
{
    public:

    MyNode();
    
    

    private:
    Mat i=imread("/home/david/intern_ws/opencv/day1/src/hw2_package/src/test.png");
    
    rclcpp::Publisher<sensor_msgs::msg::Image> P_I;
    void publish(int k);

};