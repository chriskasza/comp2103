CC         = gcc
CFLAGS     = -Wall -pedantic
LIB        = -lm
BINS       = c08e01 c08e03 c08e11
OBJ01      = c08e01.o c08e01-main.o
OBJ03      = c08e03.o c08e03-main.o
OBJ11      = c08e11.o c08e11-main.o

all: $(BINS)

clean:
	rm -f *.o $(BINS)


c08e01: $(OBJ01)
	$(CC) $(CFLAGS) -o $@ $^

c08e01.o: c08e01.c
	$(CC) $(CFLAGS) -c $<

c08e01-main.o: c08e01-main.c
	$(CC) $(CFLAGS) -c $<


c08e03: $(OBJ03)
	$(CC) $(CFLAGS) -o $@ $^

c08e03.o: c08e03.c
	$(CC) $(CFLAGS) -c $<

c08e03-main.o: c08e03-main.c
	$(CC) $(CFLAGS) -c $<


c08e11: $(OBJ11)
	$(CC) $(CFLAGS) -o $@ $^

c08e11.o: c08e11.c
	$(CC) $(CFLAGS) -c $<

c08e11-main.o: c08e11-main.c
	$(CC) $(CFLAGS) -c $<

