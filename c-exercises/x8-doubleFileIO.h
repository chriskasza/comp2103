#ifndef X8_DOUBLEFILEIO_H
#define X8_DOUBLEFILEIO_H

/*
 * File: x8-doubleFileIO.h
 * A header file for the reading of and writing to double values to
 *			and from text files
 * Operations: read n values into block from a text file
 *			write n values from a block to a text file
*/


/*
 * Function:  readDoublesFromFile
 * Purpose:  read n values into block from a text file
 * Inputs:   [inFile] text file containing double values
 *			[block] memory block large enough to hold size elements
 * Returns:  the number of values read successfully
 * Modifies:  the contents of the block
 * Error checking:  checks the result of each read operation
 * Assumes: incoming file is open; input file contains <= size values
 */
int readDoublesFromFile(FILE *inFile, double *block, int size);

/*
 * Function:  writeDoublesToFile
 * Purpose:  read n values from block to a text file
 * Inputs:   [outFile] text file to write to
 *           [block] memory block holding values, of size size
 * Returns:  1 on success, 0 on failure
 * Modifies:  the output file
 * Error checking:  checks the result of each write operation
 */
int writeDoublesToFile(FILE *outFile, double *block, int size );

#endif

