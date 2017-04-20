CC         = gcc
CFLAGS     = -Wall -pedantic -std=c89
LIB        = -lm
BINS       = c11e19
OBJ19      = c11e19.o ex11-2-list.o strdup.o

all: $(BINS)

clean:
	rm -f *.o $(BINS)

strdup.o: strdup.c
	$(CC) $(CFLAGS) -c $<

ex11-2-list.o: ex11-2-list.h ex11-enum.h
#ex11-2-list.o: ex11-2-list.c
#	$(CC) $(CFLAGS) -o $@ -c $<

c11e19: $(OBJ19)
	$(CC) $(CFLAGS) -o $@ $^

c11e19.o: c11e19.c
	$(CC) $(CFLAGS) -c $<

