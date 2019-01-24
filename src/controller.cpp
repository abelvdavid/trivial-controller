// Copyright XXXX author
#include "trivial_controller/controller.h"


namespace trivial_controller
{

Controller::Controller(ros::NodeHandle nh)
{
  vel_pub_ = nh.advertise<ackermann_msgs::AckermannDriveStamped>("navigation", 10);
  scan_sub_ = nh.subscribe("/scan", 10, &Controller::scanCallback, this);
  timer_ = nh.createTimer(ros::Duration(1.0/40.0), &Controller::timerCallback, this);
}

void Controller::timerCallback(const ros::TimerEvent& event)
{
  static bool updating(false);
  ackermann_msgs::AckermannDriveStamped::Ptr cmd(new ackermann_msgs::AckermannDriveStamped);

  // Report status.
  if (ros::Time::now() - last_cmd_.header.stamp > ros::Duration(0.1))
  {
    if (updating)
    {
      ROS_WARN("trivial_controller not updating navigation command");
      updating = false;
    }
    return;
  }
  else if (!updating)
  {
    ROS_INFO("trivial_controller updating navigation command");
    updating = true;
  }

  // Publish latest cmd.
  *cmd = last_cmd_;
  vel_pub_.publish(cmd);
}

void Controller::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
  assert(scan && scan->ranges.size() > 0);

  // TODO(xxxx): add actual code here.

  // Just use static values as example.
  last_cmd_.header.stamp = scan->header.stamp;
  last_cmd_.drive.speed = 0.25;
  last_cmd_.drive.steering_angle = 0.2;
}

}  // namespace trivial_controller
