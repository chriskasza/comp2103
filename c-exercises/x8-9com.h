#ifndef X8_9COM_H
#define X8_9COM_H

/*
 * File: x8-9com.h
 * A header file for the module to perform a lexicographical comparison of
 *	 two blocks using the provided callback function
 *
 * Operations: comparison of two blocks
 * 
*/


/*
 * Function:  compareGen
 * Purpose:   to perform a lexicographical comparison of 
 *				two blocks using the provided call back function
 *
 * Assume: the call back function must return 0 if two elements are equal,
 *          1 if the first is smaller, and -1 otherwise.
 * Inputs:   [elemSize] size of elements in both blocks
 *				 [block1] the first block, containing size1 elements
 *				 [block2] the second block, containing size2 elements
 *				 [compareIt] user provided function
 * Returns:  if both blocks are of the same size: 0 if equal. 1 if first is bigger
 *					and -1 if first block is smaller
 *				 if blocks are not the same size: 1 if block 1 is smaller; -1 otherwise
 * Modifies:  --
 * Error checking:  --
 * Assumes that the caller passes correct size 
 *
 * Spec for user provided function:
 *			the user must provide a function that compares two elements in the block.
 *			This function must return:
 *				0 if two elements are equal
 *				1 if the first element is bigger than the second
 *				-1 otherwise
 */
int compareGen(size_t elemSize, const void *block1, int size1,
      const void *block2, int size2, int (*compareIt)(const void *, const void *) );

#endif

