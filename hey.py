#!/usr/bin/python

import socket

for i in range(20):
	s = socket.socket()
	host = "150.244.64.180"
	port = 6667

	s.connect((host, port))
	s.send("Hola caracola")
	print s.recv(1024)
s.close
