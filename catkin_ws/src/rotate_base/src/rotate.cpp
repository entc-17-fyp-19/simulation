#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <cmath>


const double WHEEL_BASE = 0.5;
const double FRONT_LEN = 0.59;

double angle = 0;
double right_angle = 0;
double left_angle = 0;
double len_from_center = 0;

void rotate_angle_callback(const std_msgs::Float64& msg)
{
  angle = msg.data;
  len_from_center = FRONT_LEN/tan(angle);
  right_angle = atan(FRONT_LEN/(len_from_center + WHEEL_BASE/2));
  left_angle = atan(FRONT_LEN/(len_from_center - WHEEL_BASE/2));

  // ROS_INFO_STREAM("right_angle" << right_angle);
  // ROS_INFO_STREAM("left_angle" << left_angle);
  // ROS_INFO_STREAM("angle" << angle);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "rotate_base_node");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/rotate_angle", 100, rotate_angle_callback);
  ros::Publisher pub_front_LW_con = n.advertise<std_msgs::Float64>("/robot_platform_control/front_LW_con_joint_position_controller/command", 100);
  ros::Publisher pub_front_RW_con = n.advertise<std_msgs::Float64>("/robot_platform_control/front_RW_con_joint_position_controller/command", 100);

  ros::Rate rate(50);

  while (ros::ok())
  {
    std_msgs::Float64 msgLeft;
    std_msgs::Float64 msgRight;
    msgLeft.data = left_angle;
    msgRight.data = right_angle;

    pub_front_LW_con.publish(msgLeft);
    pub_front_RW_con.publish(msgRight);
    ros::spinOnce();

    rate.sleep();
  }
  ros::spin();

  return 0;
}
