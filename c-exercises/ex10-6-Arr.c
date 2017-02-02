#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "ex10-6-Arr.h"
                               
/*
 * File: ex10-6-Arr.c
 * Implementation file for a dynamic array module
 * The client is responsible for executing as the first call
 *   construct(void) 
 * Once this call has been made, the following operations
 *  can be performed:
 * 	Element_Arr get(int i); to get the i-th element
 *	void set(Element_Arr v, int j); to set the j-th element
 *      int length(); to get the current length of the array
 * Preconditions for all these operations are tested using assert().
 * The client is responsible for calling destruct()
 *
 * Internally, this module uses a block of memory.
 */

static Element_Arr *block_;
static int size_;
static const int increment_ = 10;  /* how much memory is added */
static int init_ = 0;	/* has been initialized */

/*
 * Function: expand_
 * Purpose: private function to expand the array
 * Inputs: size - the new size of the block
 * Returns: 1 if successful, 0 otherwise
 * Modifies: expands the array block_
 * Error checking: checks if calloc() was successful
 * Sample call: expand_(20);
 */
static int expand_(int size) {
	Element_Arr *new;
	int i;

	if((new = calloc(size, sizeof(Element_Arr))) == NULL)
		return 0;
	/* now copy the old array */
	for(i = 0; i < size_; i++)
		new[i] = block_[i];
	/* update size_ and block_ */
	size_ = size;
	free(block_);
	block_ = new;

	return 1;
}
	
/*
 * Function: construct_Arr
 * Purpose: construct the dynamic array
 * 	Does nothing if the array has already been constructed.
 * Inputs: initial size;
 * Returns 1 if successful and 0 otherwise
 */
int construct_Arr(int initSize) {
	if(init_)
		return 0;
	init_ = 1;
	size_ = initSize;
	return (block_ = calloc(initSize, sizeof(Element_Arr))) != NULL;
}

/*
 * Function: get_Arr
 * Purpose: retrieve the i-th element
 * Inputs: the index of the i-th element (parameter)
 * Returns: the value at the i-th position
 * Modifies: nothing
 * Error checking: If the index is wrong, assert() is called, and then
 * 	the result depends on whether or not NDEBUG is defined.
 * 	if it is defined, then get returns 0.
 * Sample call: Element_Arr x = get_Arr(2);
 */
Element_Arr get_Arr(int i) {
	assert(init_ && i >= 0 && i < size_);
	if(i >= 0 && i < size_ && init_)
		return block_[i];
	return 0;
}


/*
 * Function: set_Arr
 * Purpose: modify the value of the i-th element
 * Inputs: the value and the index of the i-th element (parameters)
 * Returns: the value at the i-th position
 * Modifies: i-th element
 * Error checking: If the index is negative, assert() is called, and then
 * 	the result depends on whether or not NDEBUG is defined.
 * 	if it is defined, then set does not do anything
 * If the index is positive, and larger than the current length of the array
 * then the array is extended.
 * Sample call:
 *  Element_Arr x;
 *  set_Arr(x, 2);
 */
void set_Arr(Element_Arr value, int i) {
	int res;

	assert(i >= 0 && init_);
	if(i < 0 || !init_)
		return;
	if(i >= size_)  /* expand */  {
		res = expand_(i + increment_);
		assert(res);
		if(res == 0)
			return;
	}
	block_[i] = value;
}

/*
 * Function: length_Arr
 * Purpose: return the length of the array
 * Inputs: nothing
 * Returns:  the length of the array
 * Modifies: nothing
 * Sample call:
 *  int i = length_Arr();
 */
int length_Arr() {
	if(!init_)
		return 0;
	return size_;
}

/*
 * Function: destruct_Arr
 * Purpose: destruct dynamic array
 * Error checking: does nothing if the array has not been constructed.
 */
void destruct_Arr(void) {
	if(!init_)
		return;
	init_ = 0;
	free(block_);
	size_ = 0;
}

