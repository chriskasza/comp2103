/*
 * File: x7-25double.c
 * The implementation file for the module to read and write double values to a file
 *          module maintains internal error state; it is the user's
 *          responsibility to check for error / clear error after every
 *          read / write operation
 *
 * Operations: reads a double value from a file
 *             writes a double value to a file
 *             checks for error, clear error and print error functions
 *
 * Sample call:
 *
 *       double x = getDouble();
 *       if(isError()) {
 *          printError();
 *          clearError();
 *          exit(1);
 *       }
 *
 * Possible error states include: OK, INPUT_ERROR, OUTPUT_ERROR
*/

#include <stdio.h>
#include <stdlib.h>
#include "x7-25double.h"

#define OK				(1)
#define INPUT_ERROR		(2)
#define OUTPUT_ERROR		(3)

/*** PRIVATE VARIABLES ********************/

static int errorFlag_ = OK;


/*** FUNCTION DEFINITIONS ****************/

/*
 * Function: getDouble
 * Purpose:  reads a double value from a file
 * Inputs:   inFile, already opened
 * Returns:  the value read
 * Modifies: file pointer, by reading from the file; sets the internal error flag
 *           upon error
 * Error Checking: checks to see if read was successful
*/
double getDouble(FILE *inFile) {
	double value = 0.0;

	if(fscanf(inFile, "%lf", &value) != 1)
		errorFlag_ = INPUT_ERROR;

	return value;	 /* it is the client's responsibility to check for error */
}

/* 
 * Function: putDouble
 * Purpose:  writes a value to the file
 * Inputs:   value: the value to be written
 *           outFile: the file to which to write; must be open
 *           width: the number of decimal places to use when writing
 * Returns:  --
 * Modifies: the file to which it writes; sets the internal error flag
 *           upon error
 * Error checking: checks to see if write was successful
 */
void putDouble(double value, FILE *outFile, int width) {
	if(fprintf(outFile, "%.*f\n", width, value) == EOF)
		errorFlag_ = OUTPUT_ERROR;
}

/*********** ERROR FUNCTIONS ***************************/

/*
 * Function: clearError
 * Purpose:  to reset the internal error state flag
 * Inputs:   --
 * Returns:  --
 * Modifies:  resets the internal error flag
 * Error checking:  --
 */
void clearError() {
	errorFlag_ = OK;
}

/*
 * Function: isError
 * Purpose:  to return the state of the internal error flag
 * Inputs:   --
 * Returns:  1 if the internal error flag is set; 0 otherwise
 * Modifies:  --
 * Error checking:  --
 */
int isError() {
	return errorFlag_ != OK;
}

/*
 * Function: printError
 * Purpose:  to print the internal error flag
 * Inputs:   --
 * Returns:  --
 * Modifies:  --
 * Error checking:  --
 */
void printError() {
	switch( errorFlag_ ){
		case INPUT_ERROR:
			fprintf(stderr, "Input Failed\n");
			return;
		case OUTPUT_ERROR:
			fprintf(stderr, "Output Failed\n");
                        return;
		case OK:
			return;
		default:
			fprintf(stderr, "Unknown Error\n");
                  return;
	      }
}
