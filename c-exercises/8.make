# makefile for Chapter 8 (public files)
# run: make -f 8.make target
# For example:
# make -f 8.make x8-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x8-1:	x8-1.o 
	$(CC) $(CFLAGS) -o x8-1 $(LIB) x8-1.o 

x8-5:	x8-5.o x8-doubleFileIO.o
	$(CC) $(CFLAGS) -o x8-5 $(LIB) x8-5.o x8-doubleFileIO.o
x8-doubleFileIO.o:	x8-doubleFileIO.h
x8-5.o: x8-doubleFileIO.h

x8-9:	x8-9main.o x8-9com.o x8-3mem.o
	$(CC) $(CFLAGS) -o x8-9 $(LIB) x8-9main.o x8-9com.o x8-3mem.o
x8-9main.o:	x8-9com.h x8-3mem.h
x8-3mem.o:  x8-3mem.h
x8-9com.o: x8-9com.h
