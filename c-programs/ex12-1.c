/* 
 * File: ex12-1.c
 */

typedef enum {
	real, string
} TagTypeT;

#define MAXSTR 80 /* maximum size of a string */
typedef union {
	double d;
	char s[MAXSTR+1];
} DoubleOrStringT;

typedef struct {
	TagTypeT tag;
	DoubleOrStringT value;
} TaggedValueT;

#define MAX  100  /* maximum number of items */

/*
 * Function: readFile
 * Purpose: read a text file and store double values and strings in the array of unions
 * At most MAX items are read, and each string has at most MAXSTR characters
 * Inputs: filename, and storage - an array of TaggedValues
 * Returns: number of items read, EOF if can not open a file
 * Modifies: the array
 * Error checking: stops reading on error, and returns what has been read
 *	Doesn't report an error if the file can not be closed
 * Sample call:
 *    if((i = readFile("a.dat", storage)) == EOF)
 *	error
 */
int readFile(const char *fname, TaggedValueT storage[]);

/*
 * Function: showDoubles
 * Purpose: output all double values from the array of unions, 5 doubles per line
 * Inputs: storage - an array of TaggedValues, and size - number of elements in storage
 * Returns: nothing
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *    showDoubles(storage, 10);
 */
void showDoubles(TaggedValueT storage[], int size);

/*
 * Function: showStrings
 * Purpose: output all strings from the array of unions, each string on a separate line
 * Inputs: storage - an array of TaggedValues, and size - number of elements in storage
 * Returns: nothing
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *    showStrings(storage, 10);
 */
void showStrings(TaggedValueT storage[], int size);

/*
 * Application of the above functions
 * The name of the input file is passed on the command line
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	int size;
	TaggedValueT storage[MAX];

	if(argc != 2) {
		fprintf(stderr, "usage %s filename\n", argv[0]);
		return EXIT_FAILURE;
	}
 	if((size = readFile(argv[1], storage)) == EOF) {
		fprintf(stderr, "can't open %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	printf("Double values:\n");
	showDoubles(storage, size);
	printf("Strings:\n");
	showStrings(storage, size); 

	return EXIT_SUCCESS;
}

int readFile(const char *fname, TaggedValueT storage[]) {
	FILE *in;
 	char buffer[MAXSTR+1];
	double aux;
	int size = 0;

	if((in = fopen(fname, "r")) == NULL)
		return EOF;

	/* start reading */
	while(1) 
		/* first try to read a double */
		if(fscanf(in, "%lf", &aux) == 1) { /* store it */
			storage[size].tag = real;
			storage[size].value.d = aux;
			size++;
		} else { /* try to read a string */
			if(fscanf(in, "%80s", buffer) == 1) { /* store */
				storage[size].tag = string;
				strcpy(storage[size].value.s, buffer);
				size++; 
			} else /* can't read anything 
				* stop no matter whether it is eof or error 
				*/
			   break;
		}
	fclose(in);
	return size;
}

void showDoubles(TaggedValueT storage[], int size) {
	int i;
	int count = 0;
	const int NUM_PER_LINE = 5;

	for(i = 0; i < size; i++) {
		if(count == NUM_PER_LINE) {
			putchar('\n');
			count = 0;
		}
		count++;
		if(storage[i].tag == real)
			printf("%f\n", storage[i].value.d);
	}
}

void showStrings(TaggedValueT storage[], int size) {
	int i;

	for(i = 0; i < size; i++) {
		if(storage[i].tag ==string)
			printf("%s\n", storage[i].value.s);
	}
}

