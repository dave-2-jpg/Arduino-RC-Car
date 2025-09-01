const int ena = 3;
const int in1 = 4;
const int in2 = 2;

const int enb = 9;
const int in4 = 8;
const int in3 = 7;

const int button = 11;



#include <Servo.h>
Servo myservo;

void setup() {
 pinMode(ena, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);

 pinMode(enb, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
 pinMode(button, INPUT_PULLUP);
Serial.begin(9600);

 
}

void loop() {
  int buttonVal = digitalRead(button);
  Serial.println(buttonVal);
  
  if (buttonVal == 0) {
  analogWrite(ena, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enb, 255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(10000);
  analogWrite(ena, 0);
  analogWrite(enb,0);
  
  }
  else {
    analogWrite(enb, 0);
    analogWrite(ena, 0);
  }
  

}

