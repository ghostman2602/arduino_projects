#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

void setup() {
  Serial.begin(9600);
  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();

  display.drawPixel(10, 10, WHITE);display.drawPixel(25, 15, WHITE);display.drawPixel(40, 10, WHITE);display.drawPixel(55, 15, WHITE);display.drawPixel(70, 10, WHITE);display.drawPixel(85, 15, WHITE);display.drawPixel(100, 10, WHITE);
  
  display.drawPixel(10, 30, WHITE);display.drawPixel(25, 35, WHITE);display.drawPixel(40, 30, WHITE);display.drawPixel(55, 35, WHITE);display.drawPixel(70, 30, WHITE);display.drawPixel(85, 35, WHITE);display.drawPixel(100, 30, WHITE);
  
  display.drawPixel(10, 50, WHITE);display.drawPixel(25, 55, WHITE);display.drawPixel(40, 50, WHITE);display.drawPixel(55, 55, WHITE);display.drawPixel(70, 50, WHITE);display.drawPixel(85, 55, WHITE);display.drawPixel(100, 50, WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
}


void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("°C \n");
  testdrawchar();
  delay(1);
}

void testdrawchar(void) {
    display.clearDisplay();
    display.setTextSize(2);      // Normal 1:1 pixel scale
    display.setTextColor(WHITE); // Draw white text
    display.setCursor(5,15);     // Start at top-left corner
   // display.cp437(true); 
 
    float h = dht.readHumidity();
  float t = dht.readTemperature();
  display.print("Hum: ");
  display.print(h);
  display.print("\n");
  display.print("Temp: ");
  display.print(t);
  display.display();
  delay(1);
  
}
