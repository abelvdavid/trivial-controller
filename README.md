# trivial-controller

Boilerplate for C++ ROS controllers.

This repo can be used to create driving controllers for ROS-based ackermann steering robots.

- static frequency loop (40HZ) sends driving commands
- scan (2D lidar) callback for calculating desired command
- code ROS C++ linted

# Quick start

To compile, lint and run use
```
./run-in-docker.sh
```

To connect to ROS
```
docker exec -ti trivial_controller bash -c "source devel/setup.bash && bash"
```
```
rosnode list
rostopic list
```

# Legal

Based on "racecar_potential_field_controller" authored by [Michael Boulet](https://github.com/mboulet).
