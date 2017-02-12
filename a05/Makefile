CC         = gcc
CFLAGS     = -Wall -pedantic
LIB        = -lm
BINS       = c07e23 c07e27
OBJ27      = c07e27.o c07e27-main.o ex7-4-lines.o

all: c07e23 c07e27

clean:
	rm -f *.o $(BINS)


c07e23: c07e23.o
	$(CC) $(CFLAGS) -o $@ $<

c07e23.o: c07e23.c
	$(CC) $(CFLAGS) -c $<


c07e27: $(OBJ27)
	$(CC) $(CFLAGS) -o $@ $^

c07e27.o: c07e27.c 
	$(CC) $(CFLAGS) -c $<

ex7-4-lines.o: ex7-4-lines.c
	$(CC) $(CFLAGS) -c $<

c07e27-main.o: c07e27-main.c
	$(CC) $(CFLAGS) -c $<

