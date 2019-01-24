cmake_minimum_required(VERSION 2.8.3)
project(trivial_controller)

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  roscpp
  roslint
  sensor_msgs
  ackermann_msgs
)

# Add external dependencies here.
# find_package(eigen REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS
    roscpp
    sensor_msgs
    ackermann_msgs
  # Add external dependencies here.
  #DEPENDS eigen
)

###########
## Build ##
###########

include_directories(
  include
  ${Eigen_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

# node executable
add_executable(node
  src/node.cpp
  src/controller.cpp
)
add_dependencies(node
  ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(node
  ${catkin_LIBRARIES}
  ${Eigen_LIBRARIES}
)

# Enable ROS C++ linting.
# Run with: catkin_make roslint_trivial_controller
roslint_cpp()

#############
## Install ##
#############

install(TARGETS node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
install(DIRECTORY launch/
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch)
