/*
 * File: ex7-5-io-main2.c
 * An application of the file I/O module IO
 * Reads from a file integers; outputs to a file valid integers and 
 * for invalid integers outputs an error message and skips a single input
 * character
 * Stops after having read 10 valid integers
 */
#include "ex7-5-io.h"
#include <stdlib.h>
int main() {
	const int LIMIT = 10;
	int d, i;
	char inFile[FILENAME_MAX];
	char outFile[FILENAME_MAX];
	FILE *in;
	FILE *out;

	/* open I/O files */
	printf("Input filename: ");
	scanf("%s", inFile);
	if((in = fopen(inFile, "r")) == NULL) {
		fprintf(stderr, "can't open %s\n", inFile);
		return EXIT_FAILURE;
	}

	printf("Output filename: ");
	scanf("%s", outFile);
	if((out = fopen(outFile, "w")) == NULL) {
		fprintf(stderr, "can't open %s\n", outFile);
		fclose(in);
		return EXIT_FAILURE;
	}

	/* now, read values */

	for(i = 0; i < LIMIT; ) {
		clearError_IO();
		d = getInt_IO(in);
		if(isError_IO()) {
			printError_IO();
			clearError_IO();
			if(fgetc(in) == EOF) { /* skip one char */
				fclose(in);
				fclose(out);
				return EXIT_SUCCESS;
		       }
		} else {	/* valid integer */
			putInt_IO(out, d);
			if(isError_IO()) {
				printError_IO();
				clearError_IO();
			} else fputc('\n', out);
			i++;
		}
	}
	if(fclose(in) == EOF) {
		fprintf(stderr, "can't close %s\n", inFile);
		fclose(out);
		return EXIT_FAILURE;
	}
	if(fclose(out) == EOF) {
		fprintf(stderr, "can't close %s\n", outFile);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

