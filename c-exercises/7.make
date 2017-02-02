# makefile for Chapter 7 (public files)
# run: make -f 7.make target
# For example:
# make -f 7.make x7-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x7-1:	x7-1.o 
	$(CC) $(CFLAGS) -o x7-1 x7-1.o 

x7-5:	x7-5.o 
	$(CC) $(CFLAGS) -o x7-5 x7-5.o 

x7-9:	x7-9.o 
	$(CC) $(CFLAGS) -o x7-9 x7-9.o 

x7-13:	x7-13.o 
	$(CC) $(CFLAGS) -o x7-13 x7-13.o 

x7-17:	x7-17.o 
	$(CC) $(CFLAGS) -o x7-17 x7-17.o  

x7-21:	x7-21.o 
	$(CC) $(CFLAGS) -o x7-21 x7-21.o 


x7-25:	x7-25double.o  x7-25main.o
	$(CC) $(CFLAGS) -o x7-25 x7-25main.o  x7-25double.o
x7-25main.o:	x7-25double.h
x7-25double.o:	x7-25double.h


x7-29:	x7-29fraction.o  x7-29main.o
	$(CC) $(CFLAGS) -o x7-29 $(LIB) x7-29fraction.o  x7-29main.o
x7-29main.o:	x7-29fraction.h
x7-29fraction.o:	x7-29fraction.h

