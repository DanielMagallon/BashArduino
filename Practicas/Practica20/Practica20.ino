//179 anexo
#define pinBuzzer 8
#define pinPotenc A0

int index=0;
int pinLeft = 4;
int pinRigth = 3;

void verificarIndex()
{
    int state = digitalRead(pinRigth);

    if(state){
      index++;

      if(index==3)
        index=0;
    }else{
      state = digitalRead(pinLeft);

      if(state)
      {
        index--;

        if(index==-1)
          index=2;
      }
    }

    Serial.println("Index: "+String(index));
}

#include "pitches.h"
#include "pacmantheme.h"
#include "soundthemes.h"



void setup() {
    pinMode(pinBuzzer, OUTPUT);
    pinMode(pinPotenc, INPUT);
    pinMode(pinLeft,INPUT);
    pinMode(pinRigth,INPUT);
    
    Serial.begin(9600);
}

void alarma(int toneB)
{
  tone(pinBuzzer, toneB, 600);
   delay(1000);
}

void medidor()
{
  tone(pinBuzzer, 1000, 100);
   delay(1000);
}

int getValPot()
{
    int sensorValue = analogRead(pinPotenc);  

    return map(sensorValue, 0, 1023, 0, 2000);
}


void loop() {
    //alarma(getValPot());
   // medidor();
    sing(index,pinBuzzer);
}
