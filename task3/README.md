ROS2 Distance Publisher & Subscriber
Overview

This project demonstrates a basic ROS2 communication flow between two nodes:

Distance Publisher – simulates a distance sensor by publishing random distance values to the distance topic.
Distance Subscriber – listens to the distance topic and prints the received distance values.

This setup is useful for learning ROS2 publisher-subscriber concepts and testing simple decision-making logic.

Nodes:
1. Distance Publisher (distance_publisher.py)
Publishes Int32 messages on the distance topic.
Sends a random distance between 0–100 every second.

Example log output:
[INFO] [distance_publisher]: Published distance: 42
2. Distance Subscriber (distance_subscriber.py)
Subscribes to the distance topic.
Prints the received distance values.

Example log output:
[INFO] [distance_subscriber]: Received distance: 42

Prerequisites:
Ubuntu 22.04 (or compatible)
ROS2 Humble installed
Python 3

Installation:
Create a ROS2 workspace if you don’t have one:
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
Clone or copy this package into src.
Build the workspace:
cd ~/ros2_ws
colcon build
Source the workspace:
source install/setup.bash


Running the Nodes:

Run the publisher node:
ros2 run your_package_name distance_publisher


Run the subscriber node (in a separate terminal):

ros2 run your_package_name distance_subscriber
You should see distance values printed in the subscriber terminal.

Notes:

This is a simple simulation; you can replace the random distance in the publisher with real sensor data later.
You can extend this setup by creating a decision node that reacts to the distance values (e.g., STOP or MOVE_FORWARD).


Author

Parvathy G