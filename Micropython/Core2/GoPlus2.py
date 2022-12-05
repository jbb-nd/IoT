from m5stack import *
from m5stack_ui import *
from uiflow import *
import module

import time

screen = M5Screen()
screen.clean_screen()
screen.set_screen_bg_color(0xFFFFFF)

go_plus_2 = module.get(module.GOPLUS2)

go_plus_2.set_servo_angle(go_plus_2.S1, 0)
while True:
  go_plus_2.set_servo_angle(go_plus_2.S1, 90)
  wait(2)
  go_plus_2.set_servo_angle(go_plus_2.S1, 0)
  wait(2)
  wait_ms(2)