#include "DHT.h"
#include "string.h"
// Sử dụng thư viện DHTsensorlibrarymaster
const int DHTPIN = 3;
const int DHTTYPE = DHT11;
int Count = 0;

DHT dht(DHTPIN,DHTTYPE);

float a[15];
float b[15];
float c[15];

void setup(){
  Serial.begin(9600);
  dht.begin();
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
  Serial.print("Nhiệt độ:");
  a[15] = (Serial.print(t), Serial.println("*C"));
  b[15] = Serial.print(f);
  Serial.println("*F");
  Serial.print("Độ ẩm:");
  c[15] = (Serial.print(h),Serial.println("%"));
  Serial.println(); //Để xuống hàng

  if (Count >= 100) {            //Giới hạn số lần đếm
    Count = 0;
  }
  delay(1000);
}

