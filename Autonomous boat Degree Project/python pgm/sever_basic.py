#!/usr/bin/python           # This is server.py file

import socket   # Import socket module

s = socket.socket()         # Create a socket object
host = '192.168.4.2'        # Get local machine name
port = 4444               # Reserve a port for your service.
s.bind((host, port))# Bind to the port

s.listen(5)         # Now wait for client connection.
msg=0
print "server created"
while True:
   c, addr = s.accept()     # Establish connection with client.
   c.settimeout(1)

   print 'Got connection from', addr
   while True:
       try:
           msg= c.recv(1)
           print(msg)
       except socket.timeout,e:
           err=e.args[0]
   
       c.send("X\n")
       
       if(msg == 'Z'):
          break;
       
            
    #time.sleep(3)
       #c.close()   

   c.close()
   msg=0;
s.close()
   
