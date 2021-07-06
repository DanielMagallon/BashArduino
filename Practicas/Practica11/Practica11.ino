#include  <LiquidCrystal.h>

// CONSTRUCTOR PARA LA PANTALLA LCD 16X2
// AQUI SE CONFIGURAN LOS PINES PARA LA COMUNICACION CON LA PANTALLA
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String cadena="Edgar Daniel";
void caracteresPersonalizados();

void inicio()
{
  lcd.clear();
  lcd.print(cadena);
  
  lcd.setCursor ( 0, 1 );
  
  lcd.print("Magallon Vill");
  
 
  delay(1000);
}

void setup()
{
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  
  lcd.home();
  
  inicio();

  //caracteresPersonalizados();
}

void valorSensor()
{
   lcd.clear();
  // IMPRIMIR UN ENCABEZADO
  lcd.print(" POTENCIOMETRO  ");

  // REALIZAR LECTURA ANALOGICA EN PIN A0
  unsigned int val = analogRead(A0);
  // CONVERTIR ESE VALOR A VOLTAJE (ASUMIENDO QUE EL ARDUINO SE ALIMENTA A 5 VOLTS)
  float volts = (val * 5.0) / 1024.0;

  // IMPRIMIR VALORES EN LA SEGUNDA LINEA, COMENZANDO POR EL VALOR DIRECTO DEL ADC
  lcd.setCursor(0, 1);
  lcd.print(val);

  // IMPRIMIR EL VALOR EN VOLTAJE, DESPUES DE LA LECTURA DEL ADC
  lcd.setCursor(6, 1);
  lcd.print(volts, 1);

  // ESPERAR UN SEGUNDO ANTES DE CONTUNUAR
  delay (1000);
}

void mensajesAnimados()
{
    
  // DESPLAZAR LA PANTALLA A LA DERECHA 2 VECES
  for ( int i = 0; i < 5; i++ ) {
    lcd.scrollDisplayRight();
    delay (1000);
  }

  // DESPLAZAR LA PANTALLA A LA IZQUIERDA 2 VECES
  for ( int i = 0; i < 5; i++ ) {
    lcd.scrollDisplayLeft();
    delay (1000);
  }
}

void mensajesPorSerial()
{
  
  if(Serial.available())
  {
      cadena=Serial.readString();
      cadena.replace("\n","");
      delay(800);
      Serial.println("Nueva: "+cadena);
      Serial.flush();
      lcd.setCursor ( 0, 1 );
      lcd.clear();
      lcd.print(cadena);
  }
}

void caracteresPersonalizados(){

  byte smile[8] = 
  {
    0b00000000,
    0b00001010,
    0b00001010,
    0b00001010,
    0b00000000,
    0b00010001,
    0b00001110,
    0b00000000,
  };

  byte sad[8] = {
  0b00000000,
  0b00001010,
  0b00001010,
  0b00001010,
  0b00000000,
  0b00001110,
  0b00010001,
  0b00000000,
  };
  
  byte body[8] = {
    0b00001110,
    0b00001110,
    0b00000100,
    0b00011111,
    0b00000100,
    0b00001010,
    0b00010001,
    0b00000000,
  };
  
  byte arrowr[8] = {
    0b00001000,
    0b00000100,
    0b00000010,
    0b00011111,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00000000,
  };
  
  byte arrowu[8] = {
    0b00000100,
    0b00001110,
    0b00010101,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000000,
  };
  
  byte arrowd[8] = {
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00010101,
    0b00001110,
    0b00000100,
    0b00000000,
  };
  
  byte arrowl[8] = {
    0b00000010,
    0b00000100,
    0b00001000,
    0b00011111,
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000000,
  };

  lcd.createChar (0, smile);
  lcd.createChar (1, sad);
  lcd.createChar (2, body);
  lcd.createChar (3, arrowr);
  lcd.createChar (4, arrowu);
  lcd.createChar (5, arrowd);
  lcd.createChar (7, arrowl);

   // LIMPIAR LA PANTALLA Y MOVER EL CURSOR A LA PRIMERA POSICION
  lcd.clear();
  // IMPRIMIR TITULO EN LA PRIMERA LINEA
  lcd.print(" Mis Caracteres ");
  // MOVER EL CURSOR A LA SEGUNDA LINEA
  lcd.setCursor(0, 1);

  // AHORA ESCRIBIMOS (MOSTRAMOS) LOS CARACTERES A LA PANTALLA
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.write((byte)3);
  lcd.write((byte)4);
  lcd.write((byte)5);
  lcd.write((byte)7);
}

void mensajesXSensor(){

    int MAX=8;
    int rangos[MAX] = {60,100,150,200,250,300,350,400};
    lcd.clear();
    String mensajes[MAX][2] = { 
        {"Edgar","Daniel"},  
        {"Tony","Stark"},  
        {"Veronica","Villa"},  

        {"#Hail","Linux"},
        {"Steve","Rogers"},  
        
        {"Scarlet","Johanson"},
        {"Elizabeth","Olsen"},
        
        {"Vegetta","777"},
        
    };

    unsigned int sensorValue = analogRead(A0);

    for(int i=0; i<MAX; i++)
    {
        if(sensorValue<=rangos[i])
        { 
            lcd.setCursor(0, 0);
            lcd.print(mensajes[i][0]);
            int caret=mensajes[i][0].length()+3;
            Serial.println("Caret: "+String(caret));
            lcd.setCursor(caret,0);
            lcd.print(sensorValue);
            lcd.setCursor(0, 1);
            lcd.print(mensajes[i][1]);
            break;
        }
        
    }

    delay(1000);
}

void loop()
{
   //mensajesAnimados();
  //mensajesXSensor();
  //mensajesPorSerial();
}
