CC = gcc
CFLAGS = -Wall
DEPS = c07e15-polyprops.h
OBJ = c07e15-driver.o c07e15-polyprops.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

c07e15-driver: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f *.o

