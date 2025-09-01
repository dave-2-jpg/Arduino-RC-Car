#include<IRremote.h>
const int RemotePin = 12;
int in1 = 4;
int in2 = 2;
int in3 = 10;
int in4 = 8;

int ena = 5;
int enb = 9;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RemotePin, ENABLE_LED_FEEDBACK);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
    
}
void Forward()
  {
  analogWrite(ena, 200);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enb, 200);
  digitalWrite(in3,HIGH);  
  digitalWrite(in4,LOW);   
  }
 void Backward()
  {
  analogWrite(ena, 200);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enb, 200);
  digitalWrite(in3,LOW);  
  digitalWrite(in4,HIGH);
  }
 void Stop()
  {
  analogWrite(ena, 0);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  analogWrite(enb, 0);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
  int Left()
    {
    analogWrite(ena, 0);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    analogWrite(enb, 200);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    }
  int Right()
    {
    analogWrite(ena, 200);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enb, 0);
    digitalWrite(in3,LOW);   
    digitalWrite(in4,LOW);
    }

unsigned long lastCode = 0;  // store last valid button

void loop() {
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.decodedRawData; //decode the data

    // If repeat, use last stored code
    if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) { 
      code = lastCode;
    } else {
      lastCode = code;  // update lastCode only on new press
    }

    if (code == 0xB946FF00) { // UP
      Forward();
    }
    else if (code == 0xEA15FF00) { // DOWN
      Backward();
    }
    else if (code == 0xBB44FF00) { // LEFT
      Left();
    }
    else if (code == 0xBC43FF00) { // RIGHT
      Right();
    }
    else {
      Stop();
    }

    IrReceiver.resume(); // ready for next signal
  }
}


      

