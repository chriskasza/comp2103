#ifndef IO2_H
#define IO2_H
/*
 * File: ex7-5-io2.h
 * A header of the module with two simple I/O operations
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
 */

/*** macros that represent return codes ****/
#define OK_IO2 		1
#define FAIL_IO2 	0
#define FAIL_WRITE_IO2 	2
#define FAIL_READ_IO2 	3

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
int constructRead_IO2(char *name);

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
int constructWrite_IO2(char *name);

/*
 * Function: constructReadWrite_IO2
 * Purpose: constructor to open two files, respectively for reading and writing.
 * By convention, a NULL name indicates standard input/output.
 * Inputs: inFilename and outFilename (parameters)
 * Returns: OK_IO2 if successful, FAIL_IO2 if fails, 
 *	FAIL_WRITE_IO2 if only input has been opened
 *     and FAIL_READ_IO2 if only output has been opened
 * Modifies: The global file descriptor and both flags
 * Error checking: Checks if previously called, and if so
 *   does nothing and returns FAIL_IO2
 * Sample call:
 *   i = constructReadWrite_IO2(, NULL, "output.dat");
 */
int constructReadWrite_IO2(char *inFilename, char *outFilename);
 
/* 
 * Function: getInt_IO2
 * Purpose: read from a given file a single integer and return it.
 * This file has to be opened 
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
int getInt_IO2(void);

/* 
 * Function: putInt_IO2
 * Purpose: print a single integer to a given file 
 * This file has to be opened 
 * Inputs: integer i (parameter)
 * Returns: nothing
 * Modifies: Nothing
 * Error checking: If an integer can not be printed because the output stream
 *   has not been opened, return 0; otherwise the error flag is
 *                  raised (see error routines below).
 */
void putInt_IO2(int i);

/**********   Error routines *******/

/* 
 * Function: clearError_IO2
 * Purpose: clear an error flag 
 * Inputs: Nothing
 * Returns: Nothing
 * Modifies: Nothing
 * Error checking: None
 * Sample call:
 *      clearError_IO2();
 *
 */
void clearError_IO2(void);

/* 
 * Function: isError_IO2
 * Purpose: test for an error flag 
 * Inputs: Nothing
 * Returns: 1 if the error flag is raised, 0 otherwise
 * Modifies: Clears the error flag
 * Error checking: None
 * Sample call:
 *     i = isError_IO2();
 *
 */
int isError_IO2(void);

/* 
 * Function: printError_IO2
 * Purpose: print on the standard error stream an error description 
 *    (nothing if the error flag is not set)
 * Inputs: Nothing
 * Returns: Nothing
 * Error checking: None
 * Sample call:
 *      printError_IO2();
 */
void printError_IO2(void);

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
int destructRead_IO2();

/* 
 * Function: destructWrite_IO2();
 * Purpose: close the output file opened by the constructor
 * Inputs: Nothing
 * Returns: 1 if the constructor has been called; 0 otherwise
 * Error checking: None
 * Sample call:
 *      if(destructWrite_IO2() == 0) error;
 */
int destructWrite_IO2();

/* 
 * Function: destructReadWrite_IO2();
 * Purpose: close the input and the output files opened by the constructor
 * Inputs: Nothing
 * Returns: 1 if the constructor has been called; 0 otherwise
 * Error checking: None
 * Sample call:
 *      if(destructReadWrite_IO2() == 0) error;
 */
int destructReadWrite_IO2();
#endif
