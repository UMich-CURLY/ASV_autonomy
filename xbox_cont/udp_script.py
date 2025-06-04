import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
import socket
import struct

class UdpReceiverNode(Node):
    def __init__(self):
        super().__init__('udp_receiver')
        self.publisher_ = self.create_publisher(Float64MultiArray, '/mavlink/thrust_commands', 10)

        # UDP setup
        UDP_IP = "0.0.0.0"
        UDP_PORT = 8888
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((UDP_IP, UDP_PORT))
        self.sock.setblocking(False)

        self.timer = self.create_timer(0.01, self.timer_callback)

    def timer_callback(self):
        try:
            data, _ = self.sock.recvfrom(1024)
            left, right = struct.unpack('ff', data)
            msg = Float64MultiArray()
            msg.data = [left, right]
            self.publisher_.publish(msg)
            self.get_logger().info(f'Received: {msg.data}')
        except BlockingIOError:
            pass

def main(args=None):
    rclpy.init(args=args)
    node = UdpReceiverNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

