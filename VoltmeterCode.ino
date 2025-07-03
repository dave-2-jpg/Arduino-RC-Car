#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9 , 4, 5, 6, 7);
float voltageDivisor = 2.0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("DIGITAL VOLTMETER");
}

void loop()
{
 	//calculating voltage
  	int analogVoltage = analogRead(A0);
  	float measuredVoltage = (analogVoltage * 5.0) / 1024.0;
  	float inputVoltage = measuredVoltage * voltageDivisor;
  
  if (inputVoltage < 0.1) {
  inputVoltage = 0.0;
  }
   
  Serial.print("v=");
  Serial.println(inputVoltage);
  lcd.setCursor(0, 1);
  lcd.print("Voltage=");
  lcd.print(inputVoltage);
  delay(300);
}