#ifndef X10_5CREATE_H
#define X10_5CREATE_H

/*
 * File: x10-5create.h
 * A header file for the module that currently only contains function
 *  to create a dynamic array
 * Operations: creation of a dynamic array
*/

/*
 * Function:  create
 * Purpose:   to create a dynamic array
 * Inputs:   size, arr, result
 * Returns:  --
 * Modifies:  creates memory for arr, and initializes contents to 0. 
 *				modifies result parameter: sets it to 0 if an error occurred 
 *				and 1 otherwise
 * Error checking:  checks to ensure memory allocation was successful, and that size
 *					is greater than 0
 */
void create( int size, double **arr, int *result );

#endif
