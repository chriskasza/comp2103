# makefile for example 9-11
OBJS = ex9-11.o numberOfLines.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-11:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-11
# dependencies
ex9-11.o:	ex9-11.c
	$(CC) $(CFLAGS) -c ex9-11.c
numberOfLines.o:	numberOfLines.c
	$(CC) $(CFLAGS) -c numberOfLines.c

