# makefile for module IO1
# creates three executables: ex7-51-io1 ex7-52-io1 ex7-53-io1
OBJS1 = ex7-5-io1.o ex7-5-io.o ex7-5-io1-main.o
OBJS2 = ex7-5-io1.o ex7-5-io.o ex7-5-io1-main1.o
OBJS3 = ex7-5-io1.o ex7-5-io.o ex7-5-io1-main2.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable1
ex7-51-io1:	$(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o ex7-51-io1
# dependencies
ex7-5-io1.o:	ex7-5-io1.h ex7-5-io1.c
	$(CC) $(CFLAGS) -c ex7-5-io1.c
ex7-5-io1-main.o:	ex7-5-io1.h	ex7-5-io1-main.c
	$(CC) $(CFLAGS) -c ex7-5-io1-main.c

# executable2
ex7-52-io1:	$(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o ex7-52-io1
# dependencies
#ex7-5-io1.o:	ex7-5-io1.h ex7-5-io1.c
#	$(CC) $(CFLAGS) -c ex7-5-io1.c
ex7-5-io1-main1.o:	ex7-5-io1.h	ex7-5-io1-main1.c
	$(CC) $(CFLAGS) -c ex7-5-io1-main1.c

# executable3
ex7-53-io1:	$(OBJS3)
	$(CC) $(CFLAGS) $(OBJS3) -o ex7-53-io1
# dependencies
#ex7-5-io1.o:	ex7-5-io.h ex7-5-i1.c
#	$(CC) $(CFLAGS) -c ex7-5-io1.c
ex7-5-io1-main2.o:	ex7-5-io1.h	ex7-5-io1-main2.c
	$(CC) $(CFLAGS) -c ex7-5-io1-main2.c

