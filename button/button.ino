const int ledPIN = 10;
const int pulsador=4, pulsador8=8;
int val=0;
bool pressed=false;

void setup(){

  Serial.begin(9600);
  pinMode(ledPIN , OUTPUT); 
  pinMode(pulsador,INPUT_PULLUP);
  pinMode(pulsador8,INPUT_PULLUP);
}
 
void loop(){
  
  val = digitalRead(pulsador);

  if(val == HIGH)
  {
      if(!pressed)
      {
        digitalWrite(ledPIN,HIGH);
        Serial.println("spotify");
        pressed=true;
        delay(500);
      }
    
  }else{

    val = digitalRead(pulsador8);
    
    if(val == HIGH)
    {
        digitalWrite(ledPIN,HIGH);
        Serial.println("konsole");
        delay(500);
    }
    
    else
    {
      digitalWrite(ledPIN,LOW); 
      pressed=false;
    }
  }
 /* inputValue = analogRead(analogInput);
  Serial.print("Voltaje de entrada = " );
  Serial.println(inputValue);
  delay(2);*/
}

 
