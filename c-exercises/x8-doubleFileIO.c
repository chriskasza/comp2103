
/*
 * File: x8-doubleFileIO.h
 * The implementation file for the reading of and writing to double values to
 *       and from text files
 * Operations: read n values into block from a text file
 *             write n values from a block to a text file
*/

#include <stdio.h> 
#include "x8-doubleFileIO.h"

/*
 * Function:  readDoublesFromFile
 * Purpose:  read n values into block from a text file
 * Inputs:   [inFile] text file containing double values
 *           [block] memory block large enough to hold size elements
 * Returns:  the number of values read successfully
 * Modifies:  the contents of the block
 * Error checking:  checks the result of each read operation
 * Assumes: incoming file is open
 */
int readDoublesFromFile(FILE *inFile, double *block, int size) {
	int res;
        int i = 0;
	double val;

	if(size <= 0) 
		return 0 ; /* error checking */

	/* read the values from the file */
	while(1) {

		res = fscanf(inFile, "%lf", &val); 
		if(res == EOF) /* end of file */
			return i;
		if(res != 1)
			return 0; /* an error occured */
		
		if(i >= size)
			return i; /* out of bounds, incorrect size specified */

		block[ i++ ] = val;
	}
	return i;	
}

/*
 * Function:  writeDoublesToFile
 * Purpose:  read n values from block to a text file
 * Inputs:   [outFile] text file to write to
 *           [block] memory block holding values, of size size
 * Returns:  1 on success, 0 on failure
 * Modifies:  the output file
 * Error checking:  checks the result of each write operation
 */
int writeDoublesToFile(FILE *outFile, double *block, int size) {
	int i;

	if( fprintf(outFile,"%d\n", size ) == EOF )
		return 0;

	for(i = 0; i < size; i++)
		if(fprintf(outFile,"%f\n", block[i]) == EOF)
			return 0; /* error */
	return 1;
}

