/*
 * File: ex7-5-io-main.c
 * An application of the file module IO
 * Reads an integer and if this integer is correct, outputs it
 */
#include "ex7-5-io.h"
#include <stdlib.h>
int main() {
	int d;

	printf("Enter an integer value\n");
	d = getInt_IO(stdin);

	if(isError_IO()) {
		printError_IO();
		clearError_IO();
	} else {
	    putInt_IO(stdout, d);
	    clearError_IO();
	}
	putchar('\n'); 
	return EXIT_SUCCESS;
}
