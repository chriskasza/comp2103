# makefile for module list from Chapter 11. 
# Executables: ex11-2-list ex11-21-list 
OBJS = ex11-2-list.o ex11-2-list-main.o strdup.o
OBJS1 = ex11-2-list.o ex11-2-list-main1.o strdup.o
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex11-2-list:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex11-2-list
# dependencies
ex11-2-list.o:	ex11-2-list.h ex11-enum.h ex11-2-list.c
	$(CC) $(CFLAGS) -c ex11-2-list.c
ex11-2-list-main.o:	ex11-2-list.h ex11-enum.h ex11-2-list-main.c
	$(CC) $(CFLAGS) -c ex11-2-list-main.c
strdup.o:	strdup.c
	$(CC) $(CFLAGS) -c strdup.c

# executable
ex11-21-list:	$(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o ex11-21-list
# dependencies
#ex11-2-list.o:	ex11-2-list.h ex11-2-list.c
#	$(CC) $(CFLAGS) -c ex11-2-list.c
ex11-2-list-main1.o:	ex11-2-list.h	ex11-enum.h ex11-2-list-main1.c
	$(CC) $(CFLAGS) -c ex11-2-list-main1.c

