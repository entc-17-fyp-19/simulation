#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float64.h"
#include <cmath>

const double FRONT_LEN = 0.59;
const double WHEEL_RADIUS = 0.16;
const double WHEEL_BASE = 0.5;

double angular_z = 0;
float linear_z = 0;
double angle = 0;
double left_motor_speed = 0; //rads-1
double right_motor_speed = 0; //rads-1

double dis_from_center = 0;
double omega = 0;

double heading_vel = 0;

void cmd_vel_callback(const geometry_msgs::Twist& msg)
{
  angular_z = msg.angular.z;

  // just as an example; wanted to get a velocity value from keyboard
  heading_vel = WHEEL_RADIUS * angular_z;
  // ROS_INFO_STREAM("Data" << msg);
}

void rotate_angle_callback(const std_msgs::Float64& msg)
{
  angle = msg.data;

}

void cal_wheel_vel()
{
  if (angle != 0){
    dis_from_center = FRONT_LEN/tan(angle);
    omega = (heading_vel * cos(angle))/dis_from_center;

    if(dis_from_center > 0){
      left_motor_speed = ((dis_from_center - WHEEL_BASE/2) * omega)/WHEEL_RADIUS;
      right_motor_speed = ((dis_from_center + WHEEL_BASE/2) * omega)/WHEEL_RADIUS;
    }else{
      right_motor_speed = (((-1)*dis_from_center - WHEEL_BASE/2) * (-1)* omega)/WHEEL_RADIUS;
      left_motor_speed = (((-1)*dis_from_center + WHEEL_BASE/2) * (-1)* omega)/WHEEL_RADIUS;
    }
  }else{
    left_motor_speed = heading_vel/WHEEL_RADIUS;
    right_motor_speed = heading_vel/WHEEL_RADIUS;
  }
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "keyboard_ctrl_node");
  ros::NodeHandle n;

  ros::Subscriber sub_vel = n.subscribe("/cmd_vel", 100, cmd_vel_callback);
  ros::Subscriber sub_angle = n.subscribe("/rotate_angle", 100, rotate_angle_callback);
  ros::Publisher pub_front_LW = n.advertise<std_msgs::Float64>("/robot_platform_control/front_LW_joint_velocity_controller/command", 100);
  ros::Publisher pub_front_RW = n.advertise<std_msgs::Float64>("/robot_platform_control/front_RW_joint_velocity_controller/command", 100);
  // ros::Publisher pub_front_LW_con = n.advertise<std_msgs::Float64>("/robot_platform_control/front_LW_con_joint_position_controller/command", 100);
  // ros::Publisher pub_front_RW_con = n.advertise<std_msgs::Float64>("/robot_platform_control/front_RW_con_joint_position_controller/command", 100);

  ros::Rate rate(50);

  // inital pub
  // std_msgs::Float64 zero;
  // zero.data = 0;
  // pub_front_LW_con.publish(zero);
  // pub_front_RW_con.publish(zero);

  while (ros::ok())
  {
    std_msgs::Float64 left_msg;
    std_msgs::Float64 right_msg;

    cal_wheel_vel();

    left_msg.data = left_motor_speed;
    right_msg.data = right_motor_speed;

    pub_front_LW.publish(left_msg);
    pub_front_RW.publish(right_msg);

    ros::spinOnce();

    rate.sleep();
  }
  ros::spin();
  return 0;
}
