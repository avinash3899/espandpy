import socket
import time
s = socket.socket()          
port = 8080              
s.bind(('', port))         
print "socket binded to %s" %(port) 
s.listen(1)      
print "Listening"            
while True: 
   c, addr = s.accept()      
   print 'Got connection from', addr
   f=open("gcode.txt", "r")
   for x in f:
   	c.send(x)
      time.sleep(1)
   	#c.send('\n') 
   f.close()
   c.close()
