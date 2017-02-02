#ifndef LISTSSHALLOW_H
#define LISTSSHALLOW_H
/*
 * File: ex14-1-listShallow.h
 * Header file for generic lists with support for shallow copy
 * The client is responsible for constructing a list
 * Once this call has been made, the client can enumerate over the list
 * using the Enumeration interface, and additionally call functions:
 *      int length(); to get the current length of the list
 *	insert(pos, value) to insert after the i-th element (in front for i=0)
 *	delete(pos, value) to delete the i-th element and return the value 
 * The client is responsible for testing return values.
 *
 */

#include "ex14-list.h"

/*
 * Function: insert_ListsShallow
 * Purpose: insert a new element before the i-th element (in front for i=0)
 * Inputs: List this, position i, and a void* value (parameters)
 * The client can get the value for i using an enumeration
 * Returns: 1 if successful, 0 if fails
 * Modifies: list
 * Error checking: If the index is wrong, or memory allocation fails, 0 is returned 
 * Sample call:
 *  if(insert_Lists(p, 0, &"hello") == 1)
 *            ... inserted pointer to "hello" in front of p 
 */
int insert_ListsShallow(Abstract_List this, int pos, void *value);

/*
 * Function: delete_ListsShallow
 * Purpose: delete the i-th element  
 * Inputs: List this, position i, and a void *value (parameters)
 * The client can get the value for i using an enumeration
 * Returns: 1 if successful (in this case the value from the deleted element is
 *  returned through the third parameter, 0 if fails;
 * Modifies: list
 * Error checking: If the index is wrong, 0 is returned 
 * Sample call:
 *  if(delete_Lists(p, 1, &x) == 1)
 *  ... x has the value from what was the first element 
 */
int delete_ListsShallow(Abstract_List this, int pos, void *value);

#endif

