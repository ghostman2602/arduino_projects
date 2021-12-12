int val;
void setup(){
  Serial.begin(9600);                            // sets the serial port to 9600
 }
void loop(){
  val = analogRead(0);       // read analog input pin 0
  Serial.print("AirQua = ");
  Serial.print(val, DEC);               // prints the value read
  Serial.println(" PPM");
  delay(1000);                                   // wait 1 sec for next reading
}
