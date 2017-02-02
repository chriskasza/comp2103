/*
 * File: ex7-5-io1-main1.c
 * An application of the file I/O module IO1
 * Reads from stdin integers; outputs valid integers and 
 * for invalid integers outputs an error message and skips a single input
 * character
 * Stops after having read 10 valid integers
 */
#include "ex7-5-io1.h"
#include <stdlib.h>
int main() {
	const int LIMIT = 10;
	int d, i;

	printf("Enter 10 integer values \n");
	for(i = 0; i < LIMIT; ) {
		d = getInt_IO1(stdin);
		if(isError_IO1()) {
			printError_IO1();
			if(getchar() == EOF)
				return EXIT_SUCCESS;
		} else {	/* valid integer */
			putInt_IO1(stdout, d);	
			putchar('\n');
			i++;
		}
	}
	 
	return EXIT_SUCCESS;
}
