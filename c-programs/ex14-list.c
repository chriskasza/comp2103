/*
 * File: ex14-list.c
 * Implementation file for the common code for list operations
 * Implements: 
 *	 the interface for the common parts of enumerations; file ex14-enum.h
 *	 functions declared in ex14-list.h
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "ex14-list.h"
#include "ex14-enum.h"

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
 * Function: construct_Lists
 * Purpose: constructor for the list
 * Inputs: elSize (size of each element); and two callback functions
 * Returns a list or NULL if failed
 * Sample call: 
 * if((p = construct_Lists(sizeof(char*), copyD, freeD)) == NULL) error
 */
Abstract_List construct_Lists(size_t elSize, void* (*copyData)(const void*),
	void (*freeData)(void*) ) {
	Abstract_List p;

	if((p = malloc(sizeof(struct Concrete_List))) == NULL)
		return NULL;
	p->first = NULL;
	p->elSize = elSize;
	p->freeData = freeData;
	p->copyData = copyData; 

	return p;
}

/*
 * Purpose: find the length of the list
 * Inputs: list
 * Returns:  the length of the list
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *  int i = length_Lists(p);
 */
int length_Lists(Abstract_List p) {
	int i;
	ElemTP aux;

	for(i = 0, aux = p->first; aux != NULL; i++, aux = aux->next)
		;
	return i;
}

/*
 * Function: clear
 * Purpose: private function to remove all elements from the list
 * Inputs: list this (parameter)
 */
static void clear(Abstract_List this) {
	ElemTP auxp;

	while(this->first != NULL) {
		auxp = this->first;
		this->first = this->first->next;
		if(this->freeData == NULL) /* shallow */
			free(auxp->value);
		else (this->freeData)(auxp->value); /* deep */
		free(auxp);
	}
}

/*
 * Function: destruct_Lists
 * Inputs: List this
 */
void destruct_Lists(Abstract_List *this) {
	clear(*this);
	free(*this);
	*this = NULL;
}

/******* enumeration ********************/

struct Concrete_Enumeration {
	Abstract_List list;
	ElemTP pos;
};

/*
 * Function: hasMoreElements_Enum
 * Purpose: check if there is another element
 * Inputs: an abstract enumeration
 * Returns: 1 if there is another element, 0 otherwise
 * Modifies: nothing  
 * Error checking: fails if not initialized
 * 
 */

int hasMoreElements_Enumeration(Abstract_Enumeration e) {
	return e->pos != NULL;	
}


/*
 * Function: construct_Enumeration
 * Purpose: return a new enumeration
 * Inputs: nothing
 * Returns: a new abstract enumeration, NULL if fails
 * Modifies: nothing (except the internal state of the enumeration)
 * The client is responsible for deallacating this enumeration
 * Error checking: none
 * 
 */
Abstract_Enumeration construct_Enumeration(void *p) {
	Abstract_Enumeration e;	

	if((e = calloc(1, sizeof(struct Concrete_Enumeration))) == NULL )
		return NULL;
	e->list = (Abstract_List)p; 
	e->pos = e->list->first;
	return e;
}

