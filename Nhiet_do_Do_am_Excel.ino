#include "DHT.h"
// Sử dụng thư viện DHTsensorlibrarymaster
const int DHTPIN = 3;
const int DHTTYPE = DHT11;
int Count = 0;
float t = 0;
float f = 0;
float h = 0;

DHT dht(DHTPIN,DHTTYPE);

void setup(){
  Serial.begin(128000);
  dht.begin();
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Temperature(*C),Temperature(*F),Humidity");
}

void loop(){
  Count++;
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  // Check if any read failed and exit early
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Lỗi không thể đọc được kết quả");
    return;
  }
  Serial.print("DATA,TIME,");
  Serial.print(t);
  Serial.print(",");
  Serial.print(f);
  Serial.print(",");
  Serial.print(h);
  Serial.println(); //Để xuống hàng

  if (Count >= 100) {            //Giới hạn số lần đếm
    Count = 0;
    Serial.println("ROW,SET,2");
  }
  delay(2000);
}

