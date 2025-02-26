from setuptools import find_packages
from setuptools import setup

setup(
    name='citrack_ros_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('citrack_ros_msgs', 'citrack_ros_msgs.*')),
)
