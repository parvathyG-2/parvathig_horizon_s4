Arduino Servo Control with Potentiometer and Safety LED

Overview:

This Arduino project demonstrates how to control a servo motor using a potentiometer. The servo's angle is determined by the potentiometer's position. Additionally, a safety limit is implemented so the servo cannot rotate beyond 68 degrees. When the limit is reached, an LED turns on as an indicator.

This setup is ideal for learning about analog input reading, servo control, and basic conditional logic in Arduino.

Components Required:

Arduino board (Uno, Nano, etc.)
Servo motor
Potentiometer
LED (with 220Ω resistor)
Breadboard and jumper wires
Circuit Connections
Potentiometer:
Middle pin → A0 (analog input)
Other two pins → 5V and GND
Servo motor:
Signal pin → D9
Power → 5V
Ground → GND
LED:
Anode → D7 (through 220Ω resistor)
Cathode → GND



![task2 2](https://github.com/user-attachments/assets/4810f941-d6f7-4a0a-89aa-6f728e9662a5)

![task2](https://github.com/user-attachments/assets/1599c299-2215-4576-b0ae-3cc586904466)

How It Works

Reading the potentiometer:

p_value = analogRead(p_pin);
The potentiometer returns a value from 0 to 1023.


Mapping the potentiometer value to servo angle:

angle = map(p_value, 0, 1023, 0, 180);
This converts the potentiometer value to a corresponding angle between 0° and 180°.



Limiting servo movement:

if(angle > 68) {
    microServo.write(68);
    digitalWrite(Led_pin, HIGH);
} else {
    microServo.write(angle);
    digitalWrite(Led_pin, LOW);
}
If the angle exceeds 68°, the servo is capped at 68°, and the LED turns on.
Otherwise, the servo follows the potentiometer, and the LED stays off.



Delay for stability:

delay(20);
A short delay ensures smooth servo motion.



Arduino Code:

#include <Servo.h>

Servo microServo;

int p_pin = A0;    // Potentiometer input pin
int Led_pin = 7;   // LED output pin

int p_value;
int angle;

void setup() {
  microServo.attach(9);   // Servo signal pin
  pinMode(Led_pin, OUTPUT);
}

void loop() {
  p_value = analogRead(p_pin);               // Read potentiometer
  angle = map(p_value, 0, 1023, 0, 180);    // Map to 0-180 degrees

  if (angle > 68) {                          // Limit servo to 68°
    microServo.write(68);
    digitalWrite(Led_pin, HIGH);             // Turn on LED if limit exceeded
  } else {
    microServo.write(angle);                 // Move servo
    digitalWrite(Led_pin, LOW);              // Turn off LED
  }

  delay(20);                                 // Small delay for smooth motion
}



Features:

Analog control: Smooth servo movement using a potentiometer.
Safety limit: Prevents the servo from rotating beyond 68°.
Visual feedback: LED turns on if the limit is exceeded.


Applications:

Robotics joint movement control
Servo-limited mechanisms (like a robotic arm or valve)
Learning analog input and servo programming in Arduino
