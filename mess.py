import socket
import time
TCP_IP = '192.168.1.39'
TCP_PORT = 5005
def send_message(ip,port,message):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((ip,port))
	s.listen(1)
	c,addr=s.accept()
	c.send(message)
	c.close()
	s.close()
time.sleep(2)
send_message(TCP_IP,TCP_PORT,'hi\n')