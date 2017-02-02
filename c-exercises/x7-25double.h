#ifndef X7_25DOUBLE_H
#define X7_25DOUBLE_H

/*
 * File: x7-25double.h
 * A header file for the module to read and write double values to a file
 *				module maintains internal error state; it is the user's 
 *				responsibility to check for error / clear error after every
 *				read / write operation
 *
 * Operations: reads a double value from a file
 *					writes a double value to a file
 * 				checks for error, clear error and print error functions
 *
 * Sample call:
 *
 *			double x = getDouble();
 *			if(isError()) {
 *				printError();
 *				clearError();
 *				exit(1);
 *			}
 *
 * Possible error states include: OK, INPUT_ERROR, OUTPUT_ERROR
*/


/* 
 * Function: getDouble
 * Purpose:  reads a double value from a file
 * Inputs:   inFile, already opened
 * Returns:  the value read
 * Modifies: file pointer, by reading from the file; sets the internal error flag
 *    		 upon error
 * Error Checking: checks to see if read was successful
*/
double getDouble(FILE *inFile);

/*
 * Function: putDouble
 * Purpose:  writes a value to the file
 * Inputs:   value: the value to be written
 *				 outFile: the file to which to write; must be open
 *				 width: the number of decimal places to use when writing
 * Returns:  --
 * Modifies: the file to which it writes; sets the internal error flag
 *    		 upon error
 * Error checking: checks to see if write was successful
 */
void putDouble(double value, FILE *outFile, int width);

/*********** ERROR FUNCTIONS ***************************/

/*
 * Function: clearError
 * Purpose:  to reset the internal error state flag
 * Inputs:   --
 * Returns:  --
 * Modifies:  resets the internal error flag
 * Error checking:  --
 */
void clearError();

/*
 * Function: isError
 * Purpose:  to return the state of the internal error flag
 * Inputs:   --
 * Returns:  1 if the internal error flag is set; 0 otherwise
 * Modifies:  --
 * Error checking:  --
 */
int isError();

/*
 * Function: printError
 * Purpose:  to print the internal error flag
 * Inputs:   --
 * Returns:  --
 * Modifies:  --
 * Error checking:  --
 */
void printError();

#endif

