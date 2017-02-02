/*
 * File: ex7-5-io-main1.c
 * An application of the file I/O module IO
 * Reads from stdin integers; outputs valid integers and 
 * for invalid integers outputs an error message and skips a single input
 * character
 * Stops after having read 10 valid integers
 */
#include "ex7-5-io.h"
#include <stdlib.h>

int main() {
	const int LIMIT = 10;
	int d, i;

	printf("Enter up to 10 integer values\n");
	printf("Correct values will be displayed, for incorrect values\
	a single character will be skipped\n");
	for(i = 0; i < LIMIT; ) {
		clearError_IO();
		d = getInt_IO(stdin);
		if(isError_IO()) {
			printError_IO();
			clearError_IO();
			if(getchar() == EOF) /* skip one char */
				return EXIT_SUCCESS;
		} else {	/* valid integer */
			putInt_IO(stdout, d);	
			if(isError_IO()) {
				printError_IO();
				clearError_IO();
			} else putchar('\n');
			i++;
		}
	}
	 
	return EXIT_SUCCESS;
}
