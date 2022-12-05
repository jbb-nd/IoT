#include <Arduino.h>
#include "M5Atom.h"

void setup(){
    M5.begin(true, true, true);
}

void loop(){
  M5.dis.fillpix(0xff0000);
  delay(1000);
  M5.dis.fillpix(0x000000);
  delay(1000);
}