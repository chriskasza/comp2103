# makefile for example 9-4
OBJS = ex9-4.o ex9-4-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-4:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-4
# dependencies
ex9-4.o:	ex9-4.c
	$(CC) $(CFLAGS) -c ex9-4.c
ex9-4-main.o:	ex9-4-main.c
	$(CC) $(CFLAGS) -c ex9-4-main.c


