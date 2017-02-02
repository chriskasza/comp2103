#ifndef OPS_H
#define OPS_H
/*
 * File: ex8-11-ops.h
 * Header of the module with search and sort operations
 * on a collection consisting of a number of objects of any type.
 * The client is responsible for executing as the first call
 *   construct() passing the actual number of objects
 *   the size of each element, the function to compare two objects
 * Once this call has been made, the following operations
 *  can be performed:
 * - read, to read values from a file
 * - search, to search for a given value
 * - sort, to use a built-in sorting routine to sort all values
 * All operations return 1 if successful and 0 otherwise.
 * For example, construct() has to be called first, and if it 
 * is not, all other operations will fail. Similarly,
 * destruct() has to be called before another call to
 * construct() is made.
 *
 * The implementation of a search routine can not be changed
 *   by the client, but the implementation of the sort routine
 *   can be changed by calling a function setSort().
 * By default, this module uses a built-in quick sort.
 * If the collection is sorted then a fast binary search is used.
 */

/*
 * Function: construct_Ops
 * Purpose: construct a collection to store nElements, 
 *  each of size elSize. Elements can be compared using
 *  a function compare().
 * Inputs: nElements, elSize, compare() (parameters)
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: returns 0 if wrong parameters
 */
int construct_Ops(size_t nElements, size_t elSize,
    int (*compare)(const void *, const void *));

/*
 * Function: destruct_Ops
 * Purpose: destruct a collection
 * Inputs: Nothing
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: returns 0 if the collection is not constructed
 */
int destruct_Ops(void); 

/*
 * Function: read_Ops
 * Purpose: initialize a collection, reading from a file fname.
 * 	Stops reading on EOF or error
 * Inputs: fname (parameter)
 * Returns: 1 if successful, 0 otherwise
 *           Through size (parameter) returns the number of elements read.
 * Modifies: fills in the collection with values
 * Error checking: fails if the block is not constructed
 */
int read_Ops(const char *fname, size_t* size); 

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
int search_Ops(void *value, int *result);

/*
 * Function: sort_Ops
 * Purpose: sort a collection using a default quick sort
 * 	Generic solution that uses a function compare()
 * Inputs: nothing
 * Returns: 1 if successful, 0 otherwise (e.g. a collection is not initialized)
 * Modifies: sorts the collection
 * Error checking: Returns 0 if block is not constructed
 */
int sort_Ops();

/*
 * Function: setSize_Ops
 * Purpose: set the actual size of the collection (no more than nElements)
 * Inputs: size (parameter)
 * Returns: 1 if successful, 0 otherwise (e.g. a collection is not initialized)
 * Modifies: actual size
 * Error checking: None
 */
int setSize_Ops(size_t size);

/*
 * Function: setSort_Ops
 * Purpose: set a sorting routine 
 * Inputs: sort routine (parameter)
 * Returns: 1 if successful, 0 otherwise (e.g. a collection it not initialized)
 * Modifies: changes a default sorting routine
 * Error checking: None
 */
int setSort_Ops(void (*sort)(void *base, size_t nElements, size_t elSize, 
	    int (*compare)(const void *, const void *)));
#endif

