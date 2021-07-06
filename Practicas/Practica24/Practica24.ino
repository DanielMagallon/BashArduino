//#include  <LiquidCrystal.h>
#include "DHT.h"
#include "SevSeg.h"

SevSeg sevseg; 
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Definimos el pin digital donde se conecta el sensor
#define DHTPIN A0
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

//#define pinVentilador 9
//#define pinLampara 10

void setup() {

Serial.begin(9600);
 byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_ANODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  dht.begin();
  pinMode(DHTPIN,INPUT);
  
//  lcd.begin(16, 2);
//  pinMode(pinVentilador, OUTPUT);
//  pinMode(pinLampara, OUTPUT);
//  editValsRelay(false,false);
//  lcd.home();
//  
//  Serial.begin(9600);
//  lcd.clear();
 
}
//
//void editValsRelay(boolean rl1, boolean rl2)
//{
//  digitalWrite(pinVentilador, !rl1);   
//  digitalWrite(pinLampara, !rl2);   
//}

void showTempDisp(){
 float t = dht.readTemperature();
 
      if(!isnan(t)){
        String val = String(t);
        val.replace(".","");
        int v = val.toInt();
        Serial.println("T: "+String(val));
        sevseg.setNumber(v,2);
        
        sevseg.refreshDisplay();    
        delay(2);
       } 
}

void loop() {

  //delay(100);
     
   // Leemos la humedad relativa
  //float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  //float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahrenheit
  //float f = dht.readTemperature(true);
  
  //lcd.clear();
  // Comprobamos si ha habido algún error en la lectura
//  if (isnan(t)){// || isnan(t) || isnan(f)) {
//
//    Serial.println("Error al obtener datos");
//  }
//  else
  {

 // float hif = dht.computeHeatIndex(f, h);
  //float hic = dht.computeHeatIndex(t, h, false);


//    if(t<=35){
//        editValsRelay(false,true);
//    }else if(t>35 && t<31){
//      editValsRelay(false,false);
//    }else{
//      editValsRelay(true,false);
//    }

      
     

    
//    lcd.print("HUM  "+String(h)+"  %");
//    lcd.setCursor(0,1);
//    lcd.print("TEMP "+String(t)+"C "+String(f)+"F");
//    Serial.print("Humedad: ");
//    Serial.print(h);
//    Serial.print(" %\t");
    //Serial.print("Temperatura: ");
    //Serial.print(t);
    //Serial.print(" *C ");
//    Serial.print(f);
//    Serial.print(" *F\t");
//    Serial.print("Índice de calor: ");
//    Serial.print(hic);
//    Serial.print(" *C ");
//    Serial.print(hif);
//    Serial.println(" *F");
  }

  showTempDisp();
  
}
