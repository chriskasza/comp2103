#ifndef LIST_H
#define LIST_H
/*
 * File: ex11-2-list.h
 * Header file for a number of lists of element ElType (here, string).
 * The client is responsible for constructing a list
 * Once this call has been made, the client can enumerate over the list
 * using the Enumeration interface, and additionally call functions:
 *      int length(); to get the current length of the list
 *	insert(pos, value) to insert after the i-th element (in front for i=0)
 *	delete(pos, value) to delete the i-th element and return the value 
 * The client is responsible for testing return values.
 *
 */

#include "ex11-enum.h"
#include <stdlib.h>

typedef char* DataType;
typedef struct Concrete_List *Abstract_List;

/*
 * Function: construct_List
 * Purpose: constructor for the list
 * Inputs: nothing
 * Returns a list or NULL if failed
 * Sample call:
 * if((p = construct_List)) == 0) error
 */
Abstract_List construct_List(void);

/* 
 * Function: copyData_List
 * Purpose: callback function to copy an element
 * The implementation is provided by the client
 * Inputs: v (parameter)
 * Returns: copy of v
 * Sample call:
 * v = copyData_List(v1);
 */
DataType copyData_List(const DataType v);

/* 
 * Callback function to deallocate an element
 * The implementation is provided by the client
 * Inputs: v (parameter)
 * Returns: nothing
 * Sample call:
 * freeData_List(v);
 */
void freeData_List(DataType v);

/*
 * Function: insert_List
 * Purpose: insert a new element before the i-th element (in front for i=0)
 * Inputs: List this, position i, and a double value (parameters)
 * The client can get the value for i using an enumeration
 * Returns: 1 if successful, 0 if fails
 * Modifies: list
 * Error checking: If the index is wrong, or memory allocation fails, 0 is returned 
 * Sample call:
 *  if(insert_List(p, 0, 1) == 1) ... inserted 2 in front of p 
 */
 int insert_List(Abstract_List this, int pos, DataType value);

/*
 * Function: delete_List
 * Purpose: delete the i-th element  
 * Inputs: List this, position i, and a DataType value (parameters)
 * The client can get the value for i using an enumeration
 * Returns: 1 if successful (in this case the value from the deleted element is
 *  returned through the third parameter, 0 if fails;
 * Modifies: list
 * Error checking: If the index is wrong, 0 is returned 
 * Sample call:
 *  if(delete_List(p, 1, &x) == 1) ... x has the value from what was the first element 
 */
 int delete_List(Abstract_List this, int pos, DataType *value);

/*
 * Function: length_List
 * Purpose: return the length of the list
 * Inputs: list this
 * Returns:  the length of the list
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *  int i = length_List(p);
 */
int length_List(const Abstract_List this);

/*
 * Function: destruct_List
 * Purpose: destruct the list
 * Inputs: List p
 */
void destruct_List(Abstract_List *p);

#endif
