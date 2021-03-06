cmake_minimum_required(VERSION 3.0.2)
project(ign_plugins)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

find_package(ignition-cmake2 REQUIRED)
find_package(ignition-plugin1 REQUIRED COMPONENTS register)
set(IGN_PLUGIN_VER ${ignition-plugin1_VERSION_MAJOR})
find_package(ignition-gazebo3 REQUIRED)
add_library(OdomOmnidirectional SHARED OdomOmnidirectional.cc)
set_property(TARGET OdomOmnidirectional PROPERTY CXX_STANDARD 17)
target_link_libraries(OdomOmnidirectional
  PRIVATE ignition-plugin${IGN_PLUGIN_VER}::ignition-plugin${IGN_PLUGIN_VER}
  PRIVATE ignition-gazebo3::ignition-gazebo3)