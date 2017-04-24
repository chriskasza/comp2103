CC         = gcc
CFLAGS     = -Wall -pedantic -std=c89
LIB        = -lm
BINS       = c14e03
OBJ        = c14e03.o x14-3stack.o

all: $(BINS)

clean:
	rm -f *.o $(BINS)

x14-3stack.o: x14-3stack.h
#ex11-2-list.o: ex11-2-list.c
#	$(CC) $(CFLAGS) -o $@ -c $<

c14e03: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

c14e03.o: c14e03.c
	$(CC) $(CFLAGS) -c $<

