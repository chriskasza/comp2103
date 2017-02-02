# makefile for example 9-9
OBJS = ex9-9.o ex9-2-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-9:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-9
# dependencies
ex9-9.o:	ex9-9.c
	$(CC) $(CFLAGS) -c ex9-9.c
ex9-2-main.o:	ex9-2-main.c
	$(CC) $(CFLAGS) -c ex9-2-main.c
