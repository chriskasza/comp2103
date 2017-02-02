# makefile for Chapter 5 (public files)
# run: make -f 5.make target
# For example:
# make -f 5.make x5-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x5-1:	x5-1.o 
	$(CC) $(CFLAGS) -o x5-1 $(LIB) x5-1.o 

x5-5:	x5-5.o 
	$(CC) $(CFLAGS) -o x5-5 $(LIB) x5-5.o 

x5-9:	x5-9.o 
	$(CC) $(CFLAGS) -o x5-9 $(LIB) x5-9.o 

x5-13:	x5-13.o 
	$(CC) $(CFLAGS) -o x5-13 $(LIB) x5-13.o 

x5-17:	x5-17.o 
	$(CC) $(CFLAGS) -o x5-17 $(LIB) x5-17.o 


