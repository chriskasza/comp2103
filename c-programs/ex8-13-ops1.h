#ifndef OPS1_H
#define OPS1_H

/*
 * File: ex8-13-ops1.h
 * Header of the module with search and sort operations
 * on a number of values of any type.
 * The client is responsible for executing as the first call
 *   construct() passing the actual number of elements,
 *   the size of each element, the function to compare two elements
 * Once this call has been made, the following operations
 *  can be performed:
 * - read, to read values from a file
 * - search, to search for a given value
 * - sort, to use a built-in shell sorting routine to sort
 *   all values
 * - write, to write all values to a file.
 * All operations return 1 if successful and 0 otherwise.
 * For example, construct() has to be called first, and if it 
 * is not, all other operations will fail. Similarly,
 * destruct() has to be called before another call to
 * construct() is made.
 *
 * The implementation of a search routine can not be changed
 *   by the client, but the implementation of the sort routine
 *   can be changed by calling a function setSort().
 * By default, this module uses a buil-in quick sort.
 * If the block is sorted then a fast binary search is used.
 */

typedef double Element_Ops1;

/*
 * Function: construct_Ops1
 * Purpose: construct a collection to store nElements, 
 *  Elements can be compared using
 *  a function compare().
 * Inputs: nElements, elSize, compare() (parameters)
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: returns 0 if wrong parameters
 */
int construct_Ops1(size_t nElements, 
    int (*compare)(const Element_Ops1*, const Element_Ops1 *)
   );

/*
 * Function: destruct_Ops1
 * Purpose: destruct a collection
 * Inputs: Nothing
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: returns 0 if the collection is not constructed
 */
int destruct_Ops1(void); 

/*
 * Function: read_Ops1
 * Purpose: initialize a collection, reading from a file fname.
 * 	Stops reading on EOF or error
 * Inputs: fname (parameter)
 * Returns: 1 if successful, 0 otherwise
 *           Through size (parameter) returns the number of elements read.
 * Modifies: fills in the collection with values
 * Error checking: fails if the block is not constructed
 */
int read_Ops1(const char *fname, size_t* size); 

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
int search_Ops1(const Element_Ops1 *value, int *result);

/*
 * Function: sort_Ops1
 * Purpose: sort a collection using shell sort
 * 	Generic solution that uses a function compare()
 * Inputs: nothing
 * Returns: 1 if successful, 0 otherwise (e.g. a collection is not initialized)
 * Modifies: sorts the collection
 * Error checking: Returns 0 if block is not constructed
 */
int sort_Ops1();

/*
 * Function: setSort_Ops1
 * Purpose: set a sorting routine 
 * Inputs: sort routine (parameter)
 * Returns: 1 if successful, 0 otherwise (e.g. a collection it not initialized)
 * Modifies: changes a default sorting routine
 * Error checking: None
 */
int setSort_Ops1(void (*sort)(Element_Ops1 *base, size_t nElements));

/*
 * Function: setSize_Ops1
 * Purpose: set the actual size of the collection (no more than nElements)
 * Inputs: size (parameter)
 * Returns: new size if successful, 0 otherwise (e.g. a collection is not initialized)
 * Modifies: actual size
 * Error checking: None
 */
int setSize_Ops1(size_t size);
#endif
