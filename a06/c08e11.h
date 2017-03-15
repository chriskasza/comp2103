/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c08e11.h
 *
 * This module provides a generic "bag" collection where duplicate elements are
 * permitted.  The module provides simple add and remove operations, as well
 * as enumeration.
 *
 */

#ifndef C08E11
#define C08E11

/*
 * Function: add
 * Purpose: add an element to the bag
 * Input: item is the element to be added
 * Returns: 0 upon success and -1 if unsuccessful
 * Error checking: none
 * Sample call:
 *   mybag.add(3)
 *   -- adds 3 to the bag and returns 0
 *
 */
int add(double item);

/*
 * Function: remove
 * Purpose: remove an element from the bag
 * Input: item to remove
 * Returns: 0 upon success and -1 if unsuccessful
 * Error checking: none
 * Sample call:
 *   mybag.remove(3)
 *   -- removes first occurrence of 3 from the bag and returns 0
 *
 */
int remove(void **item);

/*
 * Function: find
 * Purpose: find an element in the bag
 * Input: item to be found in the bag
 * Returns: 0 upon success and -1 if unsuccessful
 * Error checking: none
 * Sample call:
 *   mybag.find(3)
 *   -- finds the first occurrence of 3 in the bag and returns 0
 *
 */
int find(void **item);

