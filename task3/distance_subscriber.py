import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32

class DistanceSubscriber(Node):

    def __init__(self):
        super().__init__('distance_subscriber')
        
        # Subscribe to /distance topic
        self.subscription = self.create_subscription(
            Int32,
            'distance',
            self.listener_callback,
            10
        )

    def listener_callback(self, msg):
        # Print received data
        self.get_logger().info(f'Received distance: {msg.data}')

def main(args=None):
    rclpy.init(args=args)
    node = DistanceSubscriber()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()