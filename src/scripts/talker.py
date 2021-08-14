import rospy
from std_msgs.msg import String

def talker():

    """ Initializes a publisher object with topic name chatter and with 
    message type String. Queue size 10 is the amount of messages that can be
    sent asynchronously on different threads """
    pub = rospy.Publisher('chatter', String, queue_size=10)

    """ Initializes a node to connect to the master. Names it 'talker' """
    rospy.init_node('talker', anonymous=True)

    rate = rospy.Rate(1) # Sets how frequently system should sleep to 1 hz

    count = 0

    while not rospy.is_shutdown():
        hello_str = "hello world %s" % count
        rospy.loginfo(hello_str)

        # Publishes message in function param to the topic 'chatter'
        pub.publish(hello_str)

        rate.sleep()

        count += 1

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass