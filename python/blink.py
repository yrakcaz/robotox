#! env python2.7
import time

f = open("/sys/class/gpio/gpio4/value", "w+")

while True:
  time.sleep(0.1)
  s = f.read()
  f.seek(0)
  if s[0] == "0":
    f.write("1")
  elif s[0] == "1":
    f.write("0")
 
