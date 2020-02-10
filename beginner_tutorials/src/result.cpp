#include "ros/ros.h"


#include "beginner_tutorials/BMI.h"



void chatterCallback(const beginner_tutorials::BMI &msg)
{
	ROS_INFO("%d" , msg.id);
	ROS_INFO("%f" , msg.BMI);
  

}
  
int main(int argc, char **argv)
{
  ros::init(argc, argv, "result");
  ros::NodeHandle n; 
 
  ros::Subscriber sub = n.subscribe("solution", 1000, chatterCallback);
  
  ros::spin();
  return 0;
}