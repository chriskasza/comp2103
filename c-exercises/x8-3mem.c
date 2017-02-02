/*
 * File: x8-3mem.c
 * The implementation file for the module to provide simple memory operations
 * Operations: allocation of a block of memory
 *        reading of doubles and storing them in the block of memory
 *        showing the contents of the block
 *        find the maximum value in the block
*/

#include <stdio.h>
#include <stdlib.h>
#include "x8-3mem.h"


/*
 * Function:  myAlloc
 * Purpose:  to allocate a block of memory size elements big
 * Inputs:   the integer n specifying the size of the block to be allocated
 * Returns:  a pointer to the newly allocated block, NULL upon error
 * Modifies:  --
 * Error checking:  checks the result of the memory request
 */
double *myAlloc(int n) {

	if(n <= 0) /* error */
		 return NULL;

	return calloc(n , sizeof(double)); /* if calloc failed then return NULL */
}

/*
 * Function:  get
 * Purpose:   reads double values from the standard input and stores size
 *          double values in the block of memory passed as an argument
 * Inputs:  the block of memory and size (this specifies number of 
 *          values to store )
 * Returns:  the number of values read
 * Modifies:  the incoming block's contents are set to the values read
 * Error checking: checks the result of each read, and stops reading 
 *          either when an error occurs, or when size elements have been
 *          read
 */
int get(double * block, int size) {
	double val;
	int n = 0;

	if(size <= 0) /* error */
		return 0;

	/* read in the values */
	while(1) {
	
		printf("Enter the %d value > ", n + 1);

		if(scanf("%lf", &val ) != 1) /* read error, break */
			break;

		block[n++] = val;

		if(n >= size) 
			break;
	}

	/* skip any remaining characters */
	while( getchar() != '\n')
		;

	return n; /* return num values read */
}

/*
 * Function: show
 * Purpose:  shows the contents of the incoming block
 * Inputs:  the block pointer, and the size of the block
 * Returns:  --
 * Modifies: --
 * Error checking: --
 */
void show(double *block, int size) {
	int i;

	for(i = 0; i < size; i++)
		printf("%f\n", block[i] );
	
}

/*
 * Function:  max
 * Purpose:  to find the maximum value stored in the block
 * Inputs:   the block of size 'size'
 * Returns:  the maximum value in the block
 * Modifies: --
 * Error checking:  --
 */
double max(double *block, int size) {
	int i;
	double max;

	if(size == 0) /* empty block */
		return 0.0;

	max = block[0];
	for(i = 1; i < size; i++)
		if(block[i] > max)
			max = block[i];
	return max;
}
