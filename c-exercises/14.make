# makefile for Chapter 14 (public files)
# run: make -f 14.make target
# For example:
# make -f 14.make x14-1
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic

x14-1:	x14-1poly.o x14-1main.o
	$(CC) $(CFLAGS) -o x14-1 $(LIB) x14-1poly.o x14-1main.o
x14-1poly.o: x14-1poly.h ex11-enum.h
x14-1main.o: x14-1poly.h ex11-enum.h

x14-5:	x14-5main.o  x14-5stack.o
	$(CC) $(CFLAGS) -o x14-5 $(LIB) x14-5main.o  x14-5stack.o
x14-5main.o:  x14-5stack.h
x14-5stack.o:  x14-5stack.h

x14-9:	x14-9token.o  x14-9main.o
	$(CC) $(CFLAGS) -o x14-9 $(LIB) x14-9token.o  x14-9main.o
x14-9token.o: x14-9token.h
x14-9main.o: x14-9token.h

x14-13:	x14-13fig.o x14-13main.o
	$(CC) $(CFLAGS) -o x14-13 $(LIB) x14-13fig.o x14-13main.o
x14-13main.o : x14-13fig.h
x14-13fig.o : x14-13fig.h

