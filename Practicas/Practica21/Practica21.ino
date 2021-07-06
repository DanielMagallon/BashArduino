#define pinBuzzer 13
const int Trigger = 12;
const int Echo = 11;  
#include  <LiquidCrystal.h>

LiquidCrystal lcd(7,6, 5, 4, 3, 2);

void setup() {

  lcd.begin(16, 2);
  
  lcd.home();

  Serial.begin(9600);

  pinMode(pinBuzzer,OUTPUT);

  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
}

  long tiempoEco; //timepo que demora en llegar el eco
  double disCm,disMtr;
  double disPulg; //distancia en centimetros

void sonido(int freq){
    tone(pinBuzzer, freq, 1000);
}

void loop() {

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  tiempoEco = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  disCm = tiempoEco/59;             //escalamos el tiempo a una distancia en cm
  disMtr = disCm / 100;
  disPulg = disCm / 2.54;


  if(disCm>=200)
  {
      sonido(100);
  }else if(disCm>=30)
  {
    sonido(800);
  }else{
    sonido(2000);
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Dist: "+String(disCm)+"cm");
  lcd.setCursor(0,1);
  lcd.print(String(disMtr)+"mts "+String(disPulg)+"pg");      //Enviamos serialmente el valor de la distancia 
  delay(600);      
  
}
