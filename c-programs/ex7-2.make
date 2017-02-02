# makefile for example 7-2
OBJS = ex7-2.o ex7-21.o ex7-2-main.o
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex7-2:	$(OBJS)
	$(CC) $(CFLAGS) -o ex7-2 $(OBJS)
# dependencies
ex7-2.o:	ex7-2.c
	$(CC) $(CFLAGS) -c ex7-2.c
ex7-21.o:	ex7-21.c
	$(CC) $(CFLAGS) -c ex7-21.c
ex7-2-main.o:	ex7-2-main.c
	$(CC) $(CFLAGS) -c ex7-2-main.c

