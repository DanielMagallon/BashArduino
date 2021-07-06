const int LEDPines[] = {2,3,4,5,7};
const int MICRO = A0;
const int pinBuzzer = 6;
const int boton = 8;
const int lampara = 13;


void setup() {
  for(int i=0; i<5; i++)
  {
    pinMode(LEDPines[i], OUTPUT);
    digitalWrite(LEDPines[i],HIGH);
  }
  
  Serial.begin(9600);
  pinMode(MICRO, INPUT);
  pinMode(boton,INPUT);
  pinMode(lampara,OUTPUT);
  
}

void alarma(int toneB)
{
  tone(pinBuzzer, toneB, 600);
   delay(1000);
}

    int pinNivelAlto = 7;
    int pinNivelMedio[] = {4,5};
    int pinNivelBajo[] = {2,3};
    
    void nivel_alto(bool turnOn);
    void nivel_bajo(bool turnOn);
    void nivel_medio(bool turnOn);

    void nivel_alto(bool turnOn)
    {   
        digitalWrite(pinNivelAlto,turnOn);
        
        if(turnOn)
        {
            nivel_medio(!turnOn);
            nivel_bajo(!turnOn);
        }        
    }
    
    void nivel_medio(bool turnOn)
    {
        for(int i=0; i<2; i++)
        {   
            digitalWrite(pinNivelMedio[i],turnOn);
        }
        
         if(turnOn)
        {
            nivel_alto(!turnOn);
            nivel_bajo(!turnOn);
        }  
    }
    
    void nivel_bajo(bool turnOn)
    {
        for(int i=0; i<2; i++)
        {   
            digitalWrite(pinNivelBajo[i],turnOn);
        }
        
        if(turnOn)
        {
            nivel_medio(!turnOn);
            nivel_alto(!turnOn);
        }  
    }
    


   void apagarTodo(){
    for(int i=0; i<2; i++)
        {   
            digitalWrite(pinNivelBajo[i],0);
        }
        
        
        digitalWrite(pinNivelAlto,0);
        
        
        for(int i=0; i<2; i++)
        {   
            digitalWrite(pinNivelMedio[i],0);
        }
        
    }

boolean activate;

void loop() {
   int value = analogRead(MICRO);

  Serial.println(String(value));

  if(value>=900)
  {
     nivel_bajo(true);
     digitalWrite(lampara, false);
     alarma(1000);
      
  }else if(value>=28)
  {
    digitalWrite(lampara, true);
    nivel_medio(true);
   
  }else if(value>=25){
    digitalWrite(lampara, true);
   nivel_alto(true);
  }else{
   apagarTodo(); 
  }
  
  delay(100);
//  if(!activate)
//  {
//    activate= value == HIGH;
//  }
//
//  else{
//    digitalWrite(LEDPin, HIGH);
//     digitalWrite(lampara, false);
//    alarma(1000);
//    int valBtn = digitalRead(boton);
//
//    Serial.println(String("Bt: ")+valBtn);
//    
//    if(valBtn)
//    {
//      
//        digitalWrite(LEDPin, LOW);
//        digitalWrite(lampara, true);
//        activate=false;
//    }
//  }
}
