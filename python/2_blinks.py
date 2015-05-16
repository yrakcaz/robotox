#! /usr/bin/python2.7

import RPi.GPIO as gpio

gpio.setmode(gpio.BCM)

gpio.setup(18, gpio.OUT)
gpio.setup(23, gpio.OUT)

count = 0
max_count = 700
while True:
  if count >= max_count:
    count = 0

  if count < max_count / 2:
    gpio.output(18, True)
    gpio.output(23, False)
  else:
    gpio.output(23, True)
    gpio.output(18, False)
  count += 1
  print(count)
