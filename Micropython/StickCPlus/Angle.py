from m5stack import *
from m5ui import *
from uiflow import *
import unit

setScreenColor(0x111111)
angle_0 = unit.get(unit.ANGLE, unit.PORTA)

label0 = M5TextBox(50, 94, "label0", lcd.FONT_Default, 0xFFFFFF, rotate=0)

while True:
  label0.setText(str(angle_0.read()))
  wait_ms(2)