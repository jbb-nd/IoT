from m5stack import *
from m5ui import *
from uiflow import *
import hat

setScreenColor(0x111111)

hat_8servos_1 = hat.get(hat.SERVO8)
hat_8servos_1.write_servo_angle(1,0)