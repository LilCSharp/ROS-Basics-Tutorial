#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include <string>
#include <cmath>

#define PI 3.141592
using namespace ros;

int main(int argc, char **argv) {
    init(argc, argv, "talker");
    NodeHandle n;
    Publisher twist_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    Rate loop_rate(1);
    int state = 0;

    while (ok()) {
        geometry_msgs::Twist msg;

        if (state % 2 == 0) {
            msg.linear.x = 5.0;
            msg.angular.z = 0;
        } else {
            msg.linear.x = 0;
            msg.angular.z = fmod(msg.angular.z + PI, 2*PI);
        }

        ROS_INFO("[Talker] Velocity= %f, angle = %f", msg.linear.x, msg.angular.z);

        twist_pub.publish(msg);
        spinOnce();
        loop_rate.sleep();

        state = (state + 1) % 2;
    }

    return 0;
}