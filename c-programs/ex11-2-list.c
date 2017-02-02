/*
 * File: ex11-2-list.c
 * Implementation file for a number of lists of data of type DataType (here, strings).
 * The client is responsible for constructing a list
 * Once this call has been made, the client can enumerate over the list
 * using the Enumeration interface, and additionally call functions:
 *      int length(); to get the current length of the list
 *	insert(pos, value) to insert after the i-th element (in front for i=0)
 *	delete(pos, value)
 * The client is responsible for testing return values.
 *
 */

#include "ex11-enum.h"
#include <stdlib.h>
#include <stdio.h>
#include "ex11-2-list.h"

typedef struct elem {
	DataType value;
	struct elem *next;
} ElemT, *ElemTP;

struct Concrete_List {
	ElemTP first;
};

/*
 * Function: construct_List
 * Purpose: constructor for the list
 * Inputs: nothing
 * Returns a list or NULL if failed
 * Sample call:
 * if((p = construct_List)) == 0) error
 */
Abstract_List construct_List(void) {
	Abstract_List p;

	if((p = malloc(sizeof(struct Concrete_List))) == NULL)
		return NULL;
	p-> first = NULL;
	return p;
}

/*
 * Function: insert_List
 * Purpose: insert a new element before the i-th element (in front for i=0)
 * Inputs: List p, position i, and a double value (parameters)
 * The client can get the value for i using an enumeration
 * Returns: 1 if successful, 0 if fails
 * Modifies: list
 * Error checking: If the index is wrong, or memory allocation fails, 0 is returned 
 * Sample call:
 *  if(insert_List(p, 0, 1) == 1) ... inserted 2 in front of p 
 */
int insert_List(Abstract_List this, int pos, DataType value) {
	int i;
	ElemTP auxp, auxm;
	int length = length_List(this);
	
	if(pos < 0 || pos > length)
		return 0;
	if(pos == 0) /* in front */ {
		if((auxm = malloc(sizeof(ElemT))) == NULL)
			return 0;
		auxm->value = copyData_List(value);
		auxm->next = this->first; /* connect with old list*/
 		this->first = auxm;

		return 1;
	}
	if(this->first == NULL) /* empty list */
		return 0;

	/* search */
	for(i = 1, auxp = this->first; i < pos; i++, auxp = auxp->next)
		;
	/* insert after auxp */
	if((auxm = malloc(sizeof(ElemT))) == NULL)
		return 0;
	auxm->value = copyData_List(value);
	auxm->next = auxp->next; /* connect with old list*/
	auxp->next = auxm;

	return 1;
}
	
/*
 * Function: delete_List
 * Purpose: delete the i-th element  
 * Inputs: List p, position i, and a DataType value (parameters)
 * The client can get the value for i using an enumeration
 * Returns: 1 if successful (in this case the value from the deleted element is
 *  returned through the third parameter, 0 if fails;
 * Modifies: list
 * Error checking: If the index is wrong, 0 is returned 
 * Sample call:
 *  if(delete_List(p, 1, &x) == 1) ... x has the value from what was the first element 
 */
int delete_List(Abstract_List this, int pos, DataType *value) {

	int length = length_List(this);
	ElemTP auxp, auxm;
	int i;

	if(this->first == NULL)
		return 0;
	if(pos < 1 || pos > length)
		return 0;
	/* check pos 1 */
	if(pos == 1) { /* delete first */
		auxp = this->first;
		this->first = this->first->next;
		*value = copyData_List(auxp->value);
		freeData_List(auxp->value);
		free(auxp);
		return 1;
	}	
	/* search */
	for(i = 1, auxp = this->first; i < pos-1; i++, auxp = auxp->next)
		;
	 
	auxm = auxp->next;
	auxp->next = auxp->next->next;
	*value = copyData_List(auxm->value);
	freeData_List(auxm->value);
	free(auxm);
	return 1;

}

/*
 * Function: length_List
 * Purpose: return the length of the list
 * Inputs: list
 * Returns:  the length of the list
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *  int i = length_List(p);
 */
int length_List(const Abstract_List this) {
	int i;
	ElemTP aux;

	for(i = 0, aux = this->first; aux != NULL; i++, aux = aux->next)
		;
	return i;
}

/*
 * Function: clear
 * Purpose: private function to remove all elements from the list
 * Inputs: list
 * Returns: nothing
 * Modifies: entire list
 * Error checking: none
 */
static void clear(Abstract_List this) {
	DataType junk;

	while(delete_List(this, 1, &junk))
		;
}

/*
 * Function: destruct_List
 * Purpose: destruct the list
 * Inputs: List p
 */
void destruct_List(Abstract_List *this) {
	clear(*this);
	free(*this);
	*this = NULL;
}

/***************** Implementation of Enumeration *****************/

struct Concrete_Enumeration {
	ElemTP pos;
};

/*
 * Function: hasMoreElements_Enumeration
 * Purpose: check if there is another element
 * Inputs: an abstract enumeration
 * Returns: 1 if there is another element, 0 otherwise
 * Modifies: nothing  
 * Error checking: none
 * 
 */
int hasMoreElements_Enumeration(Abstract_Enumeration e) {
	return e->pos != NULL;	
}

/*
 * Function: nextElement_Enumeration
 * Purpose: get another element
 * Inputs: an abstract enumeration
 * Returns: void* pointer to the next element, 
 *  or NULL if there is no other element
 * Modifies: nothing (except the internal state of the enumeration)
 * Error checking: none
 * 
 */
void* nextElement_Enumeration(Abstract_Enumeration e) {
	DataType aux;

	if(e->pos == NULL)
		return NULL;
	aux = copyData_List(e->pos->value);
	e->pos = e->pos->next;
	return aux;
}

/*
 * Function: construct_Enumeration
 * Purpose: return a new enumeration
 * Inputs: nothing
 * Returns: a new abstract enumeration
 * Modifies: nothing (except the internal state of the enumeration)
 * The client is responsible for deallocating this enumeration
 * Error checking: none
 * 
 */
Abstract_Enumeration construct_Enumeration(void *p) {
	Abstract_Enumeration e;	

	if((e = calloc(1, sizeof(struct Concrete_Enumeration))) == NULL)
		return NULL;
	e->pos = ((Abstract_List)p)->first;
	return e;
}

