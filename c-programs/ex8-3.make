# makefile for example 8-3
OBJS = ex8-3.o ex8-3-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex8-3:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex8-3
# dependencies
ex8-3.o:	ex8-3.c
	$(CC) $(CFLAGS) -c ex8-3.c
ex8-3-main.o:	ex8-3-main.c
	$(CC) $(CFLAGS) -c ex8-3-main.c
