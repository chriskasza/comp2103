CC         = gcc
CFLAGS     = -Wall -pedantic
LIB        = -lm
FILE23     = c07e23
OBJ27      = c07e27.o c07e27-main.o ex7-4-lines.o

all: c07e23 c07e27

c07e23: c07e23.o
	$(CC) $(CFLAGS) -o $@ $^

c07e27: $(OBJ27)
	$(CC) $(CFLAGS) $(OBJ27) -o $@

c07e23.o: c07e23.c c07e23.h
	$(CC) $(CFLAGS) -c -o $@ $<

c07e27.o: c07e27.c c07e27.h
	$(CC) $(CFLAGS) -c -o c07e27.o c07e27.c

ex7-4-lines.o: ex7-4-lines.c ex7-4-lines.h 
	$(CC) $(CFLAGS) -c $<

c07e27-main.o: c07e27-main.c ex7-4-lines.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(FILE23) c07e27

