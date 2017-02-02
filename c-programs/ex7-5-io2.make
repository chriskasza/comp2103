# makefile for module IO2
# creates two executables: ex7-51-io2 ex7-52-io2
OBJS1 = ex7-5-io2.o ex7-5-io.o ex7-5-io2-main.o
OBJS2 = ex7-5-io2.o ex7-5-io.o ex7-5-io2-main1.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable1
ex7-51-io2:	$(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o ex7-51-io2
# dependencies
ex7-5-io2.o:	ex7-5-io2.h ex7-5-io2.c
	$(CC) $(CFLAGS) -c ex7-5-io2.c
ex7-5-io.o:	ex7-5-io.h ex7-5-io.c
	$(CC) $(CFLAGS) -c ex7-5-io.c
ex7-5-io2-main.o:	ex7-5-io2.h	ex7-5-io2-main.c
	$(CC) $(CFLAGS) -c ex7-5-io2-main.c

# executable2
ex7-52-io2:	$(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o ex7-52-io2
# dependencies
#ex7-5-io2.o:	ex7-5-io2.h ex7-5-io2.c
#	$(CC) $(CFLAGS) -c ex7-5-io2.c
ex7-5-io2-main1.o:	ex7-5-io2.h	ex7-5-io2-main1.c
	$(CC) $(CFLAGS) -c ex7-5-io2-main1.c
