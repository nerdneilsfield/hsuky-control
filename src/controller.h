#ifndef __controller_h_
#define __controller_h_

#include <ros/ros.h>
#include "geometry_msgs/Twist.h"

#include <fstream>
#include <string>

geometry_msgs::Twist twist;
int state;
std::string last_state;
int ReadState();

#endif