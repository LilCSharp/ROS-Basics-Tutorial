#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace ros;

void chatterCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("[Listener] I heard: [%s]\n", msg->data.c_str());
}

int main(int argc, char **argv) {

    // Initializes a new node named "listener_node"
    init(argc, argv, "listener_node");

    // Subscribes node to the topic chatter with a processing queue of 1000
    // and executes the callback function whenever a message is received
    NodeHandle node;
    Subscriber sub = node.subscribe("chatter", 1000, chatterCallback);

    // Enters a loop of listening for messages and executing callbacks
    spin();

    return 0;
}