
#include <LiquidCrystal.h>


const int LM35 = A0;
const int motor = 13;
const int LedRed = 12;
const int LedGreen = 11;
int percentValue = 0;  

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Automated Crop");
  lcd.setCursor(0,1);
  lcd.print("Watering System!");
  pinMode(motor, OUTPUT);
  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  delay(2000);
  lcd.clear();
  lcd.print("SoilM = ");
  lcd.setCursor(0,1);
  lcd.print("WaterPump= ");
}

void loop() {

  int value = analogRead(LM35);
  float Moisture = value * 500.0 / 1023.0;
  lcd.setCursor(6,0);
  lcd.print(Moisture); 
  lcd.setCursor(11,1);
  

  if (Moisture < 310){
    digitalWrite(motor, HIGH);
    digitalWrite(LedRed, HIGH);
    digitalWrite(LedGreen, LOW);
    lcd.print("ON ");
  }
  else {
    digitalWrite(motor, LOW);
    digitalWrite(LedRed, LOW);
    digitalWrite(LedGreen, HIGH);
    lcd.print("OFF");
  }
  
Serial.print ("Moisture");
  Serial.println (Moisture);
}
  