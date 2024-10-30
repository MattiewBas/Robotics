// sensor
const int Trigpin;
const int Echopin;

void setup() {
	Serial.begin(9600);
	pinMode(Trigpin, OUTPUT);
	pinMode(Echopin, INPUT);
}

void loop() {
	
}
