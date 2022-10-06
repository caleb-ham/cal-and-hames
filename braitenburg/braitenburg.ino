#include "Servo.h"
 
Servo leftServo;
Servo rightServo;
int leftValue = 0;
int rightValue = 0;

const int ldrPinLeft = A2; 
const int ldrPinRight = A1;


void setup() {
  Serial.begin(9600);
  leftServo.attach(10);
  rightServo.attach(9);
  pinMode(ldrPinLeft, INPUT);
  pinMode(ldrPinRight, INPUT);
}
 
void loop() {

  //Serial.print("QA");
  int ldrStatusLeft = analogRead(ldrPinLeft);
  int ldrStatusRight = analogRead(ldrPinRight);

  // sensor values between 50..900
  leftValue = (analogRead(0) - 50) / 50;
  rightValue = (analogRead(1) - 50) / 50;
  //leftServo.write(89 + rightValue);
  //rightServo.write(89 - leftValue);
  delay(10);

  ldrStatusLeft = map(ldrStatusLeft, 100, 900, 0, 10);
  ldrStatusRight = map(ldrStatusRight, 100, 900, 0, 10);
  
  Serial.print(ldrStatusLeft);
  Serial.print(",");
  Serial.print(ldrStatusRight);
  Serial.println();



  if (ldrStatusLeft > 2) {
      leftServo.write(180 * ldrStatusLeft/10);
      Serial.print(ldrStatusLeft);
      Serial.print(",");
  }
  if (ldrStatusRight > 2) {
      rightServo.write(180 * ldrStatusRight/10);
      Serial.print(ldrStatusRight);

  Serial.println();

  }
}