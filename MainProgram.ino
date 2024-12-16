/*

AUTHOR: MATTIEW BAS - ICT 2 PROGRAMMING
BRANIACS, MAIN PROGRAM
LAST UPDATED: 12/4/24
VERSION: b0.6.1

*/

#include <Servo.h>

Servo DistanceServo;  // create Servo object to control a servo

// motor pins


// left motor
int enA = 6;
int in1 = 7; // ground
int in2 = 5; // power

// Right motor
int enB = 3;
int in3 = 4; // ground
int in4 = 2; // power

// Line Tracker pins

const int LT = 8;
const int MT = 9;
const int RT = 10;

// Distance pins

const int TrigPin = 13;
const int EchoPin = 12;
long Mdis;

unsigned long StartMillis;
unsigned long CurrentMillis;

void setup() {
  Serial.begin(9600);
  DistanceServo.attach(11);

  // Motors

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Line Tracker

  pinMode(LT, INPUT);
  pinMode(MT, INPUT);
  pinMode(RT, INPUT);
  StartMillis = millis();
  DistanceServo.write(90);
}

void loop() {
  int DefaultPos = 90;
  int RightPos = 0;
  int LeftPos = 180;
  // int distance = DistanceCheck(); // in inches
  unsigned long CurrentMillis = millis();
  int RightDistance;
  int LeftDistance;
  CurrentMillis = millis();

  if (digitalRead(MT) == 1) {
    analogWrite(enA, 200);
    analogWrite(enB, 200);
  } else if ((digitalRead(MT) == 1) && (digitalRead(RT) == 1) && (digitalRead(LT) == 0)) {
    analogWrite(enA, 0);
    analogWrite(enB, 200);
    delay(30);
    analogWrite(enA, 200);
    analogWrite(enB, 200);
  } else if ((digitalRead(MT) == 1) && (digitalRead(RT) == 0) && (digitalRead(LT) == 1)) {
    analogWrite(enA, 200);
    analogWrite(enB, 0);
    delay(30);
    analogWrite(enA, 200);
    analogWrite(enB, 200);
  }
  
  /*
  if (distance <= 5) {
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    DistanceServo.write(RightPos);
    delay(100); // wait for servo to position
    RightDistance = DistanceCheck();
    delay(1000); // wait to ensure stable reading
    DistanceServo.write(DefaultPos);
    delay(500); // wait to bring servo back to default
    DistanceServo.write(LeftPos);
    delay(100);
    LeftDistance = DistanceCheck();
    delay(1000);
    DistanceServo.write(DefaultPos);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(300);

    if (RightDistance >= LeftDistance) {
      Serial.println("TURNING RIGHT...");
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enA, 255);
      analogWrite(enB, 0);
      delay(500);
      analogWrite(enA, 200);
      analogWrite(enB, 200);
    } else if (LeftDistance >= RightDistance) {
      Serial.println("TURNING LEFT...");
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enA, 0);
      analogWrite(enB, 255);
      delay(500);
      analogWrite(enA, 200);
      analogWrite(enB, 200);
    }
    if (RightDistance >= LeftDistance || LeftDistance >= RightDistance) {
      StartMillis = millis();
    }
  }
  */
}

int DistanceCheck() {
  pinMode(TrigPin, OUTPUT);
  digitalWrite(TrigPin, LOW);
  delay(2);
  digitalWrite(TrigPin, HIGH);
  delay(12);
  digitalWrite(TrigPin, LOW);

  pinMode(EchoPin, INPUT);
  Mdis = pulseIn(EchoPin, HIGH);
  return Mdis / 74 / 2;
}
