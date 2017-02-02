/*
 * File: ex7-5-io1.c
 * Implementation of the module with two simple I/O operations
 * to read and print an integer, and possibly set the error code.
 * The error code is not explicitly available to the client.
 * There are two functions to deal with errors:
 *   isError_IO1() to enquire about error
 *   printError_IO1() to print a description of the error 
 *          on the standard error stream
 ***************************************************************
 * This implementation uses the existing module IO
 */

#include "ex7-5-io.h"
#include "ex7-5-io1.h"

/* 
 * Function: getInt_IO1
 * Purpose: clear the error flag and read from a given file
 *    a single integer and return it.
 * Inputs: file descriptor f (parameter)
 * Returns: the integer read, 0 if fails
 * Modifies: the error flag and the current position in the file
 * Error checking: If an integer can not be read, the error flag is
 *                  set (see error routines below).
 * Sample call:
 *    i = GetInt_IO1(f);
 *    if(isError_IO1()) {
 *      printError_IO1();
 *    }
 *
 */
int getInt_IO1(FILE *f) {
	clearError_IO();
	return getInt_IO(f);
}

/* 
 * Function: putInt_IO1
 * Purpose: clear the error flag and print a single integer to a given file 
 * Inputs: file descriptor f and integer i (parameters)
 * Returns: nothing
 * Modifies: the error flag
 * Error checking: If an integer can not be printed, the error flag is
 *                  set (see error routines below).
 * Sample call:
 *    putInt_IO1(f, i);
 *    if(isError_IO1()) {
 *      printError_IO1();
 *    }
 *
 */
void putInt_IO1(FILE *f, int i) {
	clearError_IO();
	putInt_IO(f, i);
}

/**********   Error routines *******/

/* 
 * Function: isError_IO1
 * Purpose: test for an error flag 
 * Inputs: Nothing
 * Returns: 1 if the error flag is raised, 0 otherwise
 * Modifies: Clears the error flag
 * Error checking: None
 * Sample call:
 *     i = isError_IO1();
 *
 */
int isError_IO1(void) {
	return isError_IO();
}

/* 
 * Function: printError_IO1
 * Purpose: print on the standard error stream an error description 
 *    (nothing if the error flag is not set)
 * Inputs: Nothing
 * Returns: Nothing
 * Modifies: Nothing
 * Error checking: None
 * Sample call:
 *      printError_IO1();
 *
 */
void printError_IO1(void) {
	printError_IO();
}
