/*
 * File: x10-5.c
 * The implementation file for the module that currently only contains function
 *  to create a dynamic array
 * Operations: creation of a dynamic array
*/


#include <stdio.h>
#include <stdlib.h>
#include "x10-5create.h"

/*
 * Function:  create
 * Purpose:   to create a dynamic array
 * Inputs:   size, arr, result
 * Returns:  --
 * Modifies:  creates memory for arr, and initializes contents to 0. 
 *          modifies result parameter: sets it to 0 if an error occurred 
 *				and 1 otherwise
 * Error checking:  checks to ensure memory allocation was successful and size > 0
 */
void create( int size, double **arr, int *result ){

	if( size <= 0 ) {
		*result = 0;
		return;
	}
	*result = (*arr = (double *)calloc(size, sizeof(double))) != NULL;
	
	return;
}

