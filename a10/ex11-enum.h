#ifndef EX11_ENUM_H
#define EX11_ENUM_H
/*
 * File: ex11-enum.h
 * Header of the pure interface for enumerating over data structures
 * This header file will have no corresponding implementation file
 * It declares three functions to
 * return a new enumeration
 * check if there is another element
 * get the next element
 */

/* the following definition uses the Opaque idiom */
typedef struct Concrete_Enumeration *Abstract_Enumeration;

/*
 * Function: hasMoreElements_Enumeration
 * Purpose: check if there is another element
 * Inputs: an abstract enumeration
 * Returns: 1 if there is another element, 0 otherwise
 * Modifies: nothing  
 * Error checking: none
 * 
 */
int hasMoreElements_Enumeration(Abstract_Enumeration);

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
void * nextElement_Enumeration(Abstract_Enumeration);

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
Abstract_Enumeration construct_Enumeration(void *);

/* Macros that helps to avoid casting */
#define nextElementTyped_Enumeration(type, p) \
	((type)nextElement_Enumeration(p))

#endif

