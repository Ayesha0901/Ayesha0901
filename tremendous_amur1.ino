// C++ code
//
#include <Servo.h>

int dist = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_6;

void setup()
{
  servo_6.attach(6, 500, 2500);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  dist = 0.01723 * readUltrasonicDistance(7, 7);
  if (dist <= 100) {
    servo_6.write(90);
  } else {
    servo_6.write(0);
  }
  delay(1000); // Wait for 1000 millisecond(s)
  if (digitalRead(2) == 1) {
    digitalWrite(13, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    digitalWrite(13, HIGH);
  }
  delay(1000); // Wait for 1000 millisecond(s)
  if (analogRead(A0) > 200) {
    digitalWrite(9, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    digitalWrite(9, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}