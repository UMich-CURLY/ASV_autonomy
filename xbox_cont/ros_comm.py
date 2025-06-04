import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from pymavlink import mavutil
import time


class MavlinkRCBridgeNode(Node):
    def __init__(self):
        super().__init__('mavlink_rc_bridge_node')

        # Connect to the MAVLink vehicle (adjust the port/baudrate)
        self.get_logger().info('Connecting to BlueBoat MAVLink...')
        self.master = mavutil.mavlink_connection('udpin:192.168.2.1:14550')
        self.master.wait_heartbeat()
        self.get_logger().info(f'Connected to system {self.master.target_system} component {self.master.target_component}')

        # Arm the vehicle
        self.arm_vehicle()

        # RC channels (16 total; 0=chan1, 2=chan3 are used here)
        self.rc_channel_values = [65535] * 8  # 65535 means "do not override"

        # ROS 2 subscriber
        self.subscription = self.create_subscription(
            Float64MultiArray,
            '/mavlink/thrust_commands',
            self.listener_callback,
            10
        )

        # Create a timer to send RC commands at 10 Hz
        self.timer = self.create_timer(0.1, self.send_rc_commands)

        self.get_logger().info("MAVLink RC bridge ready and subscribed to /mavlink/thrust_commands")

    def arm_vehicle(self):
        self.get_logger().info('Arming vehicle...')
        self.master.arducopter_arm()
        self.master.motors_armed_wait()
        self.get_logger().info('Vehicle armed.')

    def listener_callback(self, msg):
        if len(msg.data) != 2:
            self.get_logger().warn('Expected 2 values: [left_thrust, right_thrust]')
            return

        left = max(min(msg.data[0], 1.0), -1.0)
        right = max(min(msg.data[1], 1.0), -1.0)

        # Convert to steering (CH1) and throttle (CH3)
        # Assume symmetric thrust: avg for throttle, diff for steering
        throttle = (left + right) / 2.0
        steering = (right - left) / 2.0

        self._update_channels(steering, throttle)

    def _update_channels(self, steering, throttle):
        """
        Update RC channel values based on steering and throttle inputs.
        Inputs are in range [-1.0, 1.0]; map to PWM [1100, 1900]
        """
        def map_range(x):
            return int(1500 + x * 400)  # dead center = 1500, range ±400

        ch1 = map_range(steering)  # Steering
        ch3 = map_range(throttle)  # Throttle

        self.rc_channel_values[0] = ch1
        self.rc_channel_values[2] = ch3

        self.get_logger().info(f"Updated RC: Steering={ch1}, Throttle={ch3}")

    def send_rc_commands(self):
        """Send RC override commands periodically."""
        self.master.mav.rc_channels_override_send(
            self.master.target_system,
            self.master.target_component,
            *self.rc_channel_values
        )


def main(args=None):
    rclpy.init(args=args)
    node = MavlinkRCBridgeNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down...')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()

