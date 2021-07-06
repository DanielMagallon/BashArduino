const int analogInPin = A0;
const int analogOutPin = 9;
int sensorValue = 0; // valor leído desde el potenciómetro
int outputValue = 0; // valor de la salida PWM (salida analógica)

void setup() 
{
    Serial.begin(9600);
}

void loop() {
    // Lectura de la entrada analógica
    sensorValue = analogRead(analogInPin);

    // Ubica el valor de la entrada en el rango de la salida analógica
    outputValue = map(sensorValue, 0, 1023, 0, 255);

    // Cambia el valor de salida analógica
    analogWrite(analogOutPin, outputValue);


    // muestra el resultado en el Serial Monitor:
    Serial.print("sensor = " );
    Serial.print(sensorValue);
    Serial.print("\t output = ");
    Serial.println(outputValue);
    
    //delay(500);
}
