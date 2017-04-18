CC         = gcc
CFLAGS     = -Wall -pedantic -std=c89
LIB        = -lm
BINS       = c11e07-1 c11e07-2 c11e10
OBJ07-1    = c11e07-1.o c11e07-main.o
OBJ07-2    = c11e07-2.o c11e07-main.o
OBJ10      = c11e10.o c11e10-main.o

all: $(BINS)

clean:
	rm -f *.o $(BINS)


c11e07-1: $(OBJ07-1)
	$(CC) $(CFLAGS) -o $@ $^

c11e07-2: $(OBJ07-2)
	$(CC) $(CFLAGS) -o $@ $^

c11e07-1.o: c11e07-1.c
	$(CC) $(CFLAGS) -c $<

c11e07-2.o: c11e07-2.c
	$(CC) $(CFLAGS) -c $<

c11e07-main.o: c11e07-main.c
	$(CC) $(CFLAGS) -c $<


c11e10: $(OBJ10)
	$(CC) $(CFLAGS) -o $@ $^

c11e10.o: c11e10.c
	$(CC) $(CFLAGS) -c $<

c11e10-main.o: c11e10-main.c
	$(CC) $(CFLAGS) -c $<

