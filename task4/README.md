# ROS2 Rover Decision Node – Bonus Task

## Overview
This ROS2 project simulates a simple rover decision system using publisher-subscriber communication:

- **Distance Publisher** – simulates a distance sensor by publishing random distance values.
- **Decision Node** – subscribes to the distance topic, evaluates the reading, and publishes rover commands (`STOP` or `MOVE_FORWARD`).
- **Optional Command Subscriber** – monitors the rover commands.

This setup demonstrates autonomous decision-making in a ROS2 environment.

---

## Nodes

### 1. Distance Publisher (`distance_publisher.py`)
- Publishes `Int32` messages to the `distance` topic.
- Generates random distance values (0–100) every second.
- Example log:

[INFO] [distance_publisher]: Published distance: 42


### 2. Decision Node (`decision_node.py`)
- Subscribes to `distance`.
- Implements simple decision logic:
  - `STOP` if distance < 30
  - `MOVE_FORWARD` if distance ≥ 30
- Publishes `String` messages to `rover_command`.
- Example log:

[INFO] [decision_node]: Distance received: 25 | Command: STOP


### 3. Rover Command Subscriber (optional)
- Subscribes to `rover_command` to verify commands.
- Example log:


---

## Prerequisites
- Ubuntu 22.04 or compatible
- ROS2 Humble
- Python 3

---

## Installation

1. Create a ROS2 workspace if not already created:
```bash
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src


Notes:
Decision threshold can be modified in decision_node.py.
The system can be extended to integrate real rover hardware.
This project helps understand ROS2 messaging and autonomous decision-making.

Author

Parvathy G