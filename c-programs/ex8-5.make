# makefile for example 8-5
OBJS = ex8-5.o ex8-52.o ex8-5-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex8-5:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex8-5
# dependencies
ex8-5.o:	ex8-5.c
	$(CC) $(CFLAGS) -c ex8-5.c
ex8-52.o:	ex8-52.c
	$(CC) $(CFLAGS) -c ex8-52.c
ex8-5-main.o:	ex8-5-main.c
	$(CC) $(CFLAGS) -c ex8-5-main.c
