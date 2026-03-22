 Rover Motion Simulation

 Project Description
This C program calculates the time required for a rover to move from an origin point `(x1, y1)` to a destination `(x2, y2)` in 2D space. It considers:

- Initial velocity (`u`) of the rover.
- Constant acceleration (`a`) of the rover.
- Maximum allowed speed (`topSpeed`) for safety.
  
The program handles multiple scenarios:
1. No acceleration (`a = 0`).
2. Accelerating until the rover reaches the top speed.
3. The rover cannot reach top speed within the distance.

The program uses **kinematic equations** and basic **distance calculations** for 2D coordinates.

---

 Features
- Validates input values (velocity, acceleration, top speed) to ensure physical correctness.
- Handles zero distance or zero velocity cases.
- Computes acceleration phase distance and time at constant top speed.
- Solves quadratic equations if rover does not reach top speed within the total distance.
- Provides clear output for distance traveled and total time taken.

---

 Inputs
The program takes the following inputs from the user:

1. Origin coordinates: `x1` and `y1` (meters)  
2. Destination coordinates: `x2` and `y2` (meters)  
3. Initial velocity `u` (meters/second)  
4. Acceleration `a` (meters/second²)  
5. Maximum allowed speed `topSpeed` (meters/second)

---
 Outputs
The program prints:

- Distance between origin and destination (`s`) in meters.
- Total time required to reach the destination (`t_total`) in seconds.

---
 How to Run
1. Make sure you have a **C compiler** installed, e.g., `gcc`.
2. Save the code in a file, e.g., `task_1.c`.
3. Open a terminal and navigate to the directory containing the file.
4. Compile the code:
```bash
gcc task_1.c -o task_1 -lm

Run:
./task_1


sample input:
Enter origin x1 y1: 0 0
Enter destination x2 y2: 10 0
Enter initial velocity (u): 2
Enter acceleration (a): 1
Enter top speed: 5

output:

Distance = 10.000000 m
Total time = 4.472136 seconds




Code Documentation:

Inline comments are included in the code to explain each step clearly.
The program handles edge cases such as:
Negative inputs
Zero distance
Zero acceleration
Speed limits 
![WhatsApp Image 2026-03-22 at 11 44 12 PM](https://github.com/user-attachments/assets/93fa0ac2-a12a-4c2a-b50c-6683bc7a5d1a)

Contributors:
parvathy G
