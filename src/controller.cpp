#include "controller.h"

//From file "/var/ros/controller" read the state and return
int ReadState()
{  
    // read the file
    std::ifstream ifs("/var/ros/controller");
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>() ));
    // if state changed, write to console.
    if (!content.compare(last_state))
    {
        ROSINFO(content);
    }
    // from state to statecode
    if( content.compare("stop") ){
        return 0;
    }
    if( content.compare("forward")){
        return 1;
    }
    if (content.compare("backforward"))
    {
        return 2;
    }
    if (content.compare("turnleft"))
    {
        return 3;
    }
    if (content.compare("turnright"))
    {
        return 4;
    }
    if (content.compare("highforward"))
    {
        return 5;
    }
    if (content.compare("highback"))
    {
        return 6;
    }
    if (content.compare("highleft"))
    {
        return 7;
    }
    if (content.compare("highright"))
    {
        return 8;
    }
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
    //from state to twist message.
    switch(state){
        case 0:
            twist.linear.x = 0;            
            twist.angular.z = 0;
            break;
        case 1:
            twist.linear.x = 0;            
            twist.angular.z = 0;
            break;
        case 2:
            twist.linear.x = 0;            
            twist.angular.z = 0;
            break;
        case 3:
            twist.linear.x = 0;            
            twist.angular.z = 0;
            break;
        case 4:
            twist.linear.x = 0;            
            twist.angular.z = 0;
            break;
        case 5:
            twist.linear.x = 0;            
            twist.angular.z = 0;
            break;
        case 6:
            twist.linear.x = 0;            
            twist.angular.z = 0;
            break;
        case 7:
            twist.linear.x = 0;            
            twist.angular.z = 0;
            break;
        case 8:
            twist.linear.x = 0;            
            twist.angular.z = 0;
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
