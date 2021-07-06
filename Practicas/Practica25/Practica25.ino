const int LDRPin = A0;

//#include "Part1.h"
#include "Part2.h"

void setup() {
  Serial.begin(9600);
  pinMode(LDRPin,INPUT);
  initProg();
}


void loop() {
  runner();
}
