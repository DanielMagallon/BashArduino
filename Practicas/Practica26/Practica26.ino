const int LEDPin = 7;
const int PIRPin = 9;
const int pinBuzzer = 6;
const int boton = 8;
const int lampara = 13;


void setup() {
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
  pinMode(PIRPin, INPUT);
  pinMode(boton,INPUT);
  pinMode(lampara,OUTPUT);
  
}

void alarma(int toneB)
{
  tone(pinBuzzer, toneB, 600);
   delay(1000);
}



boolean activate;

void loop() {
  int value= digitalRead(PIRPin);
  
  if(!activate)
  {
    activate= value == HIGH;
  }

  else{
    digitalWrite(LEDPin, HIGH);
     digitalWrite(lampara, false);
    alarma(1000);
    int valBtn = digitalRead(boton);

    Serial.println(String("Bt: ")+valBtn);
    
    if(valBtn)
    {
      
        digitalWrite(LEDPin, LOW);
        digitalWrite(lampara, true);
        activate=false;
    }
  }
}
