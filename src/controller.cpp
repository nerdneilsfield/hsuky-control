#include "controller.h"

//From file "/var/ros/controller" read the state and return
int ReadState()
{  
    // read the file
    std::ifstream ifs("/var/ros/controller");
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>() ));
    // if state changed, write to console.
    //ROS_INFO("%s" ,content.c_str());
    content = content.substr(0,4);
    if (content.compare(last_state) != 0)
    {
        ROS_INFO("%s" ,content.c_str());
	last_state = content;
    }
    //ROS_INFO("%s" ,content.c_str());
    //ROS_INFO("%ld", forward.length());
    //ROS_INFO("%ld", content.length());
    // from state to statecode
    if ( content == stop ){
        return 0;
    }
    if(  content == forward  ){
        return 1;
    }
    if (content == backforward)
    {
        return 2;
    }
    if (content == turnleft)
    {
        return 3;
    }
    if (content == turnright)
    {
        return 4;
    }
    if (content == highforward)
    {
        return 5;
    }
    if (content == highbackforward)
    {
        return 6;
    }
    if (content == highturnleft)
    {
        return 7;
    }
    if (content == highturnright)
    {
        return 8;
    }
	return 0;
}

int main(int argc, char** argv){
  // init the ros, and new a Publisher
  ros::init(argc, argv, "controller");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1);
  // set frequency to 100 Hz;
  ros::Rate loop_rate(100);
  //while loop
  while (ros::ok())
  {
    state  = ReadState();
    //ROS_INFO("%d", state);
    //from state to twist message.
    switch(state){
        case 0:
            twist.linear.x = 0;            
            twist.angular.z = 0;
            break;
        case 1:
            twist.linear.x = 0.4;            
            twist.angular.z = 0;
            break;
        case 2:
            twist.linear.x = -0.4;            
            twist.angular.z = 0;
            break;
        case 3:
            twist.linear.x = 0;            
            twist.angular.z = 0.3;
            break;
        case 4:
            twist.linear.x = 0;            
            twist.angular.z = -0.3;
            break;
        case 5:
            twist.linear.x = 1;            
            twist.angular.z = 0;
            break;
        case 6:
            twist.linear.x = -1;            
            twist.angular.z = 0;
            break;
        case 7:
            twist.linear.x = 0;            
            twist.angular.z = 0.6;
            break;
        case 8:
            twist.linear.x = 0;            
            twist.angular.z = -0.6;
            break;
        default:
            twist.linear.x = 0;            
            twist.angular.z = 0;
            break;
    }
    twist.linear.y = 0;
    twist.linear.z = 0;
    twist.angular.x = 0;
    twist.angular.y = 0;
    chatter_pub.publish(twist);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
