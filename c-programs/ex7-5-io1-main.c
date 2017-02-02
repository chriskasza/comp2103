/*
 * File: ex7-5-io1-main.c
 * An application of the IO1  module
 * Reads an integer and if this integer is correct, outputs it
 */
#include "ex7-5-io1.h"
#include <stdlib.h>
int main() {
	int d;

	printf("Enter an integer value\n");
	d = getInt_IO1(stdin);

	if(isError_IO1()) {
		printError_IO1();
	} else {
	    putInt_IO1(stdout, d);
	}
	putchar('\n');
		 
	return EXIT_SUCCESS;
}
