/*
 * File: x8-9com.c
 * The implementation file for the module to perform a lexicographical comparison of
 *  two blocks using the provided call back function
 *
 * Operations: comparison function for two blocks of memory is provided
*/

#include <stdlib.h>
#include <stdio.h>
#include "x8-9com.h"


/*
 * Function:  compareGen
 * Purpose:   to perform a lexicographical comparison of 
 *          two blocks using the provided call back function
 * Assume: the call back function must return 0 if two elements are equal,
 *				1 if the first is larger, and -1 otherwise.
 * Inputs:   [elemSize] size of elements in both blocks
 *           [block1] the first block, containing size1 elements
 *           [block2] the second block, containing size2 elements
 *           [compareIt] user provided function
 * Returns:  if both blocks are of the same size: 0 if equal. 1 if first is bigger
 *             and -1 if first block is smaller
 *           if blocks are not the same size: 1 if block 1 is smaller; -1 otherwise
 * Modifies:  --
 * Error checking:  --
 */
int compareGen(size_t elemSize, const void *block1, int size1,
		const void *block2, int size2,
		int (*compareIt)(const void *, const void *) ){
	int i;
	int res;
	int stop;

	if(size1 <= 0 || size2 <= 0)
		return 0; /* the caller is responsible for passing correct size args */

	stop = size1 <= size2 ? size1 : size2; /* set stop to smaller of two blocks */

	for(i = 0; i < stop; i++ ) {
		if((res = compareIt( (void*)((char *)block1 + elemSize * i),  
					(void*)((char *)block2 + elemSize * i))) != 0)
			break; /* not equal, break */
	}

	if(i == stop) { /* went all the way to the end of one (or both) of the blocks */

		if(size1 == size2)
			return 0;

		if( size1 == stop) /* size1 is smaller than size2 */
			return 1;

		return -1;
	}
	 
	return res;
}

