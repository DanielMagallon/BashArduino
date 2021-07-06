#define pinServo 9
#define LDR_LFT A0
#define LDR_RGT A1

#include <Servo.h>

Servo servoMotor;

void setup() {
    pinMode(LDR_LFT,INPUT);
    pinMode(LDR_RGT,INPUT);
    pinMode(pinServo,OUTPUT);
    Serial.begin(9600);
    servoMotor.attach(pinServo);
}

void loop() {
      
      int ilumL = analogRead(LDR_LFT);         
      int ilumR = analogRead(LDR_RGT);
      
      Serial.println("LDR_IZQ: "+String(ilumL));
      Serial.println("LDR_DER: "+String(ilumR));

      if(ilumL>200)
      {
         servoMotor.write(0);
      }
      else if(ilumR>200)
      {
         servoMotor.write(180);
      }else{
         servoMotor.write(90);
      }

}
