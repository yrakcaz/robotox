#! /usr/bin/python2.7

import RPi.GPIO as gpio

gpio.setmode(gpio.BCM)
gpio.setup(4, gpio.IN)
gpio.setup(17, gpio.IN)

gpio.setup(18, gpio.OUT)
gpio.setup(23, gpio.OUT)

pressed1 = False
pressed2 = False

while True:
  input_value1 = gpio.input(4)
  input_value2 = gpio.input(17)
 
  if pressed2 == True:
    gpio.output(18, True)
  else:
    gpio.output(18, False)

  if pressed1 == True:
    gpio.output(23, True)
  else:
    gpio.output(23, False) 
  

  if input_value1 == False:
    if pressed1 == False:
      print("The button 1 has been pressed")
    pressed1 = True
  else:
    pressed1 = False
  
  if input_value2 == False:
    if pressed2 == False:
      print("The button 2 has been pressed")
    pressed2 = True
  else:
    pressed2 = False
