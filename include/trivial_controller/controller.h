// Copyright XXXX author
#ifndef TRIVIAL_CONTROLLER_CONTROLLER_H
#define TRIVIAL_CONTROLLER_CONTROLLER_H

#include <string>

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <ackermann_msgs/AckermannDriveStamped.h>

namespace trivial_controller
{

class Controller
{
public:
  explicit Controller(ros::NodeHandle nh);

private:
  // state
  ackermann_msgs::AckermannDriveStamped last_cmd_;

  // ROS services
  ros::Publisher vel_pub_;
  ros::Subscriber scan_sub_;
  ros::Timer timer_;

  // ROS callbacks
  void timerCallback(const ros::TimerEvent& event);
  void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan);
};

}  // namespace trivial_controller

#endif  // TRIVIAL_CONTROLLER_CONTROLLER_H
