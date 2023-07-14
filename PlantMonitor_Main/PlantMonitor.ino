void setup() {
pinMode(13, OUTPUT);
Serial.begin(9600);

}

void loop() 

{
int y= analogRead(A0);
int u=map(y,0,1023,0,255);
Serial.println(u);

if(u>200)
{
  digitalWrite(13,HIGH);
  delay(1000);
}

if(u<200)
{
  digitalWrite(13,LOW);
  delay(1000);

}
}