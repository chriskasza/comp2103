# makefile for module IO
# creates three executables: ex7-51-io ex7-52-io ex7-53-io
OBJS1 = ex7-5-io.o ex7-5-io-main.o
OBJS2 = ex7-5-io.o ex7-5-io-main1.o
OBJS3 = ex7-5-io.o ex7-5-io-main2.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable1
ex7-51-io:	$(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o ex7-51-io
# dependencies
ex7-5-io.o:	ex7-5-io.h ex7-5-io.c
	$(CC) $(CFLAGS) -c ex7-5-io.c
ex7-5-io-main.o:	ex7-5-io.h ex7-5-io-main.c
	$(CC) $(CFLAGS) -c ex7-5-io-main.c

# executable2
ex7-52-io:	$(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o ex7-52-io
# dependencies
#ex7-5-io.o:	ex7-5-io.h ex7-5-io.c
#	$(CC) $(CFLAGS) -c ex7-5-io.c
ex7-5-io-main1.o:	ex7-5-io.h ex7-5-io-main1.c
	$(CC) $(CFLAGS) -c ex7-5-io-main1.c

# executable3
ex7-53-io:	$(OBJS3)
	$(CC) $(CFLAGS) $(OBJS3) -o ex7-53-io
# dependencies
#ex7-5-io.o:	ex7-5-io.h ex7-5-io.c
#	$(CC) $(CFLAGS) -c ex7-5-io.c
ex7-5-io-main2.o:	ex7-5-io.h ex7-5-io-main2.c
	$(CC) $(CFLAGS) -c ex7-5-io-main2.c

