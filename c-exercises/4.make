# makefile for Chapter 4 (public files)
# run: make -f 4.make target
# For example:
# make -f 4.make x4-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x4-1:	x4-1.o 
	$(CC) $(CFLAGS) -o x4-1 $(LIB) x4-1.o 

x4-5:	x4-5.o 
	$(CC) $(CFLAGS) -o x4-5 $(LIB) x4-5.o 

x4-9:	x4-9.o 
	$(CC) $(CFLAGS) -o x4-9 $(LIB) x4-9.o 

x4-13:	x4-13.o 
	$(CC) $(CFLAGS) -o x4-13 $(LIB) x4-13.o 

x4-17:	x4-17.o 
	$(CC) $(CFLAGS) -o x4-17 $(LIB) x4-17.o 

x4-21:	x4-21.o 
	$(CC) $(CFLAGS) -o x4-21 $(LIB) x4-21.o 
