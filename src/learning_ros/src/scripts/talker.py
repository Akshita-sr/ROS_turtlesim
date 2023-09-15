#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

def publisher_node():
    # Initialize the ROS node with a unique name (you can change 'publisher_node' to your desired name)
    rospy.init_node('publisher_node', anonymous=True) #here the node name is publisher_node

    # Create a publisher for a specific topic (e.g here 'talker') with the message type 'String'
    pub = rospy.Publisher('talker', String, queue_size=10)

    # Set the publishing rate (e.g., 1 Hz is the frequency of publishing)
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        # Create a message object and set its data
        message = String()
        message.data = "Hello World!"

        # Publish the message to the 'talker' topic
        pub.publish(message)

        # Log the message for debugging or monitoring
        rospy.loginfo("Published: <-- this is printed on the terminal when echoed %s", message.data)

        # Sleep to control the publishing rate
        rate.sleep()

if __name__ == '__main__':
    try:
        publisher_node()
    except rospy.ROSInterruptException:
        pass
