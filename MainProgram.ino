/*

AUTHOR: MATTIEW BAS - ICT 2 PROGRAMMING
BRANIACS, MAIN PROGRAM
LAST UPDATED: 12/4/24

*/


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Line tracker
  const int LT = 8;
  const int MT = 9;
  const int RT = 10;

  pinMode(LT, INPUT);
  pinMode(MT, INPUT);
  pinMode(RT, INPUT);

  // Distance checker
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
}

void loop() {
  int LeftTracker = digitalRead(LT);
  int MiddleTracker = digitalRead(MT);
  int RightTracker = digitalRead(RT)

  digitalWrite(RMG, HIGH);
  digitalWrite(LMP, HIGH)
  delay(1);
  digitalWrite(RMP, LOW);
  digitalWrite(RMG, LOW);
  
  if (MiddleTrack == 1) {
    Serial.println("Line Is Verified");
  }

  /* 

  if ((RightTracker == 1) && (MiddleTracker == 0) && ()) { // In case of right turn
    Serial.println("TURN RIGHT!!")
  }

  */
}

int DistanceCheck() { // Returns 0 within range whhilst 1 if far from an object.

  pinMode(TrigPin, OUTPUT);
  digitalWrite(TrigPin, LOW);
  delay(1);
  digitalWrite(TrigPin, HIGH);
  delay(2);
  digitalWrite(TrigPin, LOW);

  pinMode(EchoPin, INPUT);
  Mdis = pulseIn(EchoPin, HIGH);
  distance = Mdis / 74 / 2;
  return distance;
}

