#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

void initMotors();
void moveForward(int speed);
void moveBackward(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void stopMotors();

#endif
