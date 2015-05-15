#! /usr/bin/python2.7

import RPi.GPIO as gpio

gpio.setmode(gpio.BCM)
gpio.setup(4, gpio.IN)

while True:
  input_value = gpio.input(4)
  if input_value == False:
    print("The button has been pressed") 
