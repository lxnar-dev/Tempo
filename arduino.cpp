#include <Servo.h>

const int trigPin = 9;  // Ultrasonic sensor trigger pin
const int echoPin = 10; // Ultrasonic sensor echo pin
const int motorPin = 6;  // Servo motor control pin

Servo motorServo; // Create a servo object to control the motor

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  motorServo.attach(motorPin);
}

void loop() {
  long duration, distance;
  
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Convert the duration into distance
  distance = (duration / 2) / 29.1; // Divide by 29.1 or multiply by 0.0343
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if motion is detected within 30cm
  if (distance <= 30) {
    rotateServo();
    delay(2000); // Wait for the servo motor to complete its rotation
  }
}

void rotateServo() {
  // Rotate the servo motor 180 degrees left
  motorServo.write(0);
  delay(1000); // Adjust this delay based on your servo speed and mechanics
  
  // Rotate the servo motor 180 degrees right
  motorServo.write(180);
  delay(1000); // Adjust this delay based on your servo speed and mechanics
  
  // Stop the servo motor
  motorServo.write(90);
}
