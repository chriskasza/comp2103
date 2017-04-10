CC         = gcc
CFLAGS     = -Wall -pedantic -std=c89
LIB        = -lm
BINS       = c09e03 c09e07
#BINS       = c09e03 c09e07 c09e11
OBJ03      = c09e03.o c09e03-main.o
OBJ07      = c09e07.o c09e07-main.o
#OBJ11      = c09e11.o c09e11-main.o

all: $(BINS)

clean:
	rm -f *.o $(BINS)


c09e03: $(OBJ03)
	$(CC) $(CFLAGS) -o $@ $^

c09e03.o: c09e03.c
	$(CC) $(CFLAGS) -c $<

c09e03-main.o: c09e03-main.c
	$(CC) $(CFLAGS) -c $<


c09e07: $(OBJ07)
	$(CC) $(CFLAGS) -o $@ $^

c09e07.o: c09e07.c
	$(CC) $(CFLAGS) -c $<

c09e07-main.o: c09e07-main.c
	$(CC) $(CFLAGS) -c $<


#c09e11: $(OBJ11)
#	$(CC) $(CFLAGS) -o $@ $^ $(LIB)
#
#c09e11.o: c09e11.c
#	$(CC) $(CFLAGS) -c $<
#
#c09e11-main.o: c09e11-main.c
#	$(CC) $(CFLAGS) -c $<

