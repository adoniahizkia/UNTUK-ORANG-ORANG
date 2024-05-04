#include <ESP8266WiFi.h>

const char* ssid = "b";
const char* password = "tanyaandre";

const int mosfet1Pin = D2;
const int mosfet2Pin = D1;
const int mosfet3Pin = D1; // Sama dengan mosfet 2
const int mosfet4Pin = D2; // Sama dengan mosfet 1

void setup() {
  pinMode(mosfet1Pin, OUTPUT);
  pinMode(mosfet2Pin, OUTPUT);
  pinMode(mosfet3Pin, OUTPUT);
  pinMode(mosfet4Pin, OUTPUT);

  // Menghubungkan ke jaringan WiFi
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Menghubungkan ke ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Terhubung");
  Serial.println("Alamat IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Logika untuk mengontrol pulsa inverter
  // Sesuaikan dengan kebutuhan Anda

  // Contoh: Toggle mosfet 1 dan 4 setiap 10 detik
  digitalWrite(mosfet1Pin, HIGH);
  digitalWrite(mosfet2Pin, LOW);
  digitalWrite(mosfet3Pin, HIGH);
  digitalWrite(mosfet4Pin, LOW);
  delay(10); // Delay untuk satu setengah siklus (50Hz)
  digitalWrite(mosfet1Pin, LOW);
  digitalWrite(mosfet2Pin, HIGH);
  digitalWrite(mosfet3Pin, LOW);
  digitalWrite(mosfet4Pin, HIGH);
  delay(10); // Delay untuk satu setengah siklus (50Hz)
}
