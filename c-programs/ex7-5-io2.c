/*
 * File: ex7-5-io2.c
 * Implementation of the module with two simple I/O operations
 * 	to read and print an integer
 * There are three constructor functions, respectively to open an input stream
 *	an output stream, or both.
 * Macros representing returns values from these constructors are available to the client.
 * Constructor functions must be called before any other operation is performed.
 * The error code is not explicitly available to the client.
 * There are three functions to deal with errors:
 *   isError_IO2() to enquire about error
 *   clearError_IO2() to clear any error indication
 *   printError_IO2() to print a description of the error 
 *          on the standard error stream
 ***************************************************************
 * This implementation uses the existing module IO
 * There are two internal flags to check if the input and the output streams have been opened.
 */

#include "ex7-5-io.h"
#include "ex7-5-io2.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *fInput_ = NULL;		/* file handles */
static FILE *fOutput_ = NULL;

#define NOT_INITIALIZED 0	/* macros for testing initialization */
#define INITIALIZED 	1

static int initializedInput_ = 	NOT_INITIALIZED;
static int initializedOutput_ = NOT_INITIALIZED;

#define READ 	1			/* macros for testing errors */
#define WRITE 	2
#define OK 	0
static int ioErrorFlag_ = OK;  /* used when doing I/O before initialization */
 
/*
 * Function: constructRead_IO2
 * Purpose: constructor to open a file with the given name for reading. 
 * By convention, a NULL name indicates standard input.
 * Inputs: File name (parameter)
 * Returns: OK_IO2 if successful, FAIL_IO2 otherwise
 * Modifies: The global file descriptor and a flag
 * Error checking: Checks if previously called, and if so
 *   does nothing and returns FAIL_IO2
 * Sample call:
 *  i = constructRead_IO2("input.dat");
 */
int constructRead_IO2(char *fname) {
	if(initializedInput_ == INITIALIZED) 
		return FAIL_IO2;

	if(fname == NULL) { /* stdin is always opened */
		initializedInput_ = INITIALIZED;
		fInput_ = stdin;
		return OK_IO2;
	}

	if((fInput_ = fopen(fname, "r")) == NULL)
		return FAIL_IO2;
	initializedInput_ = INITIALIZED;

	return OK_IO2;
}

/*
 * Function: constructWrite_IO2
 * Purpose: constructor to open a file with the given name for writing.
 * By convention, a NULL name indicates standard output.
 * Inputs: File name (parameter)
 * Returns: OK_IO2 if successful, FAIL_IO2 otherwise
 * Modifies: The global file descriptor and a flag
 * Error checking: Checks if previously called, and if so
 *   does nothing and returns FAIL_IO2
 * Sample call:
 *   i = initWrite_IO2("output.dat");
 */
int constructWrite_IO2(char *fname){
	if(initializedOutput_ == INITIALIZED) 
		return FAIL_IO2;
	if(fname == NULL) { /* stdout is always opened */
		initializedOutput_ = INITIALIZED;
		fOutput_ = stdout;
		return OK_IO2;
	}
	if((fOutput_ = fopen(fname, "w")) == NULL)
		return FAIL_IO2;
	initializedOutput_ = INITIALIZED;

	return OK_IO2;
}

/*
 * Function: constructReadWrite_IO2
 * Purpose: constructor to open two files, respectively for reading and writing
 * By convention, a NULL name indicates standard input/output.
 * Inputs: inFilename and outFilename (parameters)
 * Returns: OK_IO2 if successful, FAIL_IO2 if fails, 
 *	FAIL_WRITE_IO2 if only input has been opened
 *     and FAIL_READ_IO2 if only output has been opened
 * Modifies: The global file descriptor and both flags
 * Error checking: Checks if previously called, and if so
 *   does nothing and returns FAIL_IO2
 * Sample call to read from the standard input:
 *   i = constructReadWrite_IO2(NULL, "output.dat");
 */
int constructReadWrite_IO2(char *inFilename, char *outFilename) {
	int r = constructRead_IO2(inFilename);
	int w = constructWrite_IO2(outFilename);

	if(r == FAIL_IO2)
		if(w == FAIL_IO2)
			return FAIL_IO2;
		else return FAIL_READ_IO2;
	else if(w == 0)
		return FAIL_WRITE_IO2;
	     else return OK_IO2;
}

