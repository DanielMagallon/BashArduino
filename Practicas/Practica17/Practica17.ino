#include <Servo.h>
#include  <LiquidCrystal.h>
#include "ServoData.h"



LiquidCrystal  lcd(12, 11, 5, 4, 3, 2);

Servo  servoMotor;

void setup() {
  
  Serial.begin (115200);
  lcd.begin (16, 2);
  lcd.home();
  lcd.setCursor(0,0);
  lcd.clear();
   lcd.print("Hello");
   
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(8);

  //setupButtons();
}

void loop() {  
  //giro0_179(servoMotor,lcd);
  giroPorPotenciometro(servoMotor,lcd);
 // getStateButton(servoMotor);
 // delay(200);
}
