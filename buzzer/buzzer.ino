int b=6, l=A1;
void setup() {
  pinMode(b,OUTPUT);
  pinMode(l,INPUT);

}

void loop() {
 // tone(b,10000);delay(500);
 // noTone(b);delay(500);
 int val = analogRead(l);
 if(val==HIGH){
  tone(b, 1000);
 }
 else if(val==LOW){
  noTone(b);
 }

}
