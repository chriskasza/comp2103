CC     = gcc
CFLAGS = -Wall -pedantic
LIB    = -lm
FILE23 = c07e23
FILE27 = c07e27
DEPS23 = $(FILE23).h
OBJ23  = $(FILE23).o
DEPS27 = $(FILE27).h
OBJ27  = ex7-4-lines.o c07e27-main.o


c07e23: c07e23.o
	$(CC) $(CFLAGS) -o $@ $^

c07e27: $(OBJ27)
	$(CC) $(CFLAGS) $(OBJ27) -o c07e27


c07e23.o: c07e23.c c07e23.h
	$(CC) $(CFLAGS) -c -o $@ $<

ex7-4-lines.o: ex7-4-lines.h ex7-4-lines.c
	$(CC) $(CFLAGS) -c ex7-4-lines.c

c07e27-main.o: c07e27-main.c ex7-4-lines.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(FILE23) $(FILE27)

