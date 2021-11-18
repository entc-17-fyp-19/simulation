#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float64.h"

double angular_z = 0;
float linear_z = 0;

void cmd_vel_callback(const geometry_msgs::Twist& msg)
{
  angular_z = msg.angular.z;
  // ROS_INFO_STREAM("Data" << msg);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "robot_ctrl");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/cmd_vel", 100, cmd_vel_callback);
  ros::Publisher pub_back_LW = n.advertise<std_msgs::Float64>("/robot_platform_control/back_LW_joint_velocity_controller/command", 100);
  ros::Publisher pub_back_RW = n.advertise<std_msgs::Float64>("/robot_platform_control/back_RW_joint_velocity_controller/command", 100);
  ros::Publisher pub_front_LW = n.advertise<std_msgs::Float64>("/robot_platform_control/front_LW_con_joint_position_controller/command", 100);
  ros::Publisher pub_front_RW = n.advertise<std_msgs::Float64>("/robot_platform_control/front_RW_con_joint_position_controller/command", 100);
  ros::Rate rate(50);

  while (ros::ok())
  {
    std_msgs::Float64 msg;
    std_msgs::Float64 zero;
    msg.data = angular_z;
    zero.data = 0;
    pub_back_LW.publish(msg);
    pub_back_RW.publish(msg);
    pub_front_LW.publish(zero);
    pub_front_RW.publish(zero);
    ros::spinOnce();

    rate.sleep();
  }
  ros::spin();
  return 0;
}
