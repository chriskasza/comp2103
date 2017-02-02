# makefile for example 9-3
OBJS = ex9-3.o ex9-3-main.o strdup.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-3:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-3
# dependencies
ex9-3.o:	ex9-3.c
	$(CC) $(CFLAGS) -c ex9-3.c
ex9-3-main.o:	ex9-3-main.c
	$(CC) $(CFLAGS) -c ex9-3-main.c
strdup.o:	strdup.c
	$(CC) $(CFLAGS) -c strdup.c

