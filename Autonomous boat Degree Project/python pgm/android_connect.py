#!/usr/bin/python           # This is server.py file

import socket   # Import socket module
import time

s = socket.socket()         # Create a socket object
host = '192.168.137.1'        # Get local machine name
port = 5000               # Reserve a port for your service.
s.bind((host, port))        # Bind to the port

s.listen(5)         # Now wait for client connection.
x=1
while True:
   x=x+1
   c, addr = s.accept()     # Establish connection with client.
   print 'Got connection from', addr
   
   while True:
       c.send('thank you\n')
       
   c.close()   

#s.connect((host,port))
#print s.recv(1024)
#s.close
