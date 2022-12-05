"""
Blynk is a platform with iOS and Android apps to control
Arduino, Raspberry Pi and the likes over the Internet.
You can easily build graphic interfaces for all your
projects by simply dragging and dropping widgets.

  Downloads, docs, tutorials: http://www.blynk.cc
  Sketch generator:           http://examples.blynk.cc
  Blynk community:            http://community.blynk.cc
  Social networks:            http://www.fb.com/blynkapp
                              http://twitter.com/blynk_app

This example shows how to initialize your ESP8266/ESP32 board
and connect it to Blynk.

Don't forget to change WIFI_SSID, WIFI_PASS and BLYNK_AUTH ;)
"""
from m5stack import *
from m5stack_ui import *
from uiflow import *

import M5BlynkLib
import network
import machine

WIFI_SSID = 'ATTR9tNp5S'
WIFI_PASS = '8jx5cda9hpg='

BLYNK_AUTH = 'L1_427mM05GzJ-M4Hl_npXIT6iSJ59nT' # Quickstart

lcd.fill(0x000000)
lcd.clear()
lcd.print('')

wifi = network.WLAN(network.STA_IF)
if not wifi.isconnected():
    lcd.println("Connecting to WiFi...")
    wifi.active(True)
    wifi.connect(WIFI_SSID, WIFI_PASS)
    while not wifi.isconnected():
        pass

lcd.print('IP:')
lcd.println(wifi.ifconfig()[0])

blynk = BlynkLib.Blynk(BLYNK_AUTH)

@blynk.on("connected")
def blynk_connected(ping):
    lcd.print('Blynk ready. Ping:')
    lcd.print(ping)
    lcd.println('ms')

@blynk.on("disconnected")
def blynk_disconnected():
    lcd.println('Blynk disconnected')

def runLoop():
    while True:
        blynk.run()
        machine.idle()

# Run blynk in the main thread
runLoop()

# You can also run blynk in a separate thread (ESP32 only)
#import _thread
#_thread.stack_size(5*1024)
#_thread.start_new_thread(runLoop, ())

