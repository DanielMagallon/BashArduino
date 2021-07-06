#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_

    void setMessage(String grados,LiquidCrystal lcd)
    {
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Girando:");
              lcd.setCursor(3,1);
              lcd.print(grados);
    }

    void giro0_179(Servo servoMotor,LiquidCrystal lcd)
    {
    
        int i=0;
        int delay2=100;
        for(; i<=180; i+=5)
        {
              Serial.println("Girando: "+String(i)+"°");
              setMessage(String(i)+" gdos",lcd);
              servoMotor.write(i);   
              delay(delay2);
        }
        
        i-=5;
        
        for(; i>=0; i-=5)
        {
              Serial.println("Girando: "+String(i)+"°");
              setMessage(String(i)+" gdos",lcd);
              servoMotor.write(i);   
              delay(delay2);
        }
    }
    
    
    const int potencioMetroPin = A0;
    int sensorValue = 0; // valor leído desde el potenciómetro
    int outputValue = 0; // valor de la salida PWM (salida analógica)
    
    void giroPorPotenciometro(Servo servoMotor,LiquidCrystal lcd)
    {
        sensorValue = analogRead(potencioMetroPin);
        outputValue = map(sensorValue, 0, 1023, 0, 180);
        
        Serial.println("Grado a rotar: "+String(outputValue));
        servoMotor.write(outputValue);   
      //  lcd.clear();
        //lcd.setCursor(0,0);
        //lcd.print("Grado Rotacion");
        //lcd.setCursor(3,1);
        //lcd.print(String(outputValue));
        delay(100);
    }

    const int BUTTONPIN_LEFT = 5, BUTTONPIN_MIDLE = 4, BUTTONPIN_RIGTH = 3;
    void setupButtons()
    {
        pinMode(BUTTONPIN_LEFT,INPUT);
        pinMode(BUTTONPIN_MIDLE,INPUT);
        pinMode(BUTTONPIN_RIGTH,INPUT);
    }

    void getStateButton(Servo servoMotor)
    {
        int reader = digitalRead(BUTTONPIN_LEFT);
        
        if(reader)
        {
           Serial.println("Se presiono el boton izq");   
           servoMotor.write(0);
        }else{
          reader = digitalRead(BUTTONPIN_MIDLE);

            if(reader)
            {
              Serial.println("Se presiono el boton en medio");   
              servoMotor.write(90);
            }
            else{
                reader = digitalRead(BUTTONPIN_RIGTH);
              if(reader)
              {
                Serial.println("Se presiono el boton derecho");   
                servoMotor.write(180);
              }
            }
        }
    }
    
#endif //_HEADER_FILE_H_
