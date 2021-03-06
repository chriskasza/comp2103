/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c08e11.h
 *
 * This module provides a generic "bag" - a set where duplicate elements are
 * permitted.  The module provides simple add and remove operations, as well
 * as enumeration.
 */

#ifndef C08E11
#define C08E11

#include <stddef.h>

/*
 * Function:       bag_construct
 * Purpose:        construct a bag
 * Input:
 *    count:       number of elements in the bag
 *    size:        size of a single element
 * Returns:        1 for successful construction; 0 for unsuccessful;
 *                 0 if bag is already initialized
 * Modifies:       sets state of module
 * Error checking: checks that count and size are positive values
 *                 checks if bag is already initialized
 * Sample call:
 *    if(bag_construct(100, sizeof(double)) == 0)
 *      printf("failed to make the bag");
 *
 */
int bag_construct(size_t count, size_t size);

/*
 * Function:       bag_destruct
 * Purpose:        destruct a bag
 * Input:          -
 * Returns:        1 for successful destruction; 0 for unsuccessful
 * Modifies:       resets state of module
 * Error checking: checks if bag is initialized before destructing
 * Sample call:
 *    if(bag_destruct() == 0)
 *      printf("failed to destruct the bag");
 *
 */
int bag_destruct();

/*
 * Function:       bag_add
 * Purpose:        add an element to the bag
 * Input:
 *    item:        an element to be added to the bag
 * Returns:        1 upon success and 0 if unsuccessful
 * Modifies:       adds an element to the bag
 * Error checking: checks if bag is initialized
 *                 checks if there is room for the item
 * Sample call:
 *    double number = 123.4
 *    if(bag_add(number) == 0)
 *      printf("failed to add number to the bag");
 *
 */
int bag_add(void *item);

/*
 * Function:       bag_remove
 * Purpose:        remove an element from the bag
 * Input:          item to remove
 *                 a function to compare two elements which returns 1 on match
 *                   and 0 otherwise
 * Returns:        1 upon success and 0 if unsuccessful
 * Modifies:       removes the first occurrence of an element from the bag
 * Error checking: checks if the bag is initialized
 *                 checks if the bag is empty
 * Sample call:
 *    double number1 = 123.4
 *    if(bag_remove(number1, doubleCompare) == 0)
 *      printf("failed to remove number1 from the bag");
 *
 */
int bag_remove(void *item, int (*compare)(const void *, const void *));

#endif
