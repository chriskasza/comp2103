# makefile for example 8-8
OBJS = ex8-8.o ex8-8-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex8-8:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex8-8
# dependencies
ex8-8.o:	ex8-8.c
	$(CC) $(CFLAGS) -c ex8-8.c
ex8-8-main.o:	ex8-8-main.c
	$(CC) $(CFLAGS) -c ex8-8-main.c
