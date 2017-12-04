#include <DS3231.h>
DS3231 rtc(SDA,SCL);
int led = 13;

void setup() {
	Serial.print(9600);
	rtc.begin();
	pinMode(led, OUTPUT);
	Serial.println("\n\nString  substring():");
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
  String c = rtc,getTimeStr();
 	Serial.println(c);
 	Serial.println();

  n = (int) c.substring(0,2);
  if n > 12 ) {
    digitalWrite(led, HIGH);
    else
    digitalWrite(led, ;LOW);
  }

 	if (isnan(rtc.getDOWStr) || isnan(rtc.getDateStr) || isnan(rtc.getTimeStr)) {
 		Serial.println("Lỗi không đọc được dữ liệu");
 		return;
 	}
 	delay(1000);
 }
