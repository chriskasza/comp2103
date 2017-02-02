# makefile for example 9-1
OBJS = ex9-1.o ex9-1-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-1:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-1
# dependencies
ex9-1.o:	ex9-1.c
	$(CC) $(CFLAGS) -c ex9-1.c
ex9-1-main.o:	ex9-1-main.c
	$(CC) $(CFLAGS) -c ex9-1-main.c
