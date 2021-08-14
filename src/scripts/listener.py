import rospy
from std_msgs.msg import String

def chatter_callback(message):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", message.data)

def listener():

    # Initializes a node with name listener and ensures unique name
    rospy.init_node('listener', anonymous=True)

    """ Creates a subscriber object to topic chatter expecting data 
    String and performs "chatter_callback" upon receiving a new message """
    rospy.Subscriber("chatter", String, chatter_callback)

    # Program goes into listening mode; executes callback w/ every message
    rospy.spin()

if __name__ == '__main__':
    listener()