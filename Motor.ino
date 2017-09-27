int E1 = 10;int E2 = 11;
int M1 = 12;int M2 = 13;
void setup(){
	pinMode(M1,OUTPUT);
	pinMode(M2,OUTPUT);
}
void loop(){
	int value;
	for(value = 50;value < 255;value +=5)
{
digitalWrite(M1,HIGH);
digitalWrite(M2,HIGH);
analogWrite(E1,value);
analogWrite(E2,value);
delay(30);
}
for (int value = 50; value < 255; value +=5)
{
	digitalWrite(M1,LOW);
	digitalWrite(M2,LOW);
	analogWrite(E1,value);
	analogWrite(E2,value);
	delay(30);
 }
}
