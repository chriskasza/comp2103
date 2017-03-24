/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c08e11.c
 *
 * This module provides a generic "bag" - a set where duplicate elements are
 * permitted.  The module provides simple add and remove operations, as well
 * as enumeration.
 */

#include <stdlib.h>
#include "c08e11.h"

#define NOT_INITIALIZED 0
#define INITIALIZED 1

static int initialized_ = NOT_INITIALIZED;

static void *bag_ = NULL;  /* the bag */
static void *current_ = NULL; /* current item for enumeration */

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
int bag_construct(int count, size_t size) {
  if(initialized_ == INITIALIZED)
    return 0;

  if(count < 1 || size < 1)
    return 0;

  if((bag_ = malloc(count*size)) == NULL)
    return 0;

  initialized_ = INITIALIZED;

  return 1;
}

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
int bag_destruct() {
  if(initialized_ == NOT_INITIALIZED)
    return 0;

  free(bag_);
  initialized_ = NOT_INITIALIZED;
  bag_ = NULL;

  return 1;
}

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
int bag_add(void *item) {
  
}

/*
 * Function:       bag_remove
 * Purpose:        remove an element from the bag
 * Input:          item to remove
 * Returns:        1 upon success and 0 if unsuccessful
 * Modifies:       removes the first occurrence of an element from the bag
 * Error checking: checks if the bag is initialized
 *                 checks if the bag is empty
 * Sample call:
 *    double number1 = 123.4
 *    if(bag_remove(number1) == 0)
 *      printf("failed to remove number1 from the bag");
 */
int bag_remove(void *item) {

}

/*
 * Function:       bag_find
 * Purpose:        find an element in the bag
 * Input:          item to be found in the bag
 * Returns:        address of the first occurrence of the item in the bag
 *                 or 0 if unsuccessful
 * Modifies:       
 * Error checking: none
 * Sample call:
 *    double number2 = 123.4
 *    double *numaddr;
 *    if((numaddr = bag_find(number2)) == 0)
 *      printf("failed to find number2 in the bag");
 */
void *bag_find(void *item) {
  /* use quicksort and binary search from stdlib.h? */
}


/*
 * Function:       bag_next
 * Purpose:        return the item from the bag
 * Input:          
 * Returns:        pointer to the next item or NULL if there is none
 * Modifies:       
 * Error checking: none
 * Sample call:
 *    double number2 = 123.4
 *    double *numaddr;
 *    if((numaddr = bag_find(number2)) == 0)
 *      printf("failed to find number2 in the bag");
 */
void *bag_next() {

}

/*
 * Function:       bag_reset_current
 * Purpose:        return the item from the bag
 * Input:          
 * Returns:        pointer to the next item or NULL if there is none
 * Modifies:       
 * Error checking: none
 * Sample call:
 *    double number2 = 123.4
 *    double *numaddr;
 *    if((numaddr = bag_find(number2)) == 0)
 *      printf("failed to find number2 in the bag");
 */
int bag_reset_current() {

}


