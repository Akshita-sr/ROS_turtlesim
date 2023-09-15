#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // Initialize the ROS node with a unique name (you can change "publisher_node" to your desired name)
    ros::init(argc, argv, "publisher_node");

    // Create a ROS node handle
    ros::NodeHandle nh;

    // Create a publisher for a specific topic (e.g., "my_topic") with the message type "std_msgs/String"
    ros::Publisher pub = nh.advertise<std_msgs::String>("talker", 10);

    // Set the publishing rate (e.g., 1 Hz)
    ros::Rate rate(1);

    while (ros::ok())
    {
        // Create a message object of type "std_msgs/String"
        std_msgs::String msg;
        msg.data = "Hello, underwater world!";

        // Publish the message to the "my_topic" topic
        pub.publish(msg);

        // Log the message for debugging or monitoring
        ROS_INFO("Published: %s", msg.data.c_str());

        // Sleep to control the publishing rate
        rate.sleep();
    }

    return 0;
}
