#Arduino board is connected to Raspi through USB
#all sensor GPS, compass are connected to Arduino
#Arduino reads all sensor data and send it to Raspi using byte array which again send to android client

import socket
import sys
import RPi.GPIO as GPIO
import serial

#create serial object on arduino connect USB port
data=serial.Serial('/dev/ttyUSB0',115200,timeout=0)

#Start server on static assign IP of Raspi
HOST="192.168.43.146"
PORT=4444
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((HOST,PORT))
s.listen(5)

#set GPIO for logic of motor driver
GPIO.setmode(GPIO.BCM)

GPIO.setup(2, GPIO.OUT)
GPIO.setup(3, GPIO.OUT)
GPIO.setup(4, GPIO.OUT)
GPIO.setup(5, GPIO.OUT)

#initialize all IO to digital low
GPIO.output(2, 0)
GPIO.output(3, 0)
GPIO.output(4, 0)
GPIO.output(5, 0)

while True:
	#accept connection from android client
	c,addr=s.accept()
	#set client timeout to be one sec
	c.settimeout(1)
	while True:
		#wait until data is read from arduino board
		Data1=data.readline()
		
		#check if correct string is received from arduino
		if(Data1.startswith("12345")==True):
			#send receive arduino data to android client
			c.send(Data1)
		try:
			#check if any data received from the android client
			data=c.recv(1)
		
		except socket.timeout,e:
			#allow socket time out error
			err=e.args[0]
	
		print 'data',data
		#if U received forword
		if data=='U':
			GPIO.output(2, 1)
			GPIO.output(3, 0)
			GPIO.output(4, 1)
			GPIO.output(5, 0)
			
		#if R received right turn
		elif data=='R':
			GPIO.output(2, 1)
			GPIO.output(3, 0)
			GPIO.output(4, 0)
			GPIO.output(5, 0)
		
		#if L left turn
		elif data=='L':
			GPIO.output(2, 0)
			GPIO.output(3, 0)
			GPIO.output(4, 1)
			GPIO.output(5, 0)
		
		#if D reverse
		elif data=='D':
			GPIO.output(2, 0)
			GPIO.output(3, 1)
			GPIO.output(4, 0)
			GPIO.output(5, 1)
        
		#if N reverse Right
		elif data=='N':
			GPIO.output(2, 0)
			GPIO.output(3, 0)
			GPIO.output(4, 0)
			GPIO.output(5, 1)
		
		#if P reverse left turn 
		elif data=='P':
			GPIO.output(2, 0)
			GPIO.output(3, 1)
			GPIO.output(4, 0)
			GPIO.output(5, 0)
		
		# if S stop robot
		elif data=='S':
			GPIO.output(2, 0)
			GPIO.output(3, 0)
			GPIO.output(4, 0)
			GPIO.output(5, 0)
		
		#if Z break the connection and stop
		elif data=='Z':
			break
		
	c.close()
	data=0;
s.close();
