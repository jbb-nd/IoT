#define BLYNK_TEMPLATE_ID "TMPLAEA79-rw"
#define BLYNK_DEVICE_NAME "My First Template"

#include <Arduino.h>
#include <BlynkSimpleEsp32.h>
#include <M5Atom.h>
// #include <FastLED.h>

// #define BLYNK_TEMPLATE_ID "TMPLL4WdTR8s"
// #define BLYNK_DEVICE_NAME "ProximityMonitor"
// char auth[] = "4xWiS_fcSAcY1yI7KYBa-EkaVs83JXPU";

// char ssid[] = "ND-guest";
// char pass[] = "";

char ssid[] = "ATTR9tNp5S";
char pass[] = "8jx5cda9hpg=";

char auth[] = "TUY6iHNgWq0FA8Ueq9_Lrw4O6axRlqjP";


// BLYNK_WRITE(V0){
//   int button_value = param.asInt();
//   if (button_value == 1)
//     M5.dis.fillpix(0xff0000);
//   else
//     M5.dis.fillpix(0x00ff00);
// }

void setup() {
  // M5.begin(true,false,true);
  M5.begin(true, true, true);
  Blynk.begin(auth, ssid, pass);
  M5.dis.fillpix(0x0000ff);
}

void loop() {
  Blynk.run();
  // if (M5.Btn.wasPressed()){
  //   M5.dis.fillpix(0xff0000);
  // }else{
  //   M5.dis.fillpix(0x00ff00);
  // }
  M5.dis.fillpix(0xff0000);
  delay(1000);
  M5.dis.fillpix(0x000000);
  delay(1000);
}