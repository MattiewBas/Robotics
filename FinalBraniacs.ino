const int RTracker = 9;
const int LTracker = 10;

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

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}

void loop() {
  analogWrite(enA, 127);
  analogWRite(enB, 127);

  while (RTracker == 0 && LTracker == 1) {
    // Left Turn
    left();
    //adjust
    if (RTracker == 1 && LTracker == 0) {
      right();
    }
  }

  while (RTracker == 1 && LTracker == 0) {
    // Right Turn
    right();
    if (RTracker == 0 && LTracker == 1) {
      Left();
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

void reverse() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
