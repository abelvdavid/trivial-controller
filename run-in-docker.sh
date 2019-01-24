#!/bin/bash

CMD="
apt-get update &&
rosdep install --from-paths src --ignore-src -r -y &&
catkin_make roslint_trivial_controller &&
catkin_make &&
source devel/setup.bash &&
roslaunch trivial_controller controller.launch
"

docker run --rm -ti \
    --name trivial_controller \
    -v $(pwd)/:/catkin_ws/src/trivial_controller \
    -w /catkin_ws \
    ros:kinetic-ros-core \
        bash -c "$CMD"
