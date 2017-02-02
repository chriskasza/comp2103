# makefile for example 8-6
OBJS = ex8-6.o ex8-6-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex8-6:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex8-6
# dependencies
ex8-6.o:	ex8-6.c
	$(CC) $(CFLAGS) -c ex8-6.c
ex8-6-main.o:	ex8-6-main.c
	$(CC) $(CFLAGS) -c ex8-6-main.c
