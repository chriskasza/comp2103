# makefile for module list from Chapter 14. 
# Executables: ex14-list ex141-list 
OBJS = ex14-list.o ex14-listShallow.o ex14-listDeep.o ex14-list-main.o strdup.o
OBJS1 = ex14-list.o ex14-listShallow.o ex14-listDeep.o ex14-list-main1.o strdup.o
LIB	= -lm
CC = gcc
CFLAGS = -Wall -pedantic
# executable
ex14-list:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ex14-list
# dependencies
ex14-listShallow.o:	ex14-list.h ex14-enum.h ex14-enumShallow.h ex14-listShallow.h ex14-listShallow.c
	$(CC) $(CFLAGS) -c ex14-listShallow.c
ex14-listDeep.o:	strdup.c ex14-list.h ex14-enum.h ex14-enumShallow.h ex14-listShallow.h ex14-listShallow.c
	$(CC) $(CFLAGS) -c ex14-listDeep.c
ex14-list.o:	ex14-list.h ex14-enum.h ex14-list.c
	$(CC) $(CFLAGS) -c ex14-list.c
ex14-list-main.o:	ex14-list.h ex14-enum.h ex14-enumShallow.h ex14-listShallow.h ex14-list-main.c
	$(CC) $(CFLAGS) -c ex14-list-main.c
strdup.o:	strdup.c
	$(CC) $(CFLAGS) -c strdup.c

# executable
ex141-list:	$(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o ex141-list
# dependencies
#ex14-listShallow.o:	ex14-list.h ex14-enum.h ex14-enumShallow.h ex14-listShallow.h ex14-listShallow.c
#	$(CC) $(CFLAGS) -c ex14-listShallow.c
#ex14-listDeep.o:	strdup.c ex14-list.h ex14-enum.h ex14-enumShallow.h ex14-listShallow.h ex14-listShallow.c
#	$(CC) $(CFLAGS) -c ex14-listShallow.c
#ex14-list.o:	ex14-list.h ex14-enum.h ex14-list.c
#	$(CC) $(CFLAGS) -c ex14-list.c
ex14-list-main1.o:	ex14-list.h ex14-enum.h ex14-enumShallow.h ex14-listShallow.h ex14-list-main1.c
	$(CC) $(CFLAGS) -c ex14-list-main1.c
#strdup.o:	strdup.c
#	$(CC) $(CFLAGS) -c strdup.c
