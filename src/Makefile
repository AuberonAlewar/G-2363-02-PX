# Compiler
CC=gcc

# Compiling options
CFLAGS=-ggdb -Wall -pedantic -I $(IDIR)

# Group name files
GR= G-2363-NN-

# DIRECTORIES
# Headers directory
IDIR := ../includes
# Objects directory
OBJ = ../obj

#=============================================================
# Executables
#=============================================================
EXEC= $(GR)cliente-tcp $(GR)server-tcp

$(GR)cliente-tcp: $(OBJ)/$(GR)cliente-tcp.o $(OBJ)/$(GR)tcp.o
	$(CC) $(CFLAGS) -o $(GR)cliente-tcp $(OBJ)/$(GR)cliente-tcp.o $(OBJ)/$(GR)tcp.o

$(GR)server-tcp: $(OBJ)/$(GR)server-tcp.o $(OBJ)/$(GR)tcp.o
	$(CC) $(CFLAGS) -o $(GR)server-tcp $(OBJ)/$(GR)server-tcp.o $(OBJ)/$(GR)tcp.o

#=============================================================
# Make all
#=============================================================
all: $(EXEC)
	
#cliente-tcp:  tcp.o cliente-tcp.o Hash.o
#	$(CC) -o alfa alfa.c lex.yy.o y.tab.o Hash.o

#=============================================================
# Objects
#=============================================================
$(OBJ)/$(GR)cliente-tcp.o: $(GR)cliente-tcp.c $(IDIR)/$(GR)tcp.h 
	$(CC) $(CFLAGS) -c -o $(OBJ)/$(GR)cliente-tcp.o $(GR)cliente-tcp.c

$(OBJ)/$(GR)server-tcp.o: $(GR)server-tcp.c $(IDIR)/$(GR)tcp.h 
	$(CC) $(CFLAGS) -c -o $(OBJ)/$(GR)server-tcp.o $(GR)server-tcp.c

$(OBJ)/$(GR)tcp.o: $(GR)tcp.c $(IDIR)/$(GR)tcp.h
	$(CC) $(CFLAGS) -c -o $(OBJ)/$(GR)tcp.o $(GR)tcp.c

$(OBJ)/$(GR)udp.o: $(GR)udp.c $(IDIR)/$(GR)udp.h
	$(CC) $(CFLAGS) -c $(GR)udp.c 


#=============================================================
# Clean .o and EXEC
#=============================================================
clean:
	rm -rf $(OBJ)/*

#CREAR LIBRERIA
# ar rcs libreriaTCPUDP.a  tcp.o udp.o
# nm libreriaTCPUDP.a
