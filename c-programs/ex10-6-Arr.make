# makefile for module Arr. 
# Executables: ex10-6-Arr ex10-61-Arr
OBJS = ex10-6-Arr.o ex10-6-Arr-main.o
OBJS1 = ex10-6-Arr.o ex10-6-Arr-main1.o
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex10-6-Arr:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex10-6-Arr
# dependencies
ex10-6-Arr.o:	ex10-6-Arr.h ex10-6-Arr.c
	$(CC) $(CFLAGS) -c ex10-6-Arr.c
ex10-6-Arr-main.o:	ex10-6-Arr.h	ex10-6-Arr-main.c
	$(CC) $(CFLAGS) -c ex10-6-Arr-main.c

# executable
ex10-61-Arr:	$(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o ex10-61-Arr
# dependencies
#ex10-6-Arr.o:	ex10-6-Arr.h ex10-6-Arr.c
#	$(CC) $(CFLAGS) -c ex10-6-Arr.c
ex10-6-Arr-main1.o:	ex10-6-Arr.h	ex10-6-Arr-main1.c
	$(CC) $(CFLAGS) -c ex10-6-Arr-main1.c

