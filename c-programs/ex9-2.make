# makefile for example 9-2
OBJS = ex9-2.o ex9-2-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-2:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-2
# dependencies
ex9-2.o:	ex9-2.c
	$(CC) $(CFLAGS) -c ex9-2.c
ex9-2-main.o:	ex9-2-main.c
	$(CC) $(CFLAGS) -c ex9-2-main.c
