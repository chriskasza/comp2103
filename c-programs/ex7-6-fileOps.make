# makefile for module fileOps
# Executable: ex7-6-fileOps
OBJS = ex7-6-fileOps.o ex7-6-fileOps-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex7-6-fileOps:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex7-6-fileOps
# dependencies
ex7-6-fileOps.o:	ex7-6-fileOps.h ex7-6-fileOps.c
	$(CC) $(CFLAGS) -c ex7-6-fileOps.c
ex7-6-fileOps-main.o:	ex7-6-fileOps.h	ex7-6-fileOps-main.c
	$(CC) $(CFLAGS) -c ex7-6-fileOps-main.c
