# makefile for Chapter 12 (public files)
# run: make -f 12.make target
# For example:
# make -f 12.make x12-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x12-1:	x12-1.o 
	$(CC) $(CFLAGS) -o x12-1 $(LIB) x12-1.o 
