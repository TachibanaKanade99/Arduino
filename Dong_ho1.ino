#include <DS3231.h>
DS3231 rtc(SDA,SCL);
int led = 13;
String inString = "";
int h;

void setup() {
	Serial.print(9600);
	rtc.begin();
	pinMode(led, OUTPUT);
	Serial.println("\n\nString  substring():");
	Serial.println();
  Serial.println("\n\nString toInt():");
  Serial.println();
  rtc.setDOW(WEDNESDAY);
	rtc.setTime("19", "04", "00");
	rtc.setDate("12", "01", "2017");
 } 

 void loop() {
 	Serial.print(rtc.getDOWStr());
 	Serial.print(" ");
  String b =  rtc.getDateStr(); 
 	Serial.println(b);
  String c = rtc.getTimeStr();
 	Serial.println(c);
 	Serial.println();

  String n = c.substring(0,2);
    if (n == '\n') {
       h =  Serial.println(inString.toInt());   
    }
    if ( h >12 ){
    digitalWrite(led, HIGH);
    }
    else {
    digitalWrite(led, LOW);
    }   
   delay(1000);
}
