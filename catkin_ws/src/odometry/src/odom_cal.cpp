#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include "std_msgs/Float64.h"
#include "sensor_msgs/JointState.h"
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
// #include <tf2/LinearMath/Quaternion.h>
#include <tf/transform_broadcaster.h>
#include <cmath>


ros::Publisher odom_data_pub;
ros::Publisher odom_data_pub_quat;
nav_msgs::Odometry odomNew;
nav_msgs::Odometry odomOld;

geometry_msgs::Quaternion odom_quat;
geometry_msgs::TransformStamped odom_trans;


const double initialX = 0.0;
const double initialY = 0.0;
const double initialTheta = 0.0;
const double PI = 3.1415926535897932;

const double WHEEL_RADIUS = 0.16;
const double WHEEL_BASE = 0.5;
const double FRONT_LEN = 0.59;

double distanceLeft = 0;
double distanceRight = 0;
double steer_angle = 0;
double total_rotation_angle = 0;

using namespace std;

void rotate_angle_callback(const std_msgs::Float64& msg)
{
  steer_angle = msg.data;
}

void joint_data_callback(const sensor_msgs::JointState& msg){
  static double last_left_radians = 0;
  static double last_right_radians = 0;

  double left_radians = msg.position[0] - last_left_radians;
  double right_radians = msg.position[1] - last_right_radians;

  distanceLeft = WHEEL_RADIUS * left_radians;
  distanceRight = WHEEL_RADIUS * right_radians;

  last_left_radians = msg.position[0];
  last_right_radians = msg.position[1];
  // ROS_INFO_STREAM("last_left_radians" << last_left_radians);
  // ROS_INFO_STREAM("last_right_radians" << last_right_radians);
}

void update_odom(){
  static tf::TransformBroadcaster odom_broadcaster;

  double cycleDistance = (distanceRight + distanceLeft)/2;
  double cycleAngle = ((distanceRight - distanceLeft)/WHEEL_BASE);
  double avgAngle = cycleAngle/2 + odomOld.pose.pose.orientation.z;

  total_rotation_angle += cycleAngle;

  if(avgAngle > PI){
    avgAngle -= 2*PI;
  }else if(avgAngle < -PI){
    avgAngle += 2*PI;
  }

  //new pose Data
  odomNew.pose.pose.position.x = odomOld.pose.pose.position.x + cycleDistance * cos(avgAngle);
  odomNew.pose.pose.position.y = odomOld.pose.pose.position.y + cycleDistance * sin(avgAngle);
  odomNew.pose.pose.orientation.z = odomOld.pose.pose.orientation.z + cycleAngle;

  if(
    isnan(odomNew.pose.pose.position.x) ||
    isnan(odomNew.pose.pose.position.y) ||
    isnan(odomNew.pose.pose.orientation.z)){
      odomNew.pose.pose.position.x = odomOld.pose.pose.position.x;
      odomNew.pose.pose.position.y = odomOld.pose.pose.position.y;
      odomNew.pose.pose.orientation.z = odomOld.pose.pose.orientation.z;
    }

  if (odomNew.pose.pose.orientation.z > PI){
    odomNew.pose.pose.orientation.z -= 2 * PI;
  }
  else if (odomNew.pose.pose.orientation.z < -PI){
    odomNew.pose.pose.orientation.z += 2 * PI;
  }

  // velocity calculation
  odomNew.header.stamp = ros::Time::now();
  double velocity = 0;
  if (odomNew.header.stamp.toSec() == odomOld.header.stamp.toSec()){
    velocity = 0;
  }else{
    velocity = (cycleDistance/(odomNew.header.stamp.toSec() - odomOld.header.stamp.toSec()));
  }

  odomNew.twist.twist.linear.x = velocity*cos(total_rotation_angle);
  odomNew.twist.twist.linear.y = velocity*sin(total_rotation_angle);
  // odomNew.twist.twist.angular.z =  cycleAngle/(odomNew.header.stamp.toSec() - odomOld.header.stamp.toSec());
  odomNew.twist.twist.angular.z = (velocity/FRONT_LEN)*tan(steer_angle);

  odomOld.pose.pose.position.x = odomNew.pose.pose.position.x;
  odomOld.pose.pose.position.y = odomNew.pose.pose.position.y;
  odomOld.pose.pose.orientation.z = odomNew.pose.pose.orientation.z;
  odomOld.header.stamp = odomNew.header.stamp;


  // set TF Data
  odom_quat = tf::createQuaternionMsgFromYaw(avgAngle);
  odom_trans.header.stamp = odomNew.header.stamp;
  odom_trans.header.frame_id = "odom";
  odom_trans.child_frame_id = "base_footprint";
  odom_trans.transform.translation.x = odomNew.pose.pose.position.x;
  odom_trans.transform.translation.y = odomNew.pose.pose.position.y;
  odom_trans.transform.translation.z = 0.0;
  odom_trans.transform.rotation = odom_quat;

  odom_broadcaster.sendTransform(odom_trans);
  odom_data_pub.publish(odomNew);

}

int main(int argc, char **argv)
{
  odomNew.header.frame_id = "odom";
  odomNew.child_frame_id = "base_footprint";
  odomNew.pose.pose.position.z = 0;
  odomNew.pose.pose.orientation.x = 0;
  odomNew.pose.pose.orientation.y = 0;
  odomNew.twist.twist.linear.x = 0;
  odomNew.twist.twist.linear.y = 0;
  odomNew.twist.twist.linear.z = 0;
  odomNew.twist.twist.angular.x = 0;
  odomNew.twist.twist.angular.y = 0;
  odomNew.twist.twist.angular.z = 0;
  odomOld.pose.pose.position.x = initialX;
  odomOld.pose.pose.position.y = initialY;
  odomOld.pose.pose.orientation.z = initialTheta;

  ros::init(argc, argv, "odom_data_pub");
  ros::NodeHandle node;

  ros::Subscriber joint_data = node.subscribe("/robot_platform_control/joint_states", 100, joint_data_callback);
  ros::Subscriber sub = node.subscribe("/rotate_angle", 100, rotate_angle_callback);
  odom_data_pub = node.advertise<nav_msgs::Odometry>("odom", 100);

  ros::Rate loop_rate(30);

  while(ros::ok()){
    update_odom();

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;

}
