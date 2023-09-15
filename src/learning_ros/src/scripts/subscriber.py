#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

def callback(data):
    # Callback function to process incoming messages here data.data means the data type of data is string
    rospy.loginfo("Received: %s", data.data) 

def subscriber_node():
    # Initialize the ROS node with a unique name (you can change 'subscriber_node' to your desired name)
    rospy.init_node('subscriber_node', anonymous=True)

    # Subscribe to the 'my_topic' topic with the message type 'String'
    rospy.Subscriber('talker', String, callback)

    # Spin to keep the node alive and process incoming messages this works like a while loop
    rospy.spin()

if __name__ == '__main__':
    try:
        subscriber_node()
    except rospy.ROSInterruptException:
        pass
