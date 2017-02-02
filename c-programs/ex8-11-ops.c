/*
 * File: ex8-11-ops.c
 * Implementation of the module with search and sort operations
 * on a number of values of any type.
 * In addition, this module implements enumeration.
 * The client is responsible for executing as the first call
 *   construct() passing the actual number of elements,
 *   the size of each element and the function to compare two elements
 *   
 * Once this call has been made, the following operations
 *  can be performed:
 * - read, to read values from a file
 * - search, to search for a given value
 * - sort, to use a built-in sorting routine to sort
 *   all values
 * All operations return 1 if successful and 0 otherwise.
 * For example, construct() has to be called first, and if it 
 * is not, all other operations will fail. Similarly,
 * destruct() has to be called before another call to
 * construct() is made.
 *
 * The implementation of a search routine can not be changed
 *   by the client, but the implementation of the sort routine
 *   can be changed by calling a function setSort().
 * By default, this module uses a buil-in quick sort from stdlib.h.
 * The implementation remembers if the block has been sorted and if so
 *  uses a binary search from stdlib.h
 */

#include <stdio.h>
#include <stdlib.h>
#include "ex8-11-ops.h"
#include "ex8-enum.h"

/***********  PRIVATE VARIABLES *******************/

static int initialized_ = 0; /* has the block been initialized */
static int isSorted_ = 0;   /* has the block been sorted */

static void *base_ = NULL;	/* block of memory */
static size_t nElements_;	/* size of block */
static size_t elSize_;		/* size of each element */
static size_t actualSize_;	/* actual number of elements in the collection */

static void (*sort_)(void *base, size_t nElements, size_t elSize, 
	    int (*compare)( const void *, const void *));
static int (*compare_)(const void *, const void *); 

/************** IMPLEMENTATION OF THE INTERFACE ******/


#define VOID(targ,size) ((void *)(((char *)(targ)) + (size)))

/*
 * Function: construct_Ops
 * Purpose: construct a collection to store nElements, 
 *  each of size elSize. Elements can be compared using
 *  a function compare().
 * Inputs: nElements, elSize, compare() (parameters)
 * Returns: 1 if successful, 0 otherwise
 * Modifies: all local static variables
 * Error checking: returns 0 if wrong parameters
 */
int construct_Ops(size_t nElements, size_t elSize,
    int (*compare)(const void *, const void *)) {

	if(initialized_)
		return 0;
	if(nElements == 0 || elSize == 0 || compare == NULL)
		return 0;
	/* now, allocate a block */
	if((base_ = calloc(nElements, elSize)) == NULL)
		return 0;
	/* initialize private variables */
	nElements_ = nElements;
	elSize_ = elSize;
	compare_ = compare;
	/* set default sort */
	sort_ = qsort;
	initialized_ = 1;
	actualSize_ = 0;    /* nothing yet */

	return 1;
}

/*
 * Function: destruct_Ops
 * Purpose: destruct a collection
 * Inputs: Nothing
 * Returns: 1 if successful, 0 otherwise
 * Modifies: base_ and initialized_
 * Error checking: returns 0 if the collection is not constructed
 */
int destruct_Ops(void) {
	if(!initialized_)
		return 0;

	free(base_);
	initialized_ = 0;

	return 1;
}

/*
 * Function: read_Ops
 * Purpose: initialize a collection, reading from a file fname.
 * 	Stops reading on EOF or error
 * Inputs: fname (parameter)
 * Returns: 1 if successful, 0 otherwise
 *           Through size (parameter) returns the number of elements read.
 * Modifies: fills in the block with values. Also modifies isSorted_
 *    and actualSize_
 * Error checking: fails if the block is not constructed
 */
int read_Ops(const char *fname, size_t* size) {
	FILE *in;

	if(!initialized_ || (in = fopen(fname, "r")) == NULL)
		return 0;
	
	/* reading */
	actualSize_ = *size = fread(base_, elSize_, nElements_, in);

	if(fclose(in) == EOF)
		return 0;
	isSorted_ = 0;

	return 1;
}

/*
 * Function: search_Ops
 * Purpose: search a collection looking for a given value
 * 	Generic solution that uses a function compare()
 * Inputs: value
 * Returns: 1 if successful, 0 otherwise (e.g. a collection it not initialized)
 * Modifies: nothing
 *    Through result (parameter) returns 1 if value found, 0 otherwise
 * Error checking: Returns 0 if block is not constructed
 */
int search_Ops(void *value, int *result) {
	if(!initialized_)
		return 0;
	if(isSorted_) /* binary search */
		*result = bsearch(value, base_, actualSize_, elSize_, compare_) != NULL;
	else {	/* linear search */
		void *p;
		*result = 0;

		for(p = base_; p < VOID(base_, actualSize_*elSize_); p = VOID(p ,elSize_))
			if(compare_(value, p) == 0)
				*result = 1;
	}

	return 1;
}

/*
 * Function: sort_Ops
 * Purpose: sort a collection using a default quick sort
 * 	Generic solution that uses a function compare()
 * Inputs: nothing
 * Returns: 1 if successful, 0 otherwise (e.g. a block it not initialized)
 * Modifies: sorts the block, modifies isSorted_
 * Error checking: Returns 0 if block is NULL
 */
int sort_Ops() {
	if(!initialized_)
		return 0;
	sort_(base_, actualSize_, elSize_, compare_);
	isSorted_ = 1;

	return 1;
}

/*
 * Function: setSort_Ops
 * Purpose: set a sorting routine 
 * Inputs: sort routine (parameter)
 * Returns: 1 if successful, 0 otherwise (e.g. a collection it not initialized)
 * Modifies: changes a default sorting routine
 * Error checking: None
 */
int setSort_Ops(void (*sort)(void *base, size_t nElements, size_t elSize, 
	    int (*compare)(const void *, const void *))) {
	if(!initialized_)
		return 0;
	sort_ = sort;

	return 1;
}

/*
 * Function: setSize_Ops
 * Purpose: set the actual size of the collection (no more than nElements)
 * Inputs: size (parameter)
 * Returns: 1 if successful, 0 otherwise (e.g. a collection is not initialized)
 * Modifies: actual size
 * Error checking: None
 */
int setSize_Ops(size_t size) {
	if(!initialized_)
		return 0;

	actualSize_ = size > nElements_ ? nElements_ : size;
	return 1;
}

/************* implementation of enumeration **************/

static int current_;  /* current "pointer" */

/*
 * Function: hasMoreElements_Enum
 * Purpose: check if there is another element
 * Inputs: nothing
 * Returns: 1 if there is another element, 0 otherwise
 * Modifies: nothing  
 * Error checking: none
 */
int hasMoreElements_Enum() {
  return current_ < actualSize_;
}

/*
 * Function: nextElement_Enum
 * Purpose: get another element
 * Inputs: nothing
 * Returns: void* pointer to the next element, 
 *  or NULL if there is another element
 * Modifies: assumes the collection is not sorted any more and sets isSorted_
 *    also modifies the internal state of the enumeration
 * Error checking: none
 */
void* nextElement_Enum() {
	int i = current_;
	if(current_ >= actualSize_)
		return NULL;

	current_++;
	isSorted_ = 0;

	return VOID(base_, i*elSize_);
}

/*
 * Function: reset_Enum
 * Purpose: reset the enumeration
 * Inputs: nothing
 * Returns: nothing
 * Modifies: nothing (except the internal state of the enumeration)
 * Error checking: none
 */
void reset_Enum() {
	current_ = 0;
}

