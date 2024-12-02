/*

AUTHOR: MATTIEW BAS - ICT 2 PROGRAMMING
BRANIACS, MAIN PROGRAM
LAST UPDATED: 12/2/24

*/


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

int DistanceCheck() { // Returns 0 within range whhilst 1 if far from an object.
  const int TrigPin = 13;
  const int EchoPin = 12;
  int distance;
  long Mdis; // Meassured distance using the sensor

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
