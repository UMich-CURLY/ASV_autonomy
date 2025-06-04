import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from pymavlink import mavutil
import time


class MavlinkBridgeNode(Node):
    def __init__(self):
        super().__init__('mavlink_bridge_node')

        self.get_logger().info('Connecting to BlueBoat MAVLink...')
        self.master = mavutil.mavlink_connection('udpin:192.168.2.1:14550')
        self.master.wait_heartbeat()
        self.get_logger().info('Heartbeat from system (system %u component %u)' %
                               (self.master.target_system, self.master.target_component))

        # Arm the vehicle
        self.arm_vehicle()

        # ROS 2 subscriber
        self.subscription = self.create_subscription(
            Float64MultiArray,
            '/mavlink/thrust_commands',
            self.listener_callback,
            10
        )

        # Init last message timestamp
        self.last_msg_time = self.get_clock().now()
        self.timeout_sec = 2.0  # seconds until timeout

        # RC channel values (PWM, 1500 = neutral, or use -1 for no override)
        #self.rc_channels = [1500] * 8
        
        # RC channels (16 total; 0=chan1, 2=chan3 are used here)
        self.rc_channel_values = [65535] * 8  # 65535 means "do not override"

        # Timer to check Wi-Fi connection
        self.timer = self.create_timer(0.5, self.check_connection)

        self.get_logger().info('MAVLink bridge initialized.')

    def arm_vehicle(self):
        self.get_logger().info('Arming vehicle...')
        self.master.arducopter_arm()
        self.master.motors_armed_wait()
        self.get_logger().info('Vehicle armed.')

    def listener_callback(self, msg):
        if len(msg.data) != 2:
            self.get_logger().warn('Expected 2 thrust values [left, right]')
            return

        # Update last received time
        self.last_msg_time = self.get_clock().now()

        left = max(min(msg.data[0], 1.0), -1.0)
        right = max(min(msg.data[1], 1.0), -1.0)

        #self.update_channels(left, right)
        # Convert to steering (CH1) and throttle (CH3)
        # Assume symmetric thrust: avg for throttle, diff for steering
        throttle = (left + right) / 2.0
        steering = (right - left) / 2.0

        self.update_channels(steering, throttle)
        self.send_rc_commands()

        self.get_logger().info(f'Sent RC thrusts: Left={left:.2f}, Right={right:.2f}')

    #def update_channels(self, left_thrust, right_thrust):
    #    """
    #    Map thrust [-1.0, 1.0] to PWM [1100, 1900], where 1500 is neutral.
    #    """
    #    def scale(value):
    #        return int(1500 + value * 400)

     #   self.rc_channels[0] = scale(left_thrust)   # e.g., channel 1 = left motor
     #   self.rc_channels[1] = scale(right_thrust)  # e.g., channel 2 = right motor
     
    def update_channels(self, steering, throttle):
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

    def check_connection(self):
        now = self.get_clock().now()
        elapsed = (now - self.last_msg_time).nanoseconds / 1e9
        if elapsed > self.timeout_sec:
            self.get_logger().error(f"No thrust commands for {elapsed:.1f} seconds. Shutting down.")
            self.shutdown()

    def shutdown(self):
        self.get_logger().info('Disarming and shutting down node...')
        try:
            self.master.arducopter_disarm()
        except Exception as e:
            self.get_logger().error(f"Disarm failed: {e}")
        finally:
            self.destroy_node()
            rclpy.shutdown()


def main(args=None):
    rclpy.init(args=args)
    node = MavlinkBridgeNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('KeyboardInterrupt: shutting down...')
        node.shutdown()


if __name__ == '__main__':
    main()

