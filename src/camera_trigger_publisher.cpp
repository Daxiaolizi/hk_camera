//
// Created by haomo on 25-7-7.
//
#include <ros/ros.h>
#include <std_msgs/Time.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "camera_trigger_publisher");
  ros::NodeHandle nh;
  ros::Publisher trigger_pub = nh.advertise<std_msgs::Time>("/camera_trigger", 10);

  ros::Rate rate(30); // 发布频率为30Hz

  while (ros::ok())
  {
    std_msgs::Time msg;
    msg.data = ros::Time::now(); // 设置当前时间作为触发时间
    trigger_pub.publish(msg);
//    ROS_INFO("Trigger signal sent at %f", msg.data.toSec());
    rate.sleep();
  }

  return 0;
}