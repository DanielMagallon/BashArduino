#include "SoundLeds.h"

int pinSequence[10] = {2,3,4,5,6,7,8,9,10,12};

int pinMicro = A0;

void setup() {

  Serial.begin(9600);

  for(int i=0; i<10; i++)
  {
      pinMode(pinSequence[i],OUTPUT);
      digitalWrite(pinSequence[i],LOW);
  }

  pinMode(pinMicro,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int value = analogRead(pinMicro);

  Serial.println(String(value));

  if(value>=1000)
  {
      nivel_alto(true);
  }else if(value>=300)
  {
    nivel_medio(true);
  }else if(value>=25){
    nivel_bajo(true);
  }else{
   apagarTodo(); 
  }

  
}
