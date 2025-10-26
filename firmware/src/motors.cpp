#include "Arduino.h"
#include "motor_driver.h"

#define LEFT_MOTOR_FORWARD 9
#define LEFT_MOTOR_BACKWARD 8
#define RIGHT_MOTOR_FORWARD 7
#define RIGHT_MOTOR_BACKWARD 6
#define LEFT_PWM 5
#define RIGHT_PWM 10

void initMotors() {
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
}

void moveForward(int speed) {
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
  analogWrite(LEFT_PWM, speed);
  analogWrite(RIGHT_PWM, speed);
}

void moveBackward(int speed) {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);
  analogWrite(LEFT_PWM, speed);
  analogWrite(RIGHT_PWM, speed);
}

void turnLeft(int speed) {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  analogWrite(RIGHT_PWM, speed);
}

void turnRight(int speed) {
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  analogWrite(LEFT_PWM, speed);
}

void stopMotors() {
  analogWrite(LEFT_PWM, 0);
  analogWrite(RIGHT_PWM, 0);
}
