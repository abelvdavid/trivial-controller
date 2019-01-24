// Copyright XXXX author
#include <boost/shared_ptr.hpp>
#include <ros/ros.h>

#include "trivial_controller/controller.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "trivial_controller");
  ros::NodeHandle nh;

  boost::shared_ptr<trivial_controller::Controller> controller;
  controller.reset(new trivial_controller::Controller(nh));

  ros::spin();

  return 0;
}
