const int LED_RED = 2;
const int LED_YELLOW = 3;
const int LED_GREEN = 4;
const int LED_MAIN = 13;
const int LDRPin = A0;

int V,aux;

int rangos[3][2] = { {768,LED_RED},{513,LED_YELLOW},{256,LED_GREEN} };

void setup() 
{
   Serial.begin(9600);
   aux=-1;
   pinMode(LDRPin,INPUT);
   pinMode(LED_RED,OUTPUT);
   pinMode(LED_YELLOW,OUTPUT);
   pinMode(LED_GREEN,OUTPUT);
   pinMode(LED_MAIN,OUTPUT);
}

boolean cumplido;
void loop()
{
   V = analogRead(LDRPin);         

   Serial.println("Value: "+String(V));
    cumplido=false;
   for(int i=0; i<3; i++)
   {
      if(V>=rangos[i][0])
      {
          if(aux!=-1)
              digitalWrite(aux,LOW);
          aux=rangos[i][1];
          digitalWrite(LED_MAIN,LOW);
          digitalWrite(aux,HIGH);
          cumplido=true;
          break;
      }
   }

   if(!cumplido)
   {
     if(aux!=-1)
         digitalWrite(aux,LOW);

     digitalWrite(LED_MAIN,HIGH);
     
   }else digitalWrite(LED_MAIN,LOW);
   
   //ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0 
   //ilum = ((long)V*A*10)/((long)B*Rc*(1024-V));    //usar si LDR entre A0 y Vcc (como en el esquema anterior)
   
   delay(1000);
}
