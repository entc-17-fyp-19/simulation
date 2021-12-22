#include "ros/ros.h"
#include <cmath>
#include <geometry_msgs/Quaternion.h>
#include <sensor_msgs/Imu.h>
#include <tf/tf.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <vector>

float start_x = 0;
float start_y = 0;
float end_x = 5;
float end_y = -10;

std::vector<std::vector<int>> trajectory {{0, 0, 0}, {5, -10, 0}};

float current_x = 0;
float current_y = 0;

float perp_x = 0;
float perp_y = 0;

const float L1 = 0.5;
const double PI = 3.1415926535897932;

ros::Publisher arc_angle_data_pub;
ros::Publisher path_pub;

nav_msgs::Path path;
geometry_msgs::PoseStamped pose;
nav_msgs::Odometry current_loc;

double heading_angle = 0;

float* calculate_path(){
  static float data[2]; //{slope, intercept}
  float angle;
  if((end_x - start_x) < 0){
    angle = atan((end_y - start_y)/(end_x - start_x));
    angle = angle + PI;
  }else if((end_x - start_x) == 0){
    if((end_y - start_y) < 0){
      angle = (3/2)*PI;
    }else{
      angle = PI/2;
    }
  }else{
    angle = atan((end_y - start_y)/(end_x - start_x));
    if((end_y - start_y) < 0){
      angle = 2*PI + angle;
    }
  }
  data[0] = angle;
  data[1] = start_y - start_x * data[0];

  return data;
}

float* calculate_perp_loc(){
  static float perp_loc[2]; // {x,y}
  float *path;

  path = calculate_path();
  perp_loc[0] = (current_y + (current_x/(*path)) - *(path+1))/(*path + 1/(*path));
  perp_loc[1] = current_y + (current_x/(*path)) - (current_y + (current_x/(*path)) - *(path+1))/(1 + pow(*path,2));

  return perp_loc;
}

float* calculate_end_point(){
  static float end_point[2]; //{x,y}
  float *path;
  float *perp_point;
  float len = 0;
  float d = 0;

  perp_point = calculate_perp_loc();
  path = calculate_path();
  d = sqrt(pow(*perp_point - current_x, 2) + pow(*(perp_point+1) - current_y, 2));
  len = sqrt(pow(L1,2) - pow(d,2));
  end_point[0] = *perp_point + len * cos(*path);
  end_point[1] = *(perp_point+1) + len * sin(*path);

  return end_point;
}

float calculate_rotation_dir(){
  float *end_point;
  end_point = calculate_end_point();
  float v1[2] = {current_x - *end_point, current_y - *(end_point+1)};
  float v2[2] = {start_x - *end_point, start_y - *(end_point+1)};

  float cross_prod_val = v1[0]*v2[1] - v1[1]*v2[0];

  return cross_prod_val;
}

void calculate_arc_angle(){
  float *path;
  float *perp_point;
  float d;
  float n1;
  float n2;
  float dir = calculate_rotation_dir();

  path = calculate_path();

  n2 = heading_angle - *path;
  perp_point = calculate_perp_loc();
  d = sqrt(pow(*perp_point - current_x, 2) + pow(*(perp_point+1) - current_y, 2));
  n1 = asin(d/L1);

  if (dir > 0){
    arc_angle_data_pub.publish(tf::createQuaternionMsgFromYaw((double)((-1)*(n1+n2))));
  }else{
    arc_angle_data_pub.publish(tf::createQuaternionMsgFromYaw((double)(n1+n2)));
  }

}

void visualize_path(){
  path.header.stamp = ros::Time::now();
  path.header.frame_id = "map";

  for(int i=0; i<trajectory.size(); i++){
    pose.header.stamp = ros::Time::now();
    pose.header.frame_id = "map";
    pose.pose.position.x = trajectory[i][0];
    pose.pose.position.y = trajectory[i][1];
    pose.pose.position.z = trajectory[i][2];
    pose.pose.orientation.x = 0;
    pose.pose.orientation.y = 0;
    pose.pose.orientation.z = 0;
    pose.pose.orientation.w = 0;

    path.poses.push_back(pose);
  }

  path_pub.publish(path);

}

void get_heading_angle(const sensor_msgs::Imu::ConstPtr& msg){
  geometry_msgs::Quaternion quat;
  quat.x = msg->orientation.x;
  quat.y = msg->orientation.y;
  quat.z = msg->orientation.z;
  quat.w = msg->orientation.w;

  heading_angle = tf::getYaw(quat);

  // ROS_INFO_STREAM("heading_angle" << heading_angle);
}

void get_current_loc(const nav_msgs::Odometry& msg){
  current_x = msg.pose.pose.position.x;
  current_y = msg.pose.pose.position.y;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "navigate");
  ros::NodeHandle node;

  ros::Subscriber imu_sub = node.subscribe("/imu", 100, get_heading_angle);
  ros::Subscriber loc_sub = node.subscribe("/odometry/filtered", 100, get_current_loc);
  arc_angle_data_pub = node.advertise<geometry_msgs::Quaternion>("/arc_angle", 100);
  path_pub = node.advertise<nav_msgs::Path>("/path", 100);

  ros::Rate loop_rate(30);


  while(ros::ok()){
    visualize_path();
    calculate_arc_angle();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
