#include "ros/ros.h"

#include "beginner_tutorials/my_msg.h"
#include "beginner_tutorials/BMI.h"

beginner_tutorials::BMI sol;   //important !!

void chatterCallback(const beginner_tutorials::my_msg &msg)
{
  
  sol.id = msg.id;
  sol.BMI = msg.hight * msg.hight / msg.weight;

}
  
int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n; 
  
  ros::Publisher pub = n.advertise<beginner_tutorials::BMI>("solution", 1000);
 
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {

    pub.publish(sol);
    ROS_INFO("%d" , sol.id);
    ROS_INFO("%f" , sol.BMI);
    
    ros::spinOnce(); 
    loop_rate.sleep();
    
  }
  //ros::spin();
  return 0;
}