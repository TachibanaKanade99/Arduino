int val_X, val_Y;
int pin_X = 0;
int pin_Y = 1;

void setup() {
  Serial.begin(9600);
}
void loop() {
  //put your main code here, to run reapeatedly:
  val_X = analogRead(pin_X);
  val_Y = analogRead(pin_Y);
  Serial.print("Val X: "); Serial.print(val_X);
  Serial.print("Val_y: "); Serial.print(val_Y);
  delay(50);
}

