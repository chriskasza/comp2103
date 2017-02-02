/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c07e11.c
 *
 * finds out how many digits in file, abc.dat
 */

#include <stdio.h>
#include <stdlib.h>

// http://ptspts.blogspot.ca/2009/03/ascii-isdigit-isalpha-and-isxdigit.html
#define ISDIGIT(c) ((c) - '0' + 0U <= 9U)

/*
 * Function: countDigits
 * Purpose: counts the number of digits in a given file
 * Inputs: filehandle, f
 * Returns: the number of digits found in f
 * Error checking: will return -1 if unable to open the file
 * Sample call: numDigits = countDigits(f);
 */
int countDigits(FILE *f); 

int main() {
	char *name = "abc.dat";
	int c;
	FILE *f;

	if((f = fopen(name, "r")) == NULL) {
		// failed to open file (f) for reading
		fprintf(stderr, "can't open %s\n", f);
		return EXIT_FAILURE;
	}
	
	c = countDigits(f);
	/*if((c = countDigits(f)) != 1) {
		printf("Unable to calculate number of digits in abc.dat\n");
		return EXIT_FAILURE;
	}*/

	// fclose(f);
	// edited for lost assignment mark
	if((fclose(f)) == NULL) {
		// failed to open file (f) for reading
		fprintf(stderr, "failed to close %s\n", f);
		return EXIT_FAILURE;
	}

	printf("There are %d digits in abc.dat.\n", c);

	return EXIT_SUCCESS;
}

int countDigits(FILE *f) {
	int c;
	int count = 0;

	while((c = fgetc(f)) != EOF) {
		/*if( c > '9' || c < '0' ) {
			// not a digit
		}
		else {
			// is a digit
			count++;
		}*/
		// edited for lost assignment mark
		if (ISDIGIT(c)) {
			// is a digit
			count++;
		}
	}

	return count;
}
	
