#ifndef EX10_6_ARR_H
#define EX10_6_ARR_H
/*
 * File: ex10-6-Arr.h
 * Header file for a dynamic array module.
 * The array is extended if needed (see below).
 * The client is responsible for executing as the first call
 *   construct(initial size) 
 * Once this call has been made, the following operations
 *  can be performed:
 * 	Element_Arr get(int i); to get the i-th element
 *	void set(Element_Arr v, int j); to set the j-th element
 *      int length(); to get the current length of the array
 * Preconditions for all these operations are tested using assert().
 * The client is responsible for calling destruct()
 *
 */

typedef char Element_Arr;

/*
 * Function: construct_Arr
 * Purpose: construct the dynamic array
 * 	Does nothing if the array has already been constructed.
 * Inputs: initial size;
 * Returns 1 if successful and 0 otherwise
 */
int construct_Arr(int initSize);

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
Element_Arr get_Arr(int i);

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
void set_Arr(Element_Arr value, int i);

/*
 * Function: length_Arr
 * Purpose: return the length of the array
 * Inputs: nothing
 * Returns:  the length of the array
 * Modifies: nothing
 * Sample call:
 *  int i = length_Arr();
 */
int length_Arr();

/*
 * Function: destruct_Arr
 * Purpose: destruct dynamic array
 * Error checking: does nothing if the array has not been constructed.
 */
void destruct_Arr(void);

#endif

