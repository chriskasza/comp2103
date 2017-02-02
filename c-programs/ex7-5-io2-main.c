/*
 * File: ex7-5-io2-main.c
 * An application of the file I/O module IO2
 * Initialize I/O streams: read from in.dat and write to a file out.dat.
 * If any of these files can not be open, use standard streams instead.
 */
#include <stdlib.h>
#include <stdio.h>
#include "ex7-5-io2.h"
int main() {
	int d;
	
	switch(constructReadWrite_IO2("in.dat", "out.dat")) {

	case OK_IO2:		/*success */
				printf("input: %s\n", "in.dat");
				printf("output: %s\n", "out.dat");
				break;	

	case FAIL_READ_IO2:	
				printf("input: %s\n", "stdin");
				printf("output: %s\n", "out.dat");
				(void)constructRead_IO2(NULL);
				break;

	case FAIL_WRITE_IO2:	
				printf("input: %s\n", "in.dat");
				printf("output: %s\n", "stdout");
				(void)constructWrite_IO2(NULL);
				break;

	case FAIL_IO2:	
				printf("input: %s\n", "stdin");
				printf("output: %s\n", "stdout");
				(void)constructReadWrite_IO2(NULL, NULL);
				break;
	}

	clearError_IO2();

	printf("Enter an integer value\n");
	d = getInt_IO2();
	if(isError_IO2()) { 
		printError_IO2();
		clearError_IO2();
	} else putInt_IO2(d);

	printf("Enter another integer value\n");
	putInt_IO2(getInt_IO2());
		 
	return EXIT_SUCCESS;
}

