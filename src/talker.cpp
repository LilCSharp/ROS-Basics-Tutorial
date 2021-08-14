#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

using namespace ros;

int main(int argc, char **argv) {

    // Initializes node with a name and connects it to master.
    init(argc, argv, "talker");

    // Creates an instance of a node handler object
    NodeHandle n;

    // Initializes the node as a publisher that handles messages of type
    // string, names the topic "chatter", and maximizes the queue to 1000
    Publisher chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);

    // Sets the execution rate of the processes
    Rate loop_rate(0.5);

    int count = 0;

    // For as long as the node is not shutdown, publishes hello world
    while (ok()) {
        // Sets message data
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello World " << count;
        msg.data = ss.str();

        ROS_INFO("[Talker] I published %s\n", msg.data.c_str());

        // Publishes a message to the topic associated with the publisher
        chatter_publisher.publish(msg);

        // Processes callbacks and sleeps for remaining time in cycle
        spinOnce();
        loop_rate.sleep();
        
        count++;
    }

    return 0;
}