/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c10e03.h
 *
 * a library of functions for reversing arrays.
 *
 */

#include <stddef.h>

/*
 * Function:       reverse
 * Purpose:        reverse a given array and return the reversed array by
 *                 storing it at the location specified by the second parameter
 * Inputs:
 *   a:            the array to be reversed
 *   r:            pointer of where the reversed array will be stored
 *   n:            the size of the array
 * Returns:        1 if successful; 0 otherwise
 * Modifies:       the pointer, r, will be used to store the reversed array
 * Error checking: checks that n is positive
 * Sample call:
 *    reverse(*myarray, *myreversedarray, SIZE)
 */
int reverse(void *a, void *r, size_t n) {

}

/*
 * Function:       reverseMyself
 * Purpose:        reverse a given array such that the reversed array replaces
 *                 the original array
 * Inputs:
 *   a:            the array to be reversed
 *   n:            the size of the array
 * Returns:        1 if successful; 0 otherwise
 * Modifies:       the provided array is reversed in place
 * Error checking: checks that n is positive
 * Sample call:
 *    reverse(*myarray, SIZE)
 */
int reverseMyself(void *a, size_t n) {

}

