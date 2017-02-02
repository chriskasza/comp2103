# makefile for example 9-12
OBJS = ex9-12.o ex9-12-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-12:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-12
# dependencies
ex9-12.o:	ex9-12.c
	$(CC) $(CFLAGS) -c ex9-12.c
ex9-12-main.o:	ex9-12-main.c
	$(CC) $(CFLAGS) -c ex9-12-main.c

