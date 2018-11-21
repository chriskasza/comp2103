CC         = gcc
CFLAGS     = -Wall -pedantic -std=c89
LIB        = -lm
BINS       = c10e03 c10e11
OBJ03      = c10e03.o c10e03-main.o
OBJ11      = c10e11.o

all: $(BINS)

clean:
	rm -f *.o $(BINS)


c10e03: $(OBJ03)
	$(CC) $(CFLAGS) -o $@ $^

c10e03.o: c10e03.c
	$(CC) $(CFLAGS) -c $<

c10e03-main.o: c10e03-main.c
	$(CC) $(CFLAGS) -c $<


c10e11: $(OBJ11)
	$(CC) $(CFLAGS) -o $@ $^

c10e11.o: c10e11.c
	$(CC) $(CFLAGS) -c $<

