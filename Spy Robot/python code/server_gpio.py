#!/usr/bin/python           # This is server.py file

import socket   # Import socket module
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

GPIO.setup(17,GPIO.OUT)



s = socket.socket()         # Create a socket object
host = '192.168.43.99'        # Get local machine name
port = 5000               # Reserve a port for your service.
s.bind((host, port))        # Bind to the port

s.listen(5)         # Now wait for client connection.

while True:
   
   c, addr = s.accept()     # Establish connection with client.
   print 'Got connection from', addr
   c.send('thank you')
   while True:
	data= c.recv(1024)
	print data
	if(data=="HIGH"):
		GPIO.output(17,GPIO.HIGH)
	if(data=="LOW"):
		GPIO.output(17,GPIO.LOW)
c.close
