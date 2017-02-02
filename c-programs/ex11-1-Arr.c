#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "ex11-1-Arr.h"

/*
 * File: ex11-1-Arr.c
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


#define VOID(targ,size) ((void *)(((char *)(targ)) + (size)))
/* typedef struct Concrete_Arr *Abstract_Arr;  */

static const int increment_ = 10;  /* how much memory is added */

struct Concrete_Arr {
	void *block_;
	int size_;	/* current size of the array */
	size_t elSize_; /* size of each element */
	int init_;	/* has been initialized */
};

/*
 * Function: expand_
 * Purpose: private function to expand the array
 * Inputs: Abstract_arr, size - the new size of the block
 * Returns: 1 if successful, 0 otherwise
 * Modifies: expands the array block_
 * Error checking: checks if calloc() was successful
 *** If the user was enumerating then the expansion will not affect it
 */
 static int expand_(Abstract_Arr this, int size) {
 	void *new;
 
 	if((new = calloc(size, this->elSize_)) == NULL)
 		return 0;
 
 	/* now copy the old array */
 	memcpy(new, this->block_, this->size_);
 	/* update size_ and block_ */
 	this->size_ = size;
 	free(this->block_);
 	this->block_ = new;
 
 	return 1;
 }
	
/*
 * Function: construct_Arr
 * Purpose: construct dynamic array
 * Does nothing if the array has already been constructed.
 * Inputs: initial size and size of each element;
 * Returns an abstract array or NULL if failed
 * Sample call:
 * if(construct_Arr(sizeof(double), 10) == 1) ...
 */
 Abstract_Arr construct_Arr(size_t elSize, int initSize) {
 	Abstract_Arr arr;
 
 	if((arr = malloc(sizeof(struct Concrete_Arr))) == NULL)
 		return NULL;
 	arr->init_ = 1;
 	arr->elSize_ = elSize;
 	if((arr->block_ = calloc(initSize, elSize)) == NULL) {
 		free(arr);
 		return NULL;
 	}
	arr->size_ = initSize; 
 	return arr;
 }

/*
 * Function: get_Arr
 * Purpose: return the i-th element
 * Inputs: Abstract_Arr this and the index of the i-th element (parameters)
 * Returns: the value at the i-th position
 * Modifies: nothing
 * Error checking: If the index is wrong, assert() is called, and then
 * 	the result depends on whether or not NDEBUG is defined.
 * 	if it is defined, then get returns 0.
 * Sample call:
 *  void *x = get_Arr(arr, 2);
 */
void* get_Arr(Abstract_Arr this, int i) {
	assert(this && this->init_ && i >= 0 && i < this->size_);
	if(this->init_ && i >= 0 && i < this->size_)
		return VOID(this->block_, i*this->elSize_);
	return NULL;
}

/*
 * Function: set_Arr
 * Purpose: set the value of the i-th element
 * Inputs: Abstract_Arr this, the value and the index of the i-th element (parameters)
 * Returns: nothing
 * Modifies: i-th element
 * Error checking: If the index is negative, assert() is called, and then
 * 	the result depends on whether or not NDEBUG is defined.
 * 	if it is defined, then set does not do anything
 * If the index is positive, and larger than the current length of the array
 * then the array is extended.
 * set() should not be called while the array is enumerated.
 * Sample call:
 *  double x;
 *  set_Arr(arr, &x, 2);
 */
 void set_Arr(Abstract_Arr this, void *value, int i) {
 	int res;
 
 	assert(this && i >= 0 && this->init_);
 	if(i < 0 || !this->init_)
 		return;
 
 	if(i >= this->size_) { /* expand */
 		res = expand_(this, i + increment_);
 		assert(res);
 		if(res == 0)
 			return;
 	}
 	memcpy(VOID(this->block_, i*this->elSize_), value, this->elSize_);
 }

/*
 * Function: length_Arr
 * Purpose: return the length of the array
 * Inputs: Abstract_Arr this
 * Returns:  the length of the array
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *  int i = length_Arr(this);
 */
int length_Arr(const Abstract_Arr this) {
	if(!this->init_)
		return 0;
	return this->size_;
}

/*
 * Function: destruct_Arr
 * Purpose: destruct the dynamic array
 * Does nothing if the array has not been constructed.
 * Inputs: Abstract_Arr this
 */
void destruct_Arr(Abstract_Arr *this) {
	if(*this == NULL || !(*this)->init_)
		return;
	free((*this)->block_);
	free(*this);
	*this = NULL;
}

/***************** Implementation of Enumeration *****************/

struct Concrete_Enumeration {
	int pos;
	Abstract_Arr arr;
}; 


/*
 * Function: hasMoreElements_Enumeration
 * Purpose: check if there is another element
 * Inputs: an abstract enumeration
 * Returns: 1 if there is another element, 0 otherwise
 * Modifies: nothing  
 * Error checking: none
 * 
 */
int hasMoreElements_Enumeration(Abstract_Enumeration e) {
	assert(e->arr->init_);
	return e->pos < e->arr->size_;	
}

/*
 * Function: nextElement_Enumeration
 * Purpose: get another element
 * Inputs: an abstract enumeration
 * Returns: void* pointer to the next element, 
 *  or NULL if there is no other element
 * Modifies: nothing (except the internal state of the enumeration)
 * Error checking: none
 * 
 */
void* nextElement_Enumeration(Abstract_Enumeration e) {
	void *aux;

	assert(e->arr->init_);
	if(e->pos == e->arr->size_)
		return NULL;
	aux = VOID(e->arr->block_, e->pos*e->arr->elSize_);
	e->pos++;
	return aux;
}

/*
 * Function: construct_Enumeration
 * Purpose: return a new enumeration
 * Inputs: nothing
 * Returns: a new abstract enumeration
 * Modifies: nothing (except the internal state of the enumeration)
 * The client is responsible for deallocating this enumeration
 * Error checking: none
 * 
 */
Abstract_Enumeration construct_Enumeration(void *p) {
	Abstract_Enumeration e;	

	if((e = calloc(1, sizeof(struct Concrete_Enumeration))) == NULL)
		return NULL;
	e->arr = (Abstract_Arr)p;
	e->pos = 0;
	return e;
}

