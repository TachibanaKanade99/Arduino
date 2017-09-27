const int ledPin = 11;
byte brightness = 10;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  if(Serial.available()) {
  brightness = Serial.parseInt();
  analogWrite(ledPin, brightness);
  } 
}

