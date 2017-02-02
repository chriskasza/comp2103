#ifndef ENUMERATIONDEEP_H
#define ENUMERATIONDEEP_H
/*
 * File: ex14-enumDeep.h
 * Header of module for enumerating over data structures
 * This header file uses the root header file
 * It declares a function to
 * get the next element (returns a deep copy the data)
 */

#include "ex14-enum.h"

/*
 * Function: nextElement_EnumerationDeep
 * Purpose: get another element and return a deep copy of this element
 * Inputs: an abstract enumeration
 * Returns: void* pointer to the copy of the next element, 
 *  or NULL if there is no other element
 * Modifies: nothing (except the internal state of the enumeration)
 * Error checking: none
 * 
 */
void* nextElement_EnumerationDeep(Abstract_Enumeration);

#endif
