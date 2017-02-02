CC = gcc
CFLAGS = -Wall -pedantic
FILE23 = c07e23
FILE27 = c07e27
DEPS23 = $(FILE23).h
OBJ23 = $(FILE23).o
DEPS27 = $(FILE27).h
OBJ27 = ex7-4-lines.o c07e27.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

c07e23: $(OBJ23)
	gcc $(CFLAGS) -o $@ $^

c07e27: $(OBJ27)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f *.o $(FILE23) $(FILE27)

