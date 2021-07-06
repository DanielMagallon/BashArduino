const int led=13;
const int boton=11;
int val;

void setup() {  
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(boton,INPUT);
}

void loop() {
    val = digitalRead(boton);

    String statusled = val ? "On" : "Off";
    Serial.println("El led esta: "+statusled);
  
    digitalWrite(led, val);
    delay(500);
    
}
