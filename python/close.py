#! /usr/bin/python2.7
import RPi.GPIO as gpio

gpio.setmode(gpio.BCM)
gpio.setup(18, gpio.OUT)
gpio.setup(23, gpio.OUT)

gpio.output(18, False)
gpio.output(23, False)
