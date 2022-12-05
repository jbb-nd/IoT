/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPLAEA79-rw"
#define BLYNK_DEVICE_NAME "My First Template"

#include <Arduino.h>
// #include <WiFi.h>
// #include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "M5Atom.h"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "XXXX";

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "ND-guest";
char pass[] = "";


BLYNK_WRITE(V0)
{
  int button_value = param.asInt();
  if (button_value == 1)
    // M5.Lcd.fillScreen(GREEN);
    M5.dis.fillpix(0x00ff00);
  else
    // M5.Lcd.fillScreen(RED);
    M5.dis.fillpix(0xff0000);
}

void setup()
{
  // Debug console
  // Serial.begin(9600);
  M5.begin(true, true, true);
  // M5.Lcd.fillScreen(BLUE);
  M5.dis.fillpix(0x0000ff);
  // M5.Lcd.setTextColor(BLACK);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  M5.update();
  if (M5.Btn.isPressed()) {
    // M5.Lcd.fillScreen(WHITE);
    M5.dis.fillpix(0xffffff);
    Blynk.virtualWrite(V2, 1);
  }
  else if (M5.Btn.isReleased()) {
    Blynk.virtualWrite(V2, 0);
  }
}

