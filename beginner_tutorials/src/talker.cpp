#include "ros/ros.h"

#include "beginner_tutorials/my_msg.h"
#include <math.h>
#include <stdlib.h>

     
int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<beginner_tutorials::my_msg>("chatter", 1000); 
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    beginner_tutorials::my_msg msg;
    srand(time(0));
    msg.id = rand() % 10;
    msg.hight = rand() % 20;
    msg.weight = rand() % 30;

    chatter_pub.publish(msg);
    ros::spinOnce(); 
    loop_rate.sleep();
    
  }
  return 0;
}