#ifndef __controller_h_
#define __controller_h_

#include <ros/ros.h>
#include "geometry_msgs/Twist.h"

#include <fstream>
#include <string>




geometry_msgs::Twist twist;
int state;
std::string last_state = "stop";

std::string stop = "stop";
std::string forward = "nofo";
std::string backforward = "noba";
std::string turnleft = "nole";
std::string turnright = "nori";
std::string highforward = "hifo";
std::string highbackforward = "hiba";
std::string highturnleft = "hile";
std::string highturnright = "hiri";

int ReadState();

#endif
