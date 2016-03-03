#!/usr/bin/python

import socket

for i in range(20):
	s = socket.socket()
	host = "127.0.0.1"
	port = 8888

	s.connect((host, port))
	s.send("Hola caracola")
	print s.recv(1024)

s.close
