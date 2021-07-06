#include <IRremote.h>
#define pinLampara 13
#include "IRKeys.h"
#include "P1_led.h"
#include "7display.h"

int RECV_PIN = 12; 
IRrecv irrecv(RECV_PIN);
decode_results results;




void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  initProg();
  init7display();
  pinMode(pinLampara,OUTPUT);
  digitalWrite(pinLampara,HIGH);
   servoMotor.attach(11);
}

void loop() {
      
  if (irrecv.decode(&results)) { 

      Serial.println(results.value, HEX); 
      runner(results,&printNumber);
      irrecv.resume(); 
    }

   more();
  delay(100); 
}
