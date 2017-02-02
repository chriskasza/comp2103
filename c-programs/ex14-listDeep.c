/*
 * File: ex14-listDeep.c
 * Implementation file for deep interface
 * Implements: 
 *	 the interface for deep lists
 *	 the interface for deep enumerations
 */

#include <stdlib.h>
#include <stdio.h>
#include "ex14-listDeep.h"
#include "ex14-enumDeep.h"

typedef struct elem {
	void *value;
	struct elem *next;
} ElemT, *ElemTP;

struct Concrete_List {
	ElemTP first;
	size_t elSize;
	void* (*copyData)(const void*);
	void (*freeData)(void*);
};
/*
 * Function: insert_ListsDeep
 * Purpose: insert a new element before the i-th element (in front for i=0)
 * Inputs: List p, position i, and a void *value (parameters)
 * The client can get the value for i using an enumeration
 * Returns: 1 if successful, 0 if fails
 * Modifies: list
 * Error checking: If the index is wrong or memory allocation fails, 0 is returned 
 * Sample call:
 *  if(insert_ListsDeep(p, 0, &"hello") == 1) ... inserted "hello" in front of p 
 */
int insert_ListsDeep(Abstract_List this, int pos, void *value) {
	int i;
	ElemTP auxp, auxm;
	int length = length_Lists(this);
	
	if(pos < 0 || pos > length)
		return 0;
	if(pos == 0) /* in front */ {
		if((auxm = malloc(sizeof(ElemT))) == NULL)
			return 0;
		auxm->value = this->copyData(value);
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
	auxm->value = (this->copyData)(value);
	auxm->next = auxp->next; /* connect with old list*/
	auxp->next = auxm;

	return 1;
}
	
/*
 * Function: delete_ListsDeep
 * Purpose: delete the i-th element  
 * Inputs: List p, position i, and a void *value (parameters)
 * The client can get the value for i using an enumeration
 * Returns: 1 if successful (in this case the copy of the value from the deleted element is
 *  returned through the third parameter, 0 if fails;
 * Modifies: list
 * Error checking: If the index is wrong, 0 is returned 
 * Sample call:
 *  if(delete_ListsDeep(p, 1, &x) == 1) ... x has the value from what was the first element 
 */
int delete_ListsDeep(Abstract_List this, int pos, void *value) {
	int length = length_Lists(this);
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
		value = (this->copyData)(auxp->value);
		free(auxp);
		return 1;
	}	
	/* search */
	for(i = 1, auxp = this->first; i < pos-1; i++, auxp = auxp->next)
		;
	 
	auxm = auxp->next;
	auxp->next = auxp->next->next;
	value = (this->copyData)(auxm->value); 
	(this->freeData)(auxm->value);	
	free(auxm);
	return 1;
}

struct Concrete_Enumeration {
	Abstract_List list;
	ElemTP pos;
};
/*
 * Function: nextElement_EnumerationDeep
 * Purpose: get another element
 * Inputs: an abstract enumeration
 * Returns: pointer to the copy of the data in the next element, 
 *  or NULL if there is no other element
 * Modifies: The internal state of the enumeration
 * Error checking: none
 * 
 */
void* nextElement_EnumerationDeep(Abstract_Enumeration e) {
	void *aux;

	if(e->pos == NULL)
		return NULL;
	aux = (e->list->copyData)(e->pos->value);
	e->pos = e->pos->next;
	return aux;
}

