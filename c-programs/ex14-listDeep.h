#ifndef LISTSDEEP_H
#define LISTSDEEP_H
/*
 * File: ex14-1-listDeep.h
 * Header file for generic lists
 * Extends: The "abstract" root for generic list, and the interface for
 *	deep enumerations
 * Functions declared in this header:
 *	insert_ListsDeep(list, pos, value) to insert after the i-th element (in front for i=0)
 *		using deep copying
 *	delete_ListsDeep(list, pos, value) to delete the i-th element and return the value
 * 	  	using deep copying and a user-supplied function to free data.
 *  
 */

#include "ex14-list.h" 

/* * Function: insert_ListsDeep
 * Purpose: insert a new element before the i-th element (in front for i=0)
 * Inputs: List p, position i, and a double value (parameters)
 * The client can get the value for i using an enumeration
 * Returns: 1 if successful, 0 if fails
 * Modifies: list
 * Error checking: If the index is wrong, or memory allocation fails, 0 is returned 
 * Sample call:
 *  if(insert_ListsDeep(p, 0, &"hello") == 1) ... inserted copy of "hello" in front of p 
 */
int insert_ListsDeep(Abstract_List p, int pos, void *value);

/*
 * Function: delete_ListsDeep
 * Purpose: delete the i-th element  
 * Inputs: List p, position i, and a void *value (parameters)
 * The client can get the value for i using an enumeration
 * Returns: 1 if successful (in this case the copy of the value from the deleted element is
 *  returned through the third parameter), 0 if fails;
 * The deleted data is deallocated using a user-supplied callback function
 * Modifies: list
 * Error checking: If the index is wrong, 0 is returned 
 * Sample call:
 *  if(delete_Lists(p, 1, &x) == 1) ... x has the value from what was the first element 
 */
int delete_ListsDeep(Abstract_List p, int pos, void *value);

#endif
