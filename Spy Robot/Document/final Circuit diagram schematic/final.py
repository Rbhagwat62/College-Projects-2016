import socket
import sys
import Adafruit_BBIO.GPIO as GPIO

HOST="192.168.43.221"
PORT=4444
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((HOST,PORT))
s.listen(5)



GPIO.setup("P8_11",GPIO.OUT)
GPIO.setup("P8_13", GPIO.OUT)
GPIO.setup("P8_15", GPIO.OUT)
GPIO.setup("P8_17", GPIO.OUT)


GPIO.output("P8_11", GPIO.HIGH)
GPIO.output("P8_13", GPIO.HIGH)
GPIO.output("P8_15", GPIO.HIGH)
GPIO.output("P8_17", GPIO.HIGH)


while True:
	c,addr=s.accept()
	while True:
		data=c.recv(1)
	
		print 'data',data
		if data=='U':
			GPIO.output("P8_11", GPIO.HIGH)
			GPIO.output("P8_13", GPIO.LOW)
			GPIO.output("P8_15", GPIO.HIGH)
			GPIO.output("P8_17", GPIO.LOW)

		elif data=='R':
			GPIO.output("P8_11", GPIO.LOW)
			GPIO.output("P8_13", GPIO.LOW)
			GPIO.output("P8_15", GPIO.HIGH)
			GPIO.output("P8_17", GPIO.LOW)
	

		elif data=='L':
			GPIO.output("P8_11", GPIO.HIGH)
			GPIO.output("P8_13", GPIO.LOW)
			GPIO.output("P8_15", GPIO.LOW)
			GPIO.output("P8_17", GPIO.LOW)
		
		elif data=='D':
			GPIO.output("P8_11", GPIO.LOW)
			GPIO.output("P8_13", GPIO.HIGH)
			GPIO.output("P8_15", GPIO.LOW)
			GPIO.output("P8_17", GPIO.HIGH)

		elif data=='N':
			GPIO.output("P8_11", GPIO.LOW)
			GPIO.output("P8_13", GPIO.LOW)
			GPIO.output("P8_15", GPIO.LOW)
			GPIO.output("P8_17", GPIO.HIGH)

		elif data=='P':
			GPIO.output("P8_11", GPIO.LOW)
			GPIO.output("P8_13", GPIO.HIGH)
			GPIO.output("P8_15", GPIO.LOW)
			GPIO.output("P8_17", GPIO.LOW)

		elif data=='S':
			GPIO.output("P8_11", GPIO.LOW)
			GPIO.output("P8_13", GPIO.LOW)
			GPIO.output("P8_15", GPIO.LOW)
			GPIO.output("P8_17", GPIO.LOW)
		
		elif data=='Z':
			break
		
	c.close()
s.close();
import socket
import sys
import Adafruit_BBIO.GPIO as GPIO

HOST="192.168.43.146"
PORT=4444
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((HOST,PORT))
s.listen(5)

GPIO.setmode(GPIO.BCM)

GPIO.setup("P8_11",GPIO.OUT)
GPIO.setup("P8_13", GPIO.OUT)
GPIO.setup("P8_15", GPIO.OUT)
GPIO.setup("P8_17", GPIO.OUT)


GPIO.output("P8_11", GPIO.HIGH)
GPIO.output("P8_13", GPIO.HIGH)
GPIO.output("P8_15", GPIO.HIGH)
GPIO.output("P8_17", GPIO.HIGH)


while True:
	c,addr=s.accept()
	while True:
		data=c.recv(1)
	
		print 'data',data
		if data=='U':
			GPIO.output("P8_11", GPIO.HIGH)
			GPIO.output("P8_13", GPIO.LOW)
			GPIO.output("P8_15", GPIO.HIGH)
			GPIO.output("P8_17", GPIO.LOW)

		elif data=='R':
			GPIO.output("P8_11", GPIO.LOW)
			GPIO.output("P8_13", GPIO.LOW)
			GPIO.output("P8_15", GPIO.HIGH)
			GPIO.output("P8_17", GPIO.LOW)
	

		elif data=='L':
			GPIO.output("P8_11", GPIO.HIGH)
			GPIO.output("P8_13", GPIO.LOW)
			GPIO.output("P8_15", GPIO.LOW)
			GPIO.output("P8_17", GPIO.LOW)
		
		elif data=='D':
			GPIO.output("P8_11", GPIO.LOW)
			GPIO.output("P8_13", GPIO.HIGH)
			GPIO.output("P8_15", GPIO.LOW)
			GPIO.output("P8_17", GPIO.HIGH)

		elif data=='N':
			GPIO.output("P8_11", GPIO.LOW)
			GPIO.output("P8_13", GPIO.LOW)
			GPIO.output("P8_15", GPIO.LOW)
			GPIO.output("P8_17", GPIO.HIGH)

		elif data=='P':
			GPIO.output("P8_11", GPIO.LOW)
			GPIO.output("P8_13", GPIO.HIGH)
			GPIO.output("P8_15", GPIO.LOW)
			GPIO.output("P8_17", GPIO.LOW)

		elif data=='S':
			GPIO.output("P8_11", GPIO.LOW)
			GPIO.output("P8_13", GPIO.LOW)
			GPIO.output("P8_15", GPIO.LOW)
			GPIO.output("P8_17", GPIO.LOW)
		
		elif data=='Z':
			break
		
	c.close()
s.close();

