#include <DHT.h>
#include <DS3231.h>

int DHTTYPE = DHT11;
int DHT_Data = 4;
int DHT_GND = 6;
int DHT_VCC = 3;
int Count = 0;
DS3231 rtc(SDA, SCL);

float t = 0;
float h = 0;
float f =0;

DHT dht(DHT_Data, DHTTYPE);

void setup(){
	pinMode(DHT_GND, OUTPUT);
	digitalWrite(DHT_GND, LOW);
	pinMode(DHT_VCC,OUTPUT);
	digitalWrite(DHT_VCC, HIGH);
	dht.begin();
	rtc.begin();
	Serial.begin(9600);
	//The following lines can be uncommented to set the date and time
	rtc.setDOW(THURSDAY);
	rtc.setTime(14, 0, 0);
	rtc.setDate(11, 23, 2017);
}

void loop(){
	Count++;
	t = dht.readTemperature();
	h = dht.readHumidity();
	f = dht.readTemperature(true);

  //Check if any read failed and exit early
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Lỗi không đọc được dữ liệu.");
    return;
	}
	Serial.print("Nhiệt độ:");
	Serial.print(t);
	Serial.print("*C");
  Serial.print(" - ");
	Serial.print(f);
	Serial.println("*F");
	Serial.print("Độ ẩm:");
  Serial.print(h);
	Serial.println("%");
	Serial.println();
	//Send Day-of-week
	Serial.print(rtc.getDOWStr());
	Serial.print(" ");
	//Send Date
	Serial.print(rtc.getDateStr());
	Serial.print(" -- ");
	//Send Time
	Serial.println(rtc.getTimeStr());

	if (Count >=100) {
		Count = 0;
	}
	delay(1000);
}

