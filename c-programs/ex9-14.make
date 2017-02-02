# makefile for example 9-14
OBJS = ex9-14.o ex9-12-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-14:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-14
# dependencies
ex9-14.o:	ex9-14.c
	$(CC) $(CFLAGS) -c ex9-14.c
ex9-12-main.o:	ex9-12-main.c
	$(CC) $(CFLAGS) -c ex9-12-main.c

