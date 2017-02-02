# makefile for module Arr from Chapter 11. 
# Executables: ex11-1-Arr ex11-11-Arr ex11-12-Arr
OBJS = ex11-1-Arr.o ex11-1-Arr-main.o
OBJS1 = ex11-1-Arr.o ex11-1-Arr-main1.o
OBJS2 = ex11-1-Arr.o ex11-1-Arr-main2.o
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex11-1-Arr:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex11-1-Arr
# dependencies
ex11-1-Arr.o:	ex11-1-Arr.h ex11-enum.h ex11-1-Arr.c
	$(CC) $(CFLAGS) -c ex11-1-Arr.c
ex11-1-Arr-main.o:	ex11-1-Arr.h ex11-enum.h ex11-1-Arr-main.c
	$(CC) $(CFLAGS) -c ex11-1-Arr-main.c

# executable
ex11-11-Arr:	$(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o ex11-11-Arr
# dependencies
#ex11-1-Arr.o:	ex11-1-Arr.h ex11-1-Arr.c
#	$(CC) $(CFLAGS) -c ex11-1-Arr.c
ex11-1-Arr-main1.o:	ex11-1-Arr.h	ex11-1-Arr-main1.c
	$(CC) $(CFLAGS) -c ex11-1-Arr-main1.c

# executable
ex11-12-Arr:	$(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o ex11-12-Arr
# dependencies
#ex11-1-Arr.o:	ex11-1-Arr.h ex11-1-Arr.c
#	$(CC) $(CFLAGS) -c ex11-1-Arr.c
ex11-1-Arr-main2.o:	ex11-1-Arr.h	ex11-1-Arr-main2.c
	$(CC) $(CFLAGS) -c ex11-1-Arr-main2.c
