CC         = gcc
CFLAGS     = -Wall -pedantic -std=c89
LIB        = -lm
BINS       = c12e03 c13e03
OBJ123     = c12e03.o
OBJ133     = c13e03.o

all: $(BINS)

clean:
	rm -f *.o $(BINS)

c12e03: $(OBJ123)
	$(CC) $(CFLAGS) -o $@ $^

c12e03.o: c12e03.c
	$(CC) $(CFLAGS) -c $<


c13e03: $(OBJ133)
	$(CC) $(CFLAGS) -o $@ $^

c13e03.o: c13e03.c
	$(CC) $(CFLAGS) -c $<

