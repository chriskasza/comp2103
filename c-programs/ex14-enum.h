#ifndef ENUMERATION_H
#define ENUMERATION_H
/*
 * File: ex14-enum.h
 * Header of the pure interface for enumerating over data structures
 * This header file will have no corresponding implementation file
 * It contains functions common to two implementations: shallow and deep.
 * It declares two functions to
 * return a new enumeration
 * check if there is another element
 */

/* the following definition uses the Opaque idiom */
typedef struct Concrete_Enumeration *Abstract_Enumeration;

/*
 * Function: hasMoreElements_Enum
 * Purpose: check if there is another element
 * Inputs: an abstract enumeration
 * Returns: 1 if there is another element, 0 otherwise
 * Modifies: nothing  
 * Error checking: none
 */
int hasMoreElements_Enumeration(Abstract_Enumeration);

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
Abstract_Enumeration construct_Enumeration(void *);


#endif
