#if ARDUINO > 10605
#include <Keyboard.h>
#endif

void setup() {
  Keyboard.begin();
  delay(5000);
}
 
void loop() {
  Keyboard.println("Hola mundo!");
  delay(1000);
}
