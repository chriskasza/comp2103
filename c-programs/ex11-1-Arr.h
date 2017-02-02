#ifndef ARRAY_H
#define ARRAY_H
/*
 * File: ex11-1-Arr.h
 * Header file for a dynamic array module.
 * The array is extended if needed (see below).
 * The client is responsible for executing as the first call
 *   construct(element size, initial size) 
 * to pass the size of each element of this array, and the initial size.
 * Once this call has been made, the client can enumerate over the array
 * using the Enumeration interface, and additionally:
 *      int length(); to get the current length of the array
 * Preconditions for all these operations are tested using assert().
 * The client is responsible for calling destruct()
 *
 */
#include "ex11-enum.h"

typedef struct Concrete_Arr *Abstract_Arr;  /* opaque idiom */

/*
 * Function: construct_Arr
 * Purpose: construct dynamic array
 * Does nothing if the array has already been constructed.
 * Inputs: initial size and size of each element;
 * Returns an abstract array or NULL if failed
 * Sample call:
 * if(construct_Arr(sizeof(double), 10) == 1) ...
 */
Abstract_Arr construct_Arr(size_t elSize, int initSize);

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
 void *get_Arr(const Abstract_Arr this, int i);

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
 void set_Arr(Abstract_Arr this, void *value, int i);

/*
 * Function: length_Arr
 * Purpose: return the length of the array
 * Inputs: Abstract_Arr this
 * Returns:  the length of the array
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *  int i = length_Arr(arr);
 */
 int length_Arr(const Abstract_Arr this);

/*
 * Function: destruct_Arr
 * Purpose: destruct the dynamic array
 * Does nothing if the array has not been constructed.
 * Inputs: Abstract_Arr this
 * Modifies: this array
 */
 void destruct_Arr(Abstract_Arr *this);

#endif

