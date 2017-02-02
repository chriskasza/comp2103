# makefile for example 9-13
OBJS = ex9-13.o ex9-13-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-13:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-13
# dependencies
ex9-13.o:	ex9-13.c
	$(CC) $(CFLAGS) -c ex9-13.c
ex9-13-main.o:	ex9-13-main.c
	$(CC) $(CFLAGS) -c ex9-13-main.c


