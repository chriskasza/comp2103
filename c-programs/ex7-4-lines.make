# makefile for module Lines. 
# Executable: ex7-4-lines
OBJS = ex7-4-lines.o ex7-4-lines-main.o
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex7-4-lines:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex7-4-lines
# dependencies
ex7-4-lines.o:	ex7-4-lines.h ex7-4-lines.c
	$(CC) $(CFLAGS) -c ex7-4-lines.c
ex7-4-lines-main.o:	ex7-4-lines.h	ex7-4-lines-main.c
	$(CC) $(CFLAGS) -c ex7-4-lines-main.c
