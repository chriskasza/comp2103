# makefile for Chapter 6 (public files)
# run: make -f 6.make target
# For example:
# make -f 6.make x6-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x6-1:	x6-1.o 
	$(CC) $(CFLAGS) -o x6-1 $(LIB) x6-1.o 

x6-5:	x6-5.o 
	$(CC) $(CFLAGS) -o x6-5 $(LIB) x6-5.o 
