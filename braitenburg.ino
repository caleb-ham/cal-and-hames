#include "Servo.h"
 
Servo leftServo;
Servo rightServo;
int leftValue = 0;
int rightValue = 0;

const int ldrPinLeft = A2; 
const int ldrPinRight = A1;

void setup() {
  leftServo.attach(10);
  rightServo.attach(9);
  pinMode(ldrPinLeft, INPUT);
  pinMode(ldrPinRight, INPUT);
}
 
void loop() {

  int ldrStatusLeft = analogRead(ldrPinLeft);
  int ldrStatusRight = analogRead(ldrPinRight);

  // sensor values between 50..900
  leftValue = (analogRead(0) - 50) / 50;
  rightValue = (analogRead(1) - 50) / 50;
  leftServo.write(89 + rightValue);
  rightServo.write(89 - leftValue);
  delay(10);

  if (ldrStatusLeft > 50) {
      leftServo.write(89 + rightValue);
      Serial.print(ldrStatusLeft);
  }
  if (ldrStatusRight > 50) {
      rightServo.write(89 - leftValue);
      Serial.print(ldrStatusRight);

  }
}