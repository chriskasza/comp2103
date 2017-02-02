# makefile for example 9-8
OBJS = ex9-8.o ex9-8-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-8:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-8
# dependencies
ex9-8.o:	ex9-8.c
	$(CC) $(CFLAGS) -c ex9-8.c
ex9-8-main.o:	ex9-8-main.c
	$(CC) $(CFLAGS) -c ex9-8-main.c

