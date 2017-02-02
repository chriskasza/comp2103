# makefile for Chapter 3 (public files)
# run: make -f 3.make target
# For example:
# make -f 3.make x3-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x3-9:	x3-9.o 
	$(CC) $(CFLAGS) -o x3-9 $(LIB) x3-9.o 

x3-13:	x3-13.o 
	$(CC) $(CFLAGS) -o x3-13 $(LIB) x3-13.o 

x3-17:	x3-17.o 
	$(CC) $(CFLAGS) -o x3-17 $(LIB) x3-17.o 
