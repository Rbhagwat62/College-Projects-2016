#!/usr/bin/python           # This is server.py file

import socket               # Import socket module
import time

s = socket.socket()         # Create a socket object
host = '192.168.43.80'        # Get local machine name
port = 4444               # Reserve a port for your service.
s.connect((host,port))
s.settimeout(1)
print('connect')
i=0;


while True:
    try:
        msg= s.recv(1024)
        print(msg)
    except socket.timeout,e:
        err=e.args[0]
    s.send("X\n")
            
    #time.sleep(3)
       #c.close()   


#print s.recv(1024)
#s.close
