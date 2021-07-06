void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

int delay2 = 1000;
void checkSerial()
{
  int aux;
  if (Serial.available() != 0)
  {

    aux = Serial.parseInt();
    if (aux != 0)
      delay2 = aux;
    Serial.flush();
  }
}

void loop() {

  digitalWrite(13, HIGH);
  delay(delay2);
  digitalWrite(13, LOW);
  delay(delay2);
  checkSerial();
}
