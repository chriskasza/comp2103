# makefile for module Ops
# creates two executables: ex8-10-ops ex8-101-ops
OBJS1 = ex8-10-ops.o ex8-10-ops-main.o
OBJS2 = ex8-10-ops.o ex8-10-ops-main1.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable1
ex8-10-ops:	$(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o ex8-10-ops
# dependencies
ex8-10-ops.o:	ex8-10-ops.h ex8-10-ops.c
	$(CC) $(CFLAGS) -c ex8-10-ops.c
ex8-10-ops-main.o:	ex8-10-ops.h	ex8-10-ops-main.c
	$(CC) $(CFLAGS) -c ex8-10-ops-main.c

# executable2
ex8-101-ops:	$(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o ex8-101-ops
# dependencies
#ex8-10-ops.o:	ex8-10-ops.h ex8-10-ops.c
#	$(CC) $(CFLAGS) -c ex8-10-ops.c
ex8-10-ops-main1.o:	ex8-10-ops.h	ex8-10-ops-main1.c
	$(CC) $(CFLAGS) -c ex8-10-ops-main1.c
