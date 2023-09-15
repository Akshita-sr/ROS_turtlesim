#include "ros/ros.h"
#include "std_msgs/String.h"

// Callback function to process incoming messages
void callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Received: %s", msg->data.c_str());
}

int main(int argc, char **argv)
{
    // Initialize the ROS node with a unique name (you can change "subscriber_node" to your desired name)
    ros::init(argc, argv, "subscriber_node");

    // Create a ROS node handle
    ros::NodeHandle nh;

    // Subscribe to the "my_topic" topic with the message type "std_msgs/String" and specify the callback function
    ros::Subscriber sub = nh.subscribe("talker", 10, callback);

    // Spin to keep the node alive and process incoming messages
    ros::spin();

    return 0;
}
