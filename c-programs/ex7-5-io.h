#include <stdio.h>
#ifndef IO_H
#define IO_H
/*
 * File: ex7-5-io.h
 * A header of the module with two simple I/O operations
 *   to read and print an integer from a file, and possibly 
 *   set the error code. The file must be opened for reading.
 * The error code is not explicitly available to the client.
 * There are three functions to deal with errors:
 *   isError_IO() to inquire about error
 *   clearError_IO() to clear any error indication
 *   printError_IO() to print a description of the error 
 *          on the standard error stream
 */

/* 
 * Function: getInt_IO
 * Purpose:	read from a given file a single integer and return it.
 * Inputs:	file descriptor f, must be opened for reading (parameter)
 * Returns:	the integer read, 0 if fails
 * Modifies: nothing (except the current position in the file)
 * Error checking: If an integer can not be read, the error flag is
 *   raised (see error routines below).
 * Sample call: 
 *   clearError_IO();
 *    i = getInt_IO(f);
 *    if(isError_IO()) 
 *      printError_IO();
 *      
 */
int getInt_IO(FILE *f);

/* 
 * Function: putInt_IO
 * Purpose:	print a single integer to a file (must be opened for output)
 * Inputs:	file descriptor f and integer i (parameters)
 * Returns:	nothing
 * Error checking: If an integer can not be printed, the error flag is
 *   raised (see error routines below).
 * Sample call:
 *    clearError_IO();
 *    putInt_IO(f, i);
 *    if(isError_IO())  
 *      printError_IO();
 */
void putInt_IO(FILE *f, int i);

/**********   Error routines *******/

/* 
 * Function: clearError_IO
 * Purpose:  clear an error flag 
 * Inputs:   nothing
 * Returns:  nothing
 * Error checking: none
 * Sample call:	 clearError_IO();
 */
void clearError_IO(void);

/* 
 * Function: isError_IO
 * Purpose:	test for an error flag 
 * Inputs:	nothing
 * Returns:	1 if the error flag is raised, 0 otherwise
 * Error checking: none
 * Sample call:		
 *     i = isError_IO();
 */
int isError_IO(void);

/* 
 * Function: printError_IO
 * Purpose:	print on the standard error stream an error description 
 *   (nothing if the error flag is not set)
 * Inputs:	nothing
 * Returns:	nothing
 * Error checking: none
 * Sample call:		printError_IO();
 */
void printError_IO(void);

#endif
