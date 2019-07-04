#!/usr/bin/python           # This is server.py file

import socket               # Import socket module
import time
s = socket.socket()         # Create a socket object

host = '192.168.4.1'        # Get local machine name
port = 4444               # Reserve a port for your service.s.bind((host, port))        # Bind to the port


s.connect((host,port))

time.sleep(5)
s.send("U\r")
print "send"

#while True:
#    print s.recv(1024)
s.close
