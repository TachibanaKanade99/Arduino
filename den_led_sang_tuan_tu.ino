int ledPin[] = {
  4,5,6
};
int pinCount = 1 ;
void setup() {
  pinCount = sizeof (ledPin );
  for (int i=0; i<pinCount;i++) {
    pinMode (ledPin[i],OUTPUT);
    digitalWrite(ledPin[i],LOW);
  }
}
 void loop() {
  for (int i=0; i < pinCount; i++) {
    digitalWrite(ledPin[i], LOW);
    delay(50);
    digitalWrite(ledPin[i], HIGH);
    delay(50);
  }
 }

