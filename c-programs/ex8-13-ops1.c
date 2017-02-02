/*
 * File: ex8-13-ops1.c
 * Implementation of the module with search and sort operations
 * on a collection of objects of type known to the implementation.
 * In addition, this module implements enumeration.
 * The client is responsible for executing as the first call
 *   construct() passing the actual number of elements
 *   and the function to compare two elements
 * Once this call has been made, the following operations
 *  can be performed:
 * - read, to read values from a file
 * - search, to search for a given value
 * - sort, to use a built-in shell sort routine to sort
 *   all values
 * All operations return 1 if successful and 0 otherwise.
 * For example, construct() has to be called first, and if it 
 * is not, all other operations will fail. Similarly,
 * destruct() has to be called before another call to
 * construct() is made.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ex8-13-ops1.h"
#include "ex8-enum.h"

#define SIZE	sizeof(Element_Ops1)

/***********  PRIVATE VARIABLES *******************/

static int initialized_ = 0; /* has the block been initialized */

static Element_Ops1 *base_ = NULL;	/* block of memory */
static size_t nElements_;	/* size of block */
static size_t actualSize_;	/* actual number of elements in the collection */

static void (*sort_)(Element_Ops1 *base, size_t nElements);
static int (*compare_)(const Element_Ops1 *, const Element_Ops1 *);

/************** IMPLEMENTATION OF THE INTERFACE ******/

/*
 * Sort using shell sort.
 * Assumes memory has been allocated
 * Returns: nothing
 * Modifies: block of memory
 * Error checking: none
 */
static void localSort_(Element_Ops1 *base, size_t nElements) {
     Element_Ops1 temp;   
     int gap, i, j;

     for (gap = nElements_/2; gap > 0; gap /= 2)
          for (i = gap; i < nElements_; i++)
               for (j = i-gap; j >= 0 && 
			compare_(&base_[j],&base_[j+gap])>0; j-=gap) {
                    temp = base_[j];
                    base_[j] = base_[j+gap];
                    base_[j+gap] = temp;
               }
}

/*
 * Function: construct_Ops1
 * Purpose: construct a collection to store nElements, 
 *  Elements can be compared using
 *  a function compare().
 * Inputs: nElements, elSize, compare() (parameters)
 * Returns: 1 if successful, 0 otherwise
 * Modifies: Initializes all static variables
 * Error checking: returns 0 if wrong parameters
 */
int construct_Ops1(size_t nElements, 
    int (*compare)(const Element_Ops1*, const Element_Ops1*)) {

	if(initialized_ || nElements == 0)
		return 0;
	
	/* now, allocate a block */
	if((base_ = calloc(nElements, SIZE)) == NULL)
		return 0;
	/* initialize private variables */
	nElements_ = nElements;
	compare_ = compare;

	/* set default sort */
	sort_ = localSort_;
	initialized_ = 1;
	actualSize_ = 0;    /* nothing yet */

	return 1;
}

/*
 * Function: destruct_Ops1
 * Purpose: destruct a collection
 * Inputs: Nothing
 * Returns: 1 if successful, 0 otherwise
 * Modifies:  initialized_
 * Error checking: returns 0 if the collection is not constructed
 */
int destruct_Ops1(void) {
	if(!initialized_)
		return 0;

	free(base_);
	initialized_ = 0;

	return 1;
}

/*
 * Function: read_Ops1
 * Purpose: initialize a collection, reading from a file fname.
 * 	Stops reading on EOF or error
 * Inputs: fname (parameter)
 * Returns: 1 if successful, 0 otherwise
 *           Through size (parameter) returns the number of elements read.
 * Modifies: fills in the collection with values. Also modifies isSorted_
 *    and actualSize_
 * Error checking: fails if the block is not constructed
 */
int read_Ops1(const char *fname, size_t* size) {
	FILE *in;

	if(!initialized_ || (in = fopen(fname, "r")) == NULL)
		return 0;

	/* reading */
	actualSize_ = *size = fread(base_, SIZE, nElements_, in);

	if(fclose(in) == EOF)
		return 0;
	 
	return 1;
} 

/*
 * Function: search_Ops1
 * Purpose: search a collection looking for a given value
 * 	Generic solution that uses a function compare()
 * Inputs: value
 * Returns: 1 if successful, 0 otherwise (e.g. a collection it not initialized)
 * Modifies: nothing
 *    Through result (parameter) returns 1 if value found, 0 otherwise
 * Error checking: Returns 0 if block is not constructed
 */
int search_Ops1(const Element_Ops1 *value, int *result) {
	Element_Ops1 *p;

	if(!initialized_)
		return 0;

	*result = 0;
	for(p = base_; p < base_ + actualSize_; p++)
		if(compare_(value, p) == 0)
			*result = 1;
	
	return 1;
}

/*
 * Function: sort_Ops1
 * Purpose: sort a collection using shell sort
 * 	Generic solution that uses a function compare()
 * Inputs: nothing
 * Returns: 1 if successful, 0 otherwise (e.g. a collection is not initialized)
 * Modifies: sorts the collection, sets isSorted_
 * Error checking: Returns 0 if block is not constructed
 */
int sort_Ops1() {
	if(!initialized_)
		return 0;
	sort_(base_, actualSize_);

	return 1;
}

/*
 * Function: setSort_Ops1
 * Purpose: set a sorting routine 
 * Inputs: sort routine (parameter)
 * Returns: new size if successful, 0 otherwise (e.g. a collection it not initialized)
 * Modifies: changes a default sorting routine
 * Error checking: None
 */

int setSort_Ops1(void (*sort)(Element_Ops1 *base, size_t nElements)) {
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

int setSize_Ops1(size_t size) {
	if(!initialized_)
		return 0;

	actualSize_ = size > nElements_ ? nElements_ : size;
	return actualSize_;
}

/************* implementation of enumeration **************/

static  int current_;

/*
 * Function: hasMoreElements_Enum
 * Purpose: check if there is another element
 * Inputs: nothing
 * Returns: 1 if there is another element, 0 otherwise
 * Modifies: nothing  
 * Error checking: none
 */
int hasMoreElements_Enum() {
	if(!initialized_)
		return 0;
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
void *nextElement_Enum() {
	int q = current_;
	if(!initialized_)
		return 0;
	if(current_ >= actualSize_)
		return NULL;
	current_++;
	return base_ + q;
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
	if(!initialized_)
		return; 
	current_ = 0;
}

