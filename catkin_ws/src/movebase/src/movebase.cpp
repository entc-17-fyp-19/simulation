#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float64.h"
#include <cmath>
#include <geometry_msgs/Quaternion.h>
#include <tf/tf.h>

const double FRONT_LEN = 0.59;
const double WHEEL_RADIUS = 0.16;
const double WHEEL_BASE = 0.5;
const double L1 = 0.5;

double angular_z = 0;
float linear_z = 0;
double angle = 0;
double left_motor_speed = 0; //rads-1
double right_motor_speed = 0; //rads-1

double dis_from_center = 0;
double omega = 0;

double heading_vel = 2; //ms-1


void arc_angle_callback(const geometry_msgs::Quaternion& msg)
{
  angle = tf::getYaw(msg);

}

void cal_wheel_vel()
{
  if (angle != 0){
    dis_from_center = L1/(2*(sin(angle))); //from rotating center to base center (2 x angle/2) = angle
    omega = heading_vel/dis_from_center;

    if(dis_from_center > 0){
      left_motor_speed = ((dis_from_center + WHEEL_BASE/2) * omega)/WHEEL_RADIUS;
      right_motor_speed = ((dis_from_center - WHEEL_BASE/2) * omega)/WHEEL_RADIUS;
    }else{
      right_motor_speed = (((-1)*dis_from_center + WHEEL_BASE/2) * (-1)* omega)/WHEEL_RADIUS;
      left_motor_speed = (((-1)*dis_from_center - WHEEL_BASE/2) * (-1)* omega)/WHEEL_RADIUS;
    }
  }else{
    left_motor_speed = heading_vel/WHEEL_RADIUS;
    right_motor_speed = heading_vel/WHEEL_RADIUS;
  }
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "movebase");
  ros::NodeHandle n;

  ros::Subscriber sub_angle = n.subscribe("/arc_angle", 100, arc_angle_callback);
  ros::Publisher pub_back_LW = n.advertise<std_msgs::Float64>("/robot_platform_control/back_LW_joint_velocity_controller/command", 100);
  ros::Publisher pub_back_RW = n.advertise<std_msgs::Float64>("/robot_platform_control/back_RW_joint_velocity_controller/command", 100);

  ros::Rate rate(50);

  while (ros::ok())
  {
    std_msgs::Float64 left_msg;
    std_msgs::Float64 right_msg;

    cal_wheel_vel();

    left_msg.data = left_motor_speed;
    right_msg.data = right_motor_speed;

    pub_back_LW.publish(left_msg);
    pub_back_RW.publish(right_msg);

    ros::spinOnce();

    rate.sleep();
  }
  ros::spin();
  return 0;
}
