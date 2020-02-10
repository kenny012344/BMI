#include "ros/ros.h"

#include "beginner_tutorials/my_msg.h"
#include "beginner_tutorials/BMI.h"

  

void chatterCallback(const beginner_tutorials::my_msg &msg)
{
  ros::NodeHandle r; 
  beginner_tutorials::BMI sol;
  ros::Publisher pub = r.advertise<beginner_tutorials::BMI>("fail", 1000);
  sol.id = msg.id;
  sol.BMI = msg.hight * msg.hight / msg.weight;
  pub.publish(sol);
}
  
int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n; 
  
 
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
 
  ros::spin();
  return 0;
}