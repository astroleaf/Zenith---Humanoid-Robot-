#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(115200);
  servo1.attach(9);
  servo2.attach(10);
  Serial.println("Servo Joint Test Ready");
}

void loop() {
  for (int angle = 0; angle <= 180; angle += 10) {
    servo1.write(angle);
    servo2.write(180 - angle);
    delay(150);
  }
}