/* 
 * Function: getInt_IO2
 * Purpose: read from a given file a single integer and return it.
 * This file has to be opened using initRead_IO2()
 * Inputs: None
 * Returns: the integer read, 0 if fails
 * Modifies: Nothing (except the current position in the file)
 * Error checking: If an integer can not be read because the input stream
 *   has not been opened, return 0; otherwise the error flag is
 *                  raised (see error routines below).
 * Sample call:
 *    i = getInt_IO2();
 *
 */
int getInt_IO2(void) {
	if(initializedInput_ == NOT_INITIALIZED) 	{
		ioErrorFlag_ = READ;
		return 0;
	}
	return getInt_IO(fInput_);
}

/* 
 * Function: putInt_IO2
 * Purpose: print a single integer to a given file 
 * This file has to be opened using initWrite_IO2()
 * Inputs: file descriptor f and integer i (parameters)
 * Returns: nothing
 * Modifies: Nothing
 * Error checking: If an integer can not be read because the input stream
 *   has not been opened, return 0; otherwise the error flag is
 *                  raised (see error routines below).
 */
void putInt_IO2(int i) {
	if(initializedOutput_ == NOT_INITIALIZED) 	{
		ioErrorFlag_ = WRITE;
		return; 
	}
	putInt_IO(fOutput_, i);
}

/**********   Error routines *******/

/* 
 * Function: clearError_IO2
 * Inputs: Nothing
 * Returns: Nothing
 * Modifies: Nothing
 * Error checking: None
 * Sample call:
 *      clearError_IO2();
 *
 */
void clearError_IO2(void) {
	ioErrorFlag_ = OK;
	clearError_IO();
}

/* 
 * Function: isError_IO2
 * Purpose: test for an error flag 
 * Inputs: Nothing
 * Returns: 1 if the error flag is raised, 0 otherwise
 * Modifies: Nothing
 * Error checking: None
 * Sample call:
 *     i = isError_IO2();
 *
 */
int isError_IO2(void) {
	return ioErrorFlag_ != OK || isError_IO();
}

/* 
 * Function: printError_IO2
 * Purpose: rint on the standard error stream an error description 
 *    (nothing if the error flag is not set)
 * Inputs: Nothing
 * Returns: Nothing
 * Modifies: Nothing
 * Error checking: None
 * Sample call:
 *      printError_IO2();
 *
 */
void printError_IO2(void) {
	switch(ioErrorFlag_) {
	case READ: fprintf(stderr, "input not initialized\n"); 
		    break;
	case WRITE: fprintf(stderr, "output not initialized\n"); 
		    break;
	default: break;
	}
	printError_IO();
}

/************************************/


/* 
 * Function: destructRead_IO2();
 * Purpose: close the input file opened by the constructor
 * Inputs: Nothing
 * Returns: 1 if the constructor has been called; 0 otherwise
 * Error checking: None
 * Sample call:
 *      if(destructRead_IO2() == 0) error;
 */
int destructRead_IO2() {
	if(initializedInput_ == NOT_INITIALIZED) 
		return FAIL_IO2;

	if(fInput_ == stdin)
		return OK_IO2;

	if(fclose(fInput_) == EOF)
		return FAIL_IO2;

	ioErrorFlag_ = OK;
	initializedInput_ = NOT_INITIALIZED;

	return OK_IO2;
}

/* 
 * Function: destructWrite_IO2();
 * Purpose: close the output file opened by the constructor
 * Inputs: Nothing
 * Returns: 1 if the constructor has been called; 0 otherwise
 * Error checking: None
 * Sample call:
 *      if(destructWrite_IO2() == 0) error;
 */
int destructWrite_IO2() {
	if(initializedOutput_ == NOT_INITIALIZED) 
		return FAIL_IO2;

	if(fOutput_ == stdout)
		return OK_IO2;

	if(fclose(fOutput_) == EOF)
		return FAIL_IO2;

	ioErrorFlag_ = OK;
	initializedOutput_ = NOT_INITIALIZED;

	return OK_IO2;
}

/* 
 * Function: destructReadWrite_IO2();
 * Purpose: close the input and the output files opened by the constructor
 * Inputs: Nothing
 * Returns: 1 if the constructor has been called; 0 otherwise
 * Error checking: None
 * Sample call:
 *      if(destructReadWrite_IO2() == 0) error;
 */
int destructReadWrite_IO2() {
	if(initializedOutput_ == NOT_INITIALIZED ||
			initializedInput_ == NOT_INITIALIZED)
		return FAIL_IO2 ;
	return destructRead_IO2() && destructWrite_IO2();
}
