/* 
  Quickstart Datastreams
  V0: switch control (int 0/1)
  V1: switch value   (int 0/1)
  V2: seconds        (int 0, 1000000)
  V3: image          (string )

  My First Template Datastreams (Bridge Device B)
  V0: DashButton     (int 0, 1)
  V1: Data           (int 0, 65535)
  V2: DeviceButton   (int 0, 1)
*/

#define BLYNK_TEMPLATE_ID           "TMPLgwrzfHok"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "L1_427mM05GzJ-M4Hl_npXIT6iSJ59nT"
#define BLYNK_AUTH_TOKEN_B          "TUY6iHNgWq0FA8Ueq9_Lrw4O6axRlqjP"
#define MY_SSID                     "ND-guest"
#define MY_PASS                     ""

// #define BLYNK_PRINT Serial

#include <Arduino.h>
#include <BlynkSimpleEsp32.h>
#include <M5Atom.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = MY_SSID;
char pass[] = MY_PASS;

WidgetBridge bridge1(V1);
BlynkTimer timer;

BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

//   // Update state
  Blynk.virtualWrite(V1, value);
  // Light up LED on bridged device B
  bridge1.virtualWrite(V0, value);
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

BLYNK_CONNECTED() {
  bridge1.setAuthToken(BLYNK_AUTH_TOKEN_B); // Place the AuthToken of the second hardware here
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  
  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}