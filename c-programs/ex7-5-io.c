/*
 * File: ex7-5-io.c
 * Implementation of the module with two simple I/O operations
 * to read and print an integer, and possibly set the error code.
 * The error code is not explicitly available to the client.
 * There are three functions to deal with errors:
 *   isError_IO() to enquire about error
 *   clearError_IO() to clear any error indication
 *   printError_IO() to print a description of the error 
 *          on the standard error stream
 */
#include "ex7-5-io.h"

/* error codes */
#define INPUT 	1
#define OUTPUT 	2
#define OK	0

static int errorFlag_ = OK;

/* 
 * Function: getInt_IO
 * Purpose: read from a given file a single integer and return it.
 * Inputs: file descriptor f (parameter)
 * Returns: the integer read, 0 if fails
 * Modifies: Nothing (except the current position in the file)
 * Error checking: If an integer can not be read, the error flag is
 *                  raised (see error routines below).
 * Sample call:
 *    clearError_IO();
 *    i = getInt_IO(f);
 *    if(isError_IO()) {
 *      printError_IO();
 *    }
 *
 */
int getInt_IO(FILE *f) {
	int i;

	if(fscanf(f, "%d", &i) != 1) {
		errorFlag_ = INPUT;
		return 0;
	}
	return i;
}

/* 
 * Function: putInt_IO
 * Purpose: print a single integer to a given file 
 * Returns: nothing
 * Error checking: If an integer can not be printed, the error flag is
 *                  raised (see error routines below).
 * Sample call:
 *    clearError_IO();
 *    putInt_IO(f, i);
 *    if(isError_IO()) {
 *      printError_IO();
 *    }
 */
void putInt_IO(FILE *f, int i) {
	if(fprintf(f, "%d", i) == EOF) 
		errorFlag_ = OUTPUT;
}

/**********   Error routines *******/

/* 
 * Function: clearError_IO
 * Purpose: clear an error flag
 * Inputs: Nothing
 * Returns: Nothing
 * Error checking: None
 * Sample call: clearError_IO();
 */
void clearError_IO(void) {
	errorFlag_ = OK;
}

/* 
 * Function: isError_IO
 * Purpose: test for an error flag 
 * Inputs: Nothing
 * Returns: 1 if the error flag is raised, 0 otherwise
 * Error checking: None
 * Sample call:  i = isError_IO();
 */
int isError_IO(void) {
	return errorFlag_ != OK;
}

/* 
 * Function: printError_IO
 * Purpose: print on the standard error stream an error description 
 *    (nothing if the error flag is not set)
 * Inputs: Nothing
 * Returns: Nothing
 * Error checking: None
 * Sample call: printError_IO();
 */
void printError_IO(void) {
	switch(errorFlag_) {
	case INPUT: fprintf(stderr, "input failed\n"); 
		    return;
	case OUTPUT: fprintf(stderr, "output failed\n"); 
		    return;
	case OK:    return;
	default:    fprintf(stderr, "unknown error\n"); 
		    return;
	}
}
