#!/usr/bin/env python
import serial

if __name__ == "__main__":
	a = ""
	b = ""
	speed = ""
	rfc = serial.serial_for_url("/dev/rfcomm0")
	while (a != "q"):
		a= raw_input("a ")
		b= raw_input("b ")
		speed = a+","+b+"q"
		rfc.write(speed)
		print speed
	rfc.close()
