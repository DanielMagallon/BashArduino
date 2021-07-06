const int N=8;
const int pines[N] = {4,5,6,7,8,9,10,11};
int delay2=100;
void setup() {
  Serial.begin(9600);
  for (int i=0; i<N; i++){
    pinMode(pines[i], OUTPUT);
    digitalWrite(pines[i], LOW);//apagar
  }
}

void checkSerial()
{
  int aux;
  if(Serial.available()!=0)
  {
    
      aux = Serial.parseInt();
      if(aux!=0)
        delay2=aux;
      Serial.flush();
  }
}

int row=0;
void loop() {
  
  digitalWrite(pines[N-1],LOW);
  for (int i=0; i<N; i++){
    checkSerial();
    if(i>0)
    {
      digitalWrite(pines[i-1], LOW);//prende led
    }
    digitalWrite(pines[i], HIGH);//prende led
    delay(delay2);
  }
}
