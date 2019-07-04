#!/usr/bin/python           # This is server.py file

import socket               # Import socket module
import time

s = socket.socket()         # Create a socket object
host = '192.168.43.138'        # Get local machine name
port = 5000               # Reserve a port for your service.
s.connect((host,port))

while True:   
   print s.recv(1024)
   while True:
       s.send("HIGH")
       time.sleep(3)
       s.send("LOW")
       time.sleep(2)
   #c.close()   


#print s.recv(1024)
#s.close
