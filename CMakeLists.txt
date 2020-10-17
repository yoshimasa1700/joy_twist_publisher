cmake_minimum_required(VERSION 3.0.0)
project(joy_twist_publisher)
find_package(catkin REQUIRED)

catkin_metapackage()

find_package(catkin REQUIRED COMPONENTS roscpp geometry_msgs sensor_msgs)
catkin_package(
  INCLUDE_DIRS
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp geometry_msgs sensor_msgs)

include_directories(
  /usr/local/include
  ${catkin_INCLUDE_DIRS})

add_executable(
  ${PROJECT_NAME}
  src/joy_twist_publisher.cpp)

link_directories(
  /usr/local/lib)

target_link_libraries(
  ${PROJECT_NAME}
  ${catkin_LIBRARIES}
  )
