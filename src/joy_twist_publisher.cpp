#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

#include <cmath>
#include <bits/stdc++.h>

geometry_msgs::Twist cmd_vel;
void joy_callback(const sensor_msgs::Joy& joy_msg)
{

  float angle = std::atan2(joy_msg.axes[0], joy_msg.axes[1]) / M_PI * 180.0;
  float vel = std::sqrt(std::pow(joy_msg.axes[1], 2) + std::pow(joy_msg.axes[0], 2));

  if(std::abs(angle) > 90){
    vel *= -1.0;

    // float sign = angle / std::abs(angle);
    // angle = (std::abs(angle) - 180.0) * sign;

    if(angle > 0){
      angle = -180 + angle;
    }else{
      angle = 180 + angle;
    }
  }

  cmd_vel.linear.x = vel;
  cmd_vel.angular.z = angle;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "basic_twist_publisher");
  ros::NodeHandle nh;
  ros::Publisher cmd_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Subscriber joy_sub = nh.subscribe("joy", 10, joy_callback);

  ros::Rate loop_rate(10);
  while (ros::ok())
    {
      cmd_pub.publish(cmd_vel);
      ros::spinOnce();
      loop_rate.sleep();
    }
  return 0;
}
