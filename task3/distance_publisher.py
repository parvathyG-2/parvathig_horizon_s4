import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
import random

class DistancePublisher(Node):

    def __init__(self):
        super().__init__('distance_publisher')
        
        # Create publisher on /distance topic
        self.publisher_ = self.create_publisher(Int32, 'distance', 10)
        
        # Timer: publish every 1 second
        self.timer = self.create_timer(1.0, self.publish_distance)

    def publish_distance(self):
        msg = Int32()
        
        # Generate random distance value
        msg.data = random.randint(0, 100)
        
        # Publish message
        self.publisher_.publish(msg)
        
        # Print for debugging
        self.get_logger().info(f'Publishing: {msg.data}')

def main(args=None):
    rclpy.init(args=args)
    node = DistancePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()