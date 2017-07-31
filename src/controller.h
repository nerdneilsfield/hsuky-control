#include <ros/ros.h>
#include "geometry_msgs/Twist.h"

#include <fstream>
#include <string>

int readState()
{
    std::ifstream ifs("/var/ros/controller");
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>() ));
    if content.compare("forward") {

    }
    if content.compare("backforward")
    {

    }
    if content.compare("turnleft")
    {

    }
    if content.compare("turnright")
    {
	
    }
    if content.compare("highforward")
    {}
    if content.compare("highback")
    {}

}
