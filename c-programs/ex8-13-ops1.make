# makefile for module ops11 with enumerations
# creates two executables: ex8-131-ops1 ex8-132-ops1
OBJS1 = ex8-13-ops1.o ex8-13-ops1-main.o
OBJS2 = ex8-13-ops1.o ex8-13-ops1-main1.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable1
ex8-131-ops1:	$(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o ex8-131-ops1
# dependencies
ex8-13-ops1.o:	ex8-enum.h ex8-13-ops1.h ex8-13-ops1.c
	$(CC) $(CFLAGS) -c ex8-13-ops1.c
ex8-13-ops1-main.o:	ex8-13-ops1.h ex8-enum.h ex8-13-ops1-main.c
	$(CC) $(CFLAGS) -c ex8-13-ops1-main.c

# executable2
ex8-132-ops1:	$(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o ex8-132-ops1
# dependencies
#ex8-13-ops1.o:	ex8-enum.h ex8-13-ops1.h ex8-13-ops1.c
#	$(CC) $(CFLAGS) -c ex8-13-ops1.c
ex8-13-ops1-main1.o:	ex8-13-ops1.h ex8-enum.h ex8-13-ops1-main1.c
	$(CC) $(CFLAGS) -c ex8-13-ops1-main1.c
