/*

AUTHOR: MATTIEW BAS - ICT 2 PROGRAMMING
BRANIACS, MAIN PROGRAM
LAST UPDATED: 12/4/24
VERSION: b0.5

WARNING: WAIT FOR UPDATE  b0.6

*/


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // Line Tracker
  const int LT = 8;
  const int MT = 9;
  const int RT = 10;
  pinMode(LT, INPUT);
  pinMode(MT, INPUT);
  pinMode(RT, INPUT);

  // distance sensor

  const int TrigPin = 13;
  const int EchoPin = 12;
  int distance;
  long Mdis;

  // Motors
  int RMG = 4;
  int RMP = 3;
  int LMP = 2;
  int LMG = 1;

  pinMode(RMG, OUTPUT);
  pinMode(RMP, OUTPUT);
  pinMode(LMP, OUTPUT);
  pinMode(RMP, OUTPUT);

  int LeftTracker = digitalRead(LT);
  int MiddleTracker = digitalRead(MT);
  int RightTracker = digitalRead(RT);

  digitalWrite(RMG, HIGH);
  digitalWrite(LMP, HIGH);
  delay(1);
  digitalWrite(RMP, LOW);
  digitalWrite(RMG, LOW);
  
  if (MiddleTracker == 1) {
    if ((RightTracker == 0) && (MiddleTracker == 1) && (LeftTracker == 1)) { // In case of right turn
      Serial.println("TURN RIGHT!!");
    } else {
      Serial.println("MOVE FORWARD");
    }
  } else {
    Serial.println("ALIGN TRACKER");
  }
}
