#!/usr/bin/env python3
"""
keyboard_thrust_teleop.py

Manual control of left and right thrusters via keyboard input.

Controls:
W/S: Increase/Decrease forward thrust
A/D: Differential thrust for turning
SPACE: Stop all thrust
1: Set to max thrust
2: Set to min thrust
Q or CTRL-C: Quit
"""

import sys
import termios
import tty
import signal
import select

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64


class KeyboardThrustTeleop(Node):
    def __init__(self):
        super().__init__('keyboard_thrust_teleop')

        self.publisher_left = self.create_publisher(
            Float64,
            '/wamv/thrusters/left/thrust',
            10
        )
        self.publisher_right = self.create_publisher(
            Float64,
            '/wamv/thrusters/right/thrust',
            10
        )

        self.left_thrust = 0.0
        self.right_thrust = 0.0
        self.step = 50.0
        self.max_thrust = 200.0
        self.min_thrust = -200.0
        self.running = True

        self.print_instructions()
        self.publish_thrust()

    def print_instructions(self):
        print("""
WAM-V Keyboard Thrust Control
-----------------------------
Reading from keyboard and publishing to thrust topics.

w/s   : increase/decrease forward thrust for both thrusters
a/d   : differential thrust, turn left/right
space : stop all thrust
1     : set both thrusters to max thrust
2     : set both thrusters to min thrust
q     : quit
CTRL-C: quit
-----------------------------
""")

    def publish_thrust(self):
        msg_left = Float64()
        msg_right = Float64()

        msg_left.data = float(self.left_thrust)
        msg_right.data = float(self.right_thrust)

        self.publisher_left.publish(msg_left)
        self.publisher_right.publish(msg_right)

        print(
            f"\rLeft Thrust: {self.left_thrust:7.2f}, "
            f"Right Thrust: {self.right_thrust:7.2f}  ",
            end='',
            flush=True
        )

    def stop_thrusters(self):
        self.left_thrust = 0.0
        self.right_thrust = 0.0
        self.publish_thrust()
        print("\nThrusters stopped.")

    def update_thrust(self, key):
        key = key.lower()

        if key == 'w':
            self.left_thrust = min(self.left_thrust + self.step, self.max_thrust)
            self.right_thrust = min(self.right_thrust + self.step, self.max_thrust)

        elif key == 's':
            self.left_thrust = max(self.left_thrust - self.step, self.min_thrust)
            self.right_thrust = max(self.right_thrust - self.step, self.min_thrust)

        elif key == 'a':
            self.left_thrust = max(self.left_thrust - self.step, self.min_thrust)
            self.right_thrust = min(self.right_thrust + self.step, self.max_thrust)

        elif key == 'd':
            self.left_thrust = min(self.left_thrust + self.step, self.max_thrust)
            self.right_thrust = max(self.right_thrust - self.step, self.min_thrust)

        elif key == ' ':
            self.left_thrust = 0.0
            self.right_thrust = 0.0

        elif key == '1':
            self.left_thrust = self.max_thrust
            self.right_thrust = self.max_thrust

        elif key == '2':
            self.left_thrust = self.min_thrust
            self.right_thrust = self.min_thrust

        elif key in ('q', '\x03', '\x04'):
            # q, CTRL-C, or CTRL-D
            self.running = False
            return

        else:
            print(f"\nUnknown key: {repr(key)}")
            return

        self.publish_thrust()


class KeyboardReader:
    """
    Context manager for keyboard input.

    Uses cbreak mode instead of raw mode so CTRL-C can still raise
    KeyboardInterrupt normally.
    """

    def __init__(self):
        self.fd = sys.stdin.fileno()
        self.old_settings = None

    def __enter__(self):
        if sys.stdin.isatty():
            self.old_settings = termios.tcgetattr(self.fd)
            tty.setcbreak(self.fd)
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        if self.old_settings is not None:
            termios.tcsetattr(self.fd, termios.TCSADRAIN, self.old_settings)

    def get_key(self, timeout=0.1):
        readable, _, _ = select.select([sys.stdin], [], [], timeout)
        if readable:
            return sys.stdin.read(1)
        return None


def main(args=None):
    rclpy.init(args=args)
    node = KeyboardThrustTeleop()

    def request_shutdown(sig=None, frame=None):
        node.running = False

    signal.signal(signal.SIGINT, request_shutdown)
    signal.signal(signal.SIGTERM, request_shutdown)

    try:
        with KeyboardReader() as keyboard:
            while rclpy.ok() and node.running:
                rclpy.spin_once(node, timeout_sec=0.0)

                key = keyboard.get_key(timeout=0.1)
                if key is not None:
                    node.update_thrust(key)

    except KeyboardInterrupt:
        node.running = False

    finally:
        try:
            node.stop_thrusters()
        except Exception as exc:
            print(f"\nFailed to publish zero thrust during shutdown: {exc}")

        node.destroy_node()

        if rclpy.ok():
            rclpy.shutdown()

        print("Exited keyboard thrust teleop.")


if __name__ == '__main__':
    main()
