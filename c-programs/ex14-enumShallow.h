#ifndef ENUMERATIONSHALLOW_H
#define ENUMERATIONSHALLOW_H
/*
 * File: ex14-enumShallow.h
 * Header of the module for enumerating over data structures using the shallow copy
 * This header file uses the "root" header file for enumerating
 * It declares a function to
 * get the next element (returns a shallow copy of the data)
 */

#include "ex14-enum.h"

/*
 * Function: nextElement_EnumerationShallow
 * Purpose: get another element
 * Inputs: an abstract enumeration
 * Returns: void* pointer to the next element, 
 *  or NULL if there is no other element
 * Modifies: nothing (except the internal state of the enumeration)
 * Error checking: none
 * 
 */
void* nextElement_EnumerationShallow(Abstract_Enumeration);

#endif
