#define echoPin 8 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 9 //attach pin D3 Arduino to pin Trig of HC-SR04

int b=7;

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

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
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(b,INPUT);
  Serial.begin(9600);

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
      // Draw characters of the default font
}


void loop() {

   digitalWrite(trigPin, LOW);
  delayMicroseconds(500);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  display.clearDisplay();
    display.setTextSize(2);      // Normal 1:1 pixel scale
    display.setTextColor(WHITE); // Draw white text
    display.setCursor(0, 15);     // Start at top-left corner
    display.cp437(true); 

    
    display.print("Distance: ");
  display.print(distance);
  display.println(" cm");
  display.display();
  }
