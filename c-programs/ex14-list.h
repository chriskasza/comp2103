#ifndef LISTS_H
#define LISTS_H
/*
 * File: ex14-list.h
 * Root header file for generic lists; the client uses its "descendants"
 * The client is responsible for constructing a list
 * Once this call has been made, the client can enumerate over the list
 * using the Enumeration interface, and additionally call functions:
 *      int length_Lists(); to get the current length of the list
 * The client is responsible for destructing the list.
 *
 */

typedef struct Concrete_List *Abstract_List;

/*
 * Function: construct_Lists
 * Purpose: constructor for the list
 * Inputs: elSize (size of each element; and two callback functions (parameters)
 * Returns a list or NULL if failed
 * Sample call:
 * if((p = construct_Lists(sizeof(char*), copyD, freeD)) == NULL) error
 */
Abstract_List construct_Lists(size_t elSize, void* (*copyData)(const void*),
	void (*freeData)(void*) );

/*
 * Function: length_Lists
 * Purpose: find the length of the list
 * Inputs: list
 * Returns:  the length of the list
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *  int i = length_List(p);
 */
int length_Lists(const Abstract_List this);

/*
 * Function: destruct_Lists
 * Purpose: destruct the list
 * Inputs: List p
 */
void destruct_Lists(Abstract_List *this);

#endif

