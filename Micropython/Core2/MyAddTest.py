from m5stack import * 
import MyAddLib

lcd.clear()
lcd.print('', 0, 0)
lcd.print('Value = ')
lcd.println(MyAddLib.my_add_fun(3, 4))
