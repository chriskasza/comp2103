# makefile for Chapter 10 (public files)
# run: make -f 10.make target
# For example:
# make -f 10.make x10-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x10-5:	x10-5main.o  x10-5create.o
	$(CC) $(CFLAGS) -o x10-5 $(LIB) x10-5main.o  x10-5create.o
x10-5main.o:  x10-5create.h
x10-5create.o:  x10-5create.h

x10-9:	x10-9main.o x10-Arr.o
	$(CC) $(CFLAGS) -o x10-9 $(LIB) x10-9main.o x10-Arr.o
x10-9main.o: x10-Arr.h
x10-Arr.o: x10-Arr.h

x10-13:	x10-13main.o x10-13find.o x10-11getLine.o ex9-token.o
	$(CC) $(CFLAGS) -o x10-13 $(LIB) x10-13main.o x10-13find.o x10-11getLine.o ex9-token.o
x10-13main.o:	x10-13find.h 
x10-13find.o:	x10-13find.h x10-11getLine.h ex9-token.h
x10-11getLine.o: x10-11getLine.h
