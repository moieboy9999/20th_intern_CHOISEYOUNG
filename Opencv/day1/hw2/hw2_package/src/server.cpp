#include"../include/hw2_package/server.hpp"

MyNode::MyNode() : Node("p"){
    P_I= this->create_publisher<sensor_msgs::msg::Image>con
}
void MyNode::publish(int k){
    if(k==1){
        publish(i);
    }
}