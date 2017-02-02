/*
 * File: x7-25main.c
 * Application of the module for reading and writing doubles
 *
 * the application expects two command line arguments: the
 * name of the input and output files; it reads values from the input
 *	file, and writes them to the output file
 */

#include <stdio.h>
#include <stdlib.h>
#include "x7-25double.h"

#define WIDTH		(4)

int main(int argc, char *argv[]) {
	FILE *inFile;
	FILE *outFile;
	double val;

	if( argc != 3 ){
		printf("Usage: programName inputTextFileName outputFileName\n");
		return EXIT_FAILURE;
	}

	/* open input file */
	if((inFile = fopen( argv[1], "r")) == NULL) {
		fprintf(stderr, "could not open input file, exiting \n");
		return EXIT_FAILURE;
	}

	/* open output file */
	if((outFile = fopen( argv[2], "w")) == NULL) { 
		fprintf(stderr, "could not open output file, exiting \n");
		return EXIT_FAILURE;
	}

	while(1) {
		val = getDouble(inFile);
		if(feof(inFile)) /* check if we are at end of file */
			break; 

		if(isError()) {
			/* otherwise an error occured while reading */
			fprintf(stderr, "Error reading value from inFile, ignoring ... \n");
			clearError();
		} else {
			putDouble(val, outFile, WIDTH);
			if(isError()) {
				fprintf(stderr, "Error writing value to outFile, ignoring ... \n");
				clearError();
			}
		}
	}
	
	/* close input file */
	if(fclose(inFile) == EOF) {
		fprintf(stderr, "could not close input file, exiting \n");
		return EXIT_FAILURE;
	}

	/* close output file */
	if(fclose(outFile) == EOF) {
		fprintf(stderr, "could not close output file, exiting \n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
