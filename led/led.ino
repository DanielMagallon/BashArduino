const int ledPIN = 10;
const int analogInput = A0;
int inputValue=0;

int option;
 
void setup(){
  Serial.begin(9600);
  pinMode(ledPIN , OUTPUT); 
}
 
void loop(){
  //si existe información pendiente
  if (Serial.available()>0){
    //leeemos la opcion
    char option = Serial.read();
    //si la opcion esta entre '1' y '9'
    if (option >= '1' && option <= '9')
    {
      //restamos el valor '0' para obtener el numero enviado
      option -= '0';
      for(int i=0;i<option;i++){
         digitalWrite(ledPIN , HIGH);
         delay(1000);
         digitalWrite(ledPIN , LOW);
         delay(2000);
      }
    }
  }
  
 /* inputValue = analogRead(analogInput);
  Serial.print("Voltaje de entrada = " );
  Serial.println(inputValue);
  delay(2);*/
}
 
