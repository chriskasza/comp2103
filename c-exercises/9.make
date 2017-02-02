# makefile for Chapter 9 (public files)
# run: make -f 9.make target
# For example:
# make -f 9.make x9-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x9-1:	x9-1.o 
	$(CC) $(CFLAGS) -o x9-1 $(LIB) x9-1.o 

x9-5:	x9-5.o 
	$(CC) $(CFLAGS) -o x9-5 $(LIB) x9-5.o 

x9-9:	x9-9.o 
	$(CC) $(CFLAGS) -o x9-9 $(LIB) x9-9.o 

x9-13:	x9-13.o 
	$(CC) $(CFLAGS) -o x9-13 $(LIB) x9-13.o 

x9-17:	x9-17.o 
	$(CC) $(CFLAGS) -o x9-17 $(LIB) x9-17.o 

x9-21:	x9-21.o ex9-token.o 
	$(CC) $(CFLAGS) -o x9-21 $(LIB) x9-21.o ex9-token.o
ex9-token.o:	ex9-token.h
x9-21.o:	ex9-token.h

