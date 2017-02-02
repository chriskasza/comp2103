/*
 * File: x8-5.c
 * Program to read a file. The first value in the file is an integer n;
 *	it allocates a block of memory to hold n doubles, and then reads
 * these doubles from the text file.
*/

#include <stdio.h>
#include <stdlib.h>
#include "x8-doubleFileIO.h"

/*
 * Function:  compare
 * Purpose:   function passed to qsort; compares the two elements
 * Inputs:    two elements of type double
 * Returns:   0 if elements are  equal, 1 if the first is bigger
 *					than the second, and -1 otherwise
 * Modifies:  --
 * Error checking:  --
 */
static int compare( const void *elem1, const void *elem2){
	double *p1, *p2;

	p1 = (double *)elem1;
	p2 = (double *)elem2;

	if( *p1 == *p2 ) return 0;
	if( *p1 < *p2 ) return -1;
        return 1;
}

int main(int argc, char *argv[]) {
	FILE *inFile;
	int i, size;
	double *block;

	if(argc != 2) {
		printf("Usage: programName inputTextFileName\n");
		return EXIT_FAILURE;
	}

	/* open input file */
	if((inFile = fopen( argv[1], "r+")) == NULL) {
		fprintf(stderr, "could not open input file %s, exiting\n", argv[1]);
		return EXIT_FAILURE;
	}

	/* read the value from the file */
	if(fscanf(inFile,"%d", &size) != 1) {
                fclose(inFile);
		fprintf(stderr, "Could not read the size from the file \n");
		return EXIT_FAILURE;
	}

	/* check that size is valid */
	if(size <= 0) {
                fclose(inFile);
		fprintf(stderr, "Size must be greater than zero \n");
		return EXIT_FAILURE;
	}

	/* allocate the block of memory */
	if((block = calloc(size, sizeof(double))) == NULL) {
                fclose(inFile);
                fprintf(stderr, "Could not allocate block of memory, exiting \n");	
		return EXIT_FAILURE;
	}

	/* read the data from the file into the memory block */
	if(readDoublesFromFile(inFile, block, size) == 0) {
                free(block);
                fclose(inFile);
		fprintf(stderr, "read error from input file\n");
		return EXIT_FAILURE;
	}
	
	/* sort the block of memory */
	qsort((void *)block, size, sizeof(double), compare);

	/* write the contents of sorted block to the file */
        if(fseek(inFile, 0, SEEK_END) != 0){
            fclose(inFile);
            fprintf(stderr, "file error\n");
            return EXIT_FAILURE;
        }
	fprintf(inFile, "\n\nSorted data \n");
	for(i = 0; i < size; i++)
		if(fprintf(inFile, "%f\n", block[i]) == EOF) {
			fprintf(stderr, "could not print to output file \n");
                        fclose(inFile);
			free( block );
			return EXIT_FAILURE;
		}

	if(fclose(inFile ) == EOF) {
		fprintf(stderr, "could not close output file, exiting \n");
		free(block);
		return EXIT_FAILURE;
	}

	free(block);
	return EXIT_SUCCESS;
}
