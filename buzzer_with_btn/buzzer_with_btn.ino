int b=10,bt=9;
void setup() {
  pinMode(b,OUTPUT);
  pinMode(bt,INPUT);
}

void loop() {
  if(digitalRead(bt)==1){
    tone(b,1000);
  }
  else{
    noTone(b);
  }

}
