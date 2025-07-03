#include <LiquidCrystal.h>              //library for LCD screen fnctions
LiquidCrystal lcd(8, 9 , 4, 5, 6, 7);   // Initialize the LCD with Arduino pins: RS=8, E=9, D4-D7=4,5,6,7
float voltageDivisor = 2.0;             //variable to store the divisor

//beginning config
void setup()
{
  // Start serial communication at 9600 bits per second 
  Serial.begin(9600);
  
  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Print the title on the LCD 
  lcd.print("DIGITAL VOLTMETER");
}

//repeat infinitely
void loop()
{
   	//calculating voltage
  	int analogVoltage = analogRead(A0);
  	float measuredVoltage = (analogVoltage * 5.0) / 1024.0;
  	float inputVoltage = measuredVoltage * voltageDivisor;

  //round voltage down to 0
  if (inputVoltage < 0.1){
  inputVoltage = 0.0;
  }

  //print voltage to the serial monitor
  Serial.print("v=");
  Serial.println(inputVoltage);

  //overwrite the 2nd row
  lcd.setCursor(0, 1);

  //print voltage to lcd screen in user friendly mannr
  lcd.print("Voltage=");
  lcd.print(inputVoltage);

  //pause for 300 milliseconds
  delay(300);
}
