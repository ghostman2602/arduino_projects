#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include "DHT.h"

DHT dht(7, DHT11);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

int l = 5, bz = 3, b1 = 10, b2 = 12;

void setup(){
  pinMode(l, OUTPUT); pinMode(bz, OUTPUT); pinMode(b1, INPUT); pinMode(b2, INPUT);
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){Serial.print("Allocation failed");}
  display.clearDisplay();
  display.setCursor(0, 0); display.setTextSize(2); display.setTextColor(WHITE); display.cp437(true);
  display.print("Starting ...");
  display.display();
  delay(2000);
}

void loop(){
  int pol_val = analogRead(0);
  int b1v = digitalRead(b1), b2v = digitalRead(b2);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  display.clearDisplay();
  display.setCursor(0, 0); display.setTextSize(1); display.setTextColor(WHITE); display.cp437(true);

  display.print("\nHumidity: "); display.print(h); display.print(" %\n\n");
  display.print("Temperature: "); display.print(t); display.print(" C\n\n");
  display.print("\nAir Quality: "); display.print(pol_val); display.print("\n");

  display.display();
}
