import socket
import sys
import RPi.GPIO as GPIO

HOST="192.168.43.138"
PORT=4444
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((HOST,PORT))
s.listen(5)

data=0

GPIO.setmode(GPIO.BCM)

GPIO.setup(2, GPIO.OUT)
GPIO.setup(3, GPIO.OUT)
GPIO.setup(4, GPIO.OUT)
GPIO.setup(5, GPIO.OUT)
GPIO.setup(22,GPIO.OUT)
GPIO.setup(27,GPIO.OUT)
GPIO.setup(17,GPIO.IN)



GPIO.output(2, 0)
GPIO.output(3, 0)
GPIO.output(4, 0)
GPIO.output(5, 0)
GPIO.output(22,0)
GPIO.output(27,0)

while True:
	c,addr=s.accept()
	c.settimeout(1)
	while True:
		if(GPIO.input(17)):
			c.send('Y\n')
			print('no gas')
	
		else:
			c.send('X\n')
			print('gas')
			
		
		try:
	          	 data= c.recv(1)
        	  
       		except socket.timeout,e:
           		err=e.args[0]
   
	
		print 'data',data
	
		if data=='U':
			GPIO.output(2, 1)
			GPIO.output(3, 0)
			GPIO.output(4, 1)
			GPIO.output(5, 0)
		
		elif data=='R':
			GPIO.output(2, 1)
			GPIO.output(3, 0)
			GPIO.output(4, 0)
			GPIO.output(5, 0)
		
		elif data=='L':
			GPIO.output(2, 0)
			GPIO.output(3, 0)
			GPIO.output(4, 1)
			GPIO.output(5, 0)
		
		elif data=='D':
			GPIO.output(2, 0)
			GPIO.output(3, 1)
			GPIO.output(4, 0)
			GPIO.output(5, 1)

		elif data=='P':
			GPIO.output(2, 0)
			GPIO.output(3, 0)
			GPIO.output(4, 0)	
			GPIO.output(5, 1)
		
		elif data=='N':
			GPIO.output(2, 0)
			GPIO.output(3, 1)
			GPIO.output(4, 0)
			GPIO.output(5, 0)
		
		elif data=='A':
			GPIO.output(22,0)
			GPIO.output(27,1)
		
		elif data=='B':
			GPIO.output(22,1)
			GPIO.output(27,0)
		
		elif data=='S':
			GPIO.output(2, 0)
			GPIO.output(3, 0)
			GPIO.output(4, 0)
			GPIO.output(5, 0)
			GPIO.output(22,0)
			GPIO.output(27,0)
		
		elif data=='Z':
			break
		
	c.close()
	data=0
s.close();


