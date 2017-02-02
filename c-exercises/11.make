# makefile for Chapter 11 (public files)
# run: make -f 11.make target
# For example:
# make -f 11.make x11-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x11-1:	x11-1.o 
	$(CC) $(CFLAGS) -o x11-1 $(LIB) x11-1.o 

x11-5:	x11-5main.o  x11-5.o
	$(CC) $(CFLAGS) -o x11-5 $(LIB) x11-5main.o  x11-5.o
x11-5main.o:  x11-5.h
x11-5.o:  x11-5.h

x11-9:	x11-9.o 
	$(CC) $(CFLAGS) -o x11-9 $(LIB) x11-9.o 

x11-13:	x11-13.o 
	$(CC) $(CFLAGS) -o x11-13 $(LIB) x11-13.o 

x11-17:	x11-17array.o x11-17main.o
	$(CC) $(CFLAGS) -o x11-17 $(LIB) x11-17array.o x11-17main.o
x11-17main.o: x11-17array.h
x11-17array.o: x11-17array.h

x11-21:	x11-21main.o x11-21list.o
	$(CC) $(CFLAGS) -o x11-21 $(LIB) x11-21main.o x11-21list.o
x11-21main.o: x11-21list.h
x11-21list.o: x11-21list.h
