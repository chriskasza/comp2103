#ifndef ENUM_H
#define ENUM_H
/*
 * File: ex8-enum.h
 * Header of the pure interface for enumerating over data structures
 * This header file will have no corresponding implementation file
 * It declares three functions to
 * reset an enumeration
 * check if there is another element
 * get the next element
 */

/*
 * Function: hasMoreElements_Enum
 * Purpose: check if there is another element
 * Inputs: nothing
 * Returns: 1 if there is another element, 0 otherwise
 * Modifies: nothing  
 * Error checking: none
 */
int hasMoreElements_Enum();

/*
 * Function: nextElement_Enum
 * Purpose: get another element
 * Inputs: nothing
 * Returns: void* pointer to the next element, 
 *  or NULL if there is another element
 * Modifies: nothing (except the internal state of the enumeration)
 * Error checking: none
 */
void* nextElement_Enum();

/*
 * Function: reset_Enum
 * Purpose: reset the enumeration
 * Inputs: nothing
 * Returns: nothing
 * Modifies: nothing (except the internal state of the enumeration)
 * Error checking: none
 */
void reset_Enum();

#endif
