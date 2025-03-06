const int RTracker = 9;
const int LTracker = 8;

// Motor Pins

const int enA = 6; // Right Motor speed
const int enB = 3; // Left mOTOR Speed

const int in1 = 7;
const int in2 = 5;
const int in3 = 4;
const int in4 = 2;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(RTracker, INPUT);
  pinMode(LTracker, INPUT);
  analogWrite(enA, 127);
  analogWrite(enB, 127);
}

void loop() {

  forward();

  while (digitalRead(RTracker) == 0 && digitalRead(LTracker) == 1) {
    // Left Turn
    left();
    //adjust
    if (digitalRead(RTracker) == 1 && digitalRead(LTracker) == 0) {
      right();
    } else {
      continue;
    }
  }

  while (digitalRead(RTracker) == 1 && digitalRead(LTracker) == 0) {
    // Right Turn
    right();
    if (digitalRead(RTracker) == 0 && digitalRead(LTracker) == 1) {
      left();
    } else {
      continue;
    }
  }

}
// Movement Modules

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
