#ifndef X8_3MEM_H
#define X8_3MEM_H

/*
 * File: x8-3mem.h
 * A header file for the module to provide simple memory operations
 * Operations: allocation of a block of memory
 *		reading of doubles and storing them in the block of memory
 *		showing the contents of the block
 *		find the maximum value in the block
 */

/*
 * Function:  myAlloc
 * Purpose:  to allocate a block of memory size elements big
 * Inputs:   the integer n specifying the size of the block to be allocated
 * Returns:  a pointer to the newly allocated block, NULL upon error
 * Modifies:  --
 * Error checking:  checks the result of the memory request
 */
double *myAlloc(int n);

/*
 * Function:  get
 * Purpose:   reads double values from the standard input and stores size
 *				double values in the block of memory passed as an argument
 * Inputs:  the block of memory and size (this specifies number of 
 *				values to store )
 * Returns:  the number of values read
 * Modifies:  the incoming block's contents are set to the values read
 * Error checking: checks the result of each read, and stops reading 
 *				either when an error occurs, or when size elements have been
 *				read
 */
int get(double *block, int size);

/*
 * Function: show
 * Purpose:  shows the contents of the incoming block
 * Inputs:  the block pointer, and the size of the block
 * Returns:  --
 * Modifies: --
 * Error checking: --
 */
void show(double *block, int size);

/*
 * Function:  max
 * Purpose:  to find the maximum value stored in the block
 * Inputs:   the block of size 'size'
 * Returns:  the maximum value in the block
 * Modifies: --
 * Error checking:  --
 */
double max(double *block, int size);


#endif

