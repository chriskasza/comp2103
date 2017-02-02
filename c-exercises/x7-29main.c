/*
 * File: x7-29main.c
 * Application of the module fraction to perform operations on fractions
 * the program expects a file name from the command line: inputFile
 * The input file contains fraction pairs of the form;
 *		numerator1  denominator1  numerator2  denominator2 <newline>
 * it writes the result of the various operations to the standard output
 */

#include <stdio.h>
#include <stdlib.h>
#include "x7-29fraction.h"

/* 
 * Function: SkipLine
 * Purpose: helper function, skips a line of text in the input file
*/
static void SkipLine(FILE *inFile) {
	while(getc(inFile) != '\n')
		;
}

int main(int argc, char *argv[]) {
	FILE *inFile;
	int num1, den1, num2, den2;
	int res;

	if(argc != 2) {
		printf("Usage: programName inputTextFileName outputFileName\n");
		return EXIT_FAILURE;
	}

	/* open input file */
	if((inFile = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "could not open input file, exiting \n");
		return EXIT_FAILURE;
	}

	while(1) {
		res = fscanf(inFile, "%d%d%d%d", &num1, &den1, &num2, &den2);
		if(res == EOF) 
			break;

		if(res != 4) {
			fprintf(stderr,"Incorrect format in input file, ignoring line... \n");
			SkipLine( inFile );
			clearError();
			continue;
		}

		/* input fraction */
		printf("read the following fraction pair: %d / %d and %d / %d \n",
					num1, den1, num2, den2);

		/* initialize the fraction */
		InitializeFractionPair( num1, den1, num2, den2 );
		
		if(isError()) {
			fprintf(stderr,"Incorrect data in input file, ignoring ... \n");
			clearError();
                        continue;
		}

		/* add the fraction */
		AddFractionPair();
		printf("Added the fraction pair, result is: "); 
		PrintFractionResult();

		/* subtract the fraction */
               SubtractFractionPair();
		/* alternately, we can print the result directly in the main program */
                printf("Subtracted the fraction pair, result is: %d / %d ", 
				GetNumeratorResult(), GetDenominatorResult() );

		/* multiply the fraction */
		MultiplyFractionPair();
		printf("Multiplied the fraction pair, result is: ");
		PrintFractionResult();

		/* divide the fraction */
               DivFractionPair(); 
               printf("Divided the fraction pair, result is: ");
		PrintFractionResult();

	}
	
	/* close input file */
	if(fclose(inFile) == EOF) {
		fprintf(stderr, "could not close input file, exiting \n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
