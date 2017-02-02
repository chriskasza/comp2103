# makefile for module Ops with enumerations
# creates two executables: ex8-111-ops ex8-112-ops 
OBJS1 = ex8-11-ops.o ex8-11-ops-main.o
OBJS2 = ex8-11-ops.o ex8-11-ops-main1.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable1
ex8-111-ops:	$(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o ex8-111-ops
# dependencies
ex8-11-ops.o:	ex8-enum.h ex8-11-ops.h ex8-11-ops.c
	$(CC) $(CFLAGS) -c ex8-11-ops.c
ex8-11-ops-main.o:	ex8-11-ops.h ex8-enum.h ex8-11-ops-main.c
	$(CC) $(CFLAGS) -c ex8-11-ops-main.c

# executable2
ex8-112-ops:	$(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o ex8-112-ops
# dependencies
#ex8-11-ops.o:	ex8-enum.h ex8-11-ops.h ex8-11-ops.c
#	$(CC) $(CFLAGS) -c ex8-11-ops.c
ex8-11-ops-main1.o:	ex8-11-ops.h ex8-enum.h ex8-11-ops-main1.c
	$(CC) $(CFLAGS) -c ex8-11-ops-main1.c

