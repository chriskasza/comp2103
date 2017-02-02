# makefile for module Tokens. 
# Executable: ex9-15
OBJS = ex9-token.o ex9-15-token-main.o

LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex9-15:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex9-15
# dependencies
ex9-token.o:	ex9-token.h ex9-token.c
	$(CC) $(CFLAGS) -c ex9-token.c
ex9-15-main.o:	ex9-token.h	ex9-15-token-main.c
	$(CC) $(CFLAGS) -c ex9-15-token-main.c
