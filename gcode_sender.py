import socket
import time
s = socket.socket()
host = ''
port = 8080
s.bind((host, port))
print "socket binded to %s" %(port) 
s.listen(1)
print "Listening"            
while True: 
   c, addr = s.accept()      
   print 'Got connection from', addr
   f=open("gcode.txt", "r")
   for x in f:
   		c.send(x)
   		c.settimeout(20)
   		while True:
   			data=c.recv(20)
   			print data
   			ack=data
   			data=""
   			if "OK" in ack:
   				print ("Received :"+ack)
   				break
   		#while True:
   		#	time.sleep(0.00001)
   		#	if data:
   		#		print data
   		#		if data=="OK\n":
   		#			break
   		#c.send('\n') 
   f.close()
   c.close()