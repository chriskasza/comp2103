# makefile for Chapter 13 (public files)
# run: make -f 13.make target
# For example:
# make -f 13.make x13-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x13-1:	x13-1.o 
	$(CC) $(CFLAGS) -o x13-1 $(LIB) x13-1.o 

x13-5:	x13-5.o x13-5main.o
	$(CC) $(CFLAGS) -o x13-5 $(LIB) x13-5.o x13-5main.o
x13-5.o:	x13-5.h
x13-5main.o:	x13-5.h
 
