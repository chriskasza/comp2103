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

#include "c10e03.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOID(targ,size) ((void *)(((char *)(targ)) + (size)))
#define VOIDSUB(targ,size) ((void *)(((char *)(targ)) - (size)))

/*
 * Function:       reverse
 * Purpose:        reverse a given array and return the reversed array by
 *                 storing it at the location specified by the second parameter
 * Inputs:
 *   a:            the array to be reversed
 *   r:            pointer of where the reversed array will be stored
 *   e:            the size of an element in the array
 *   n:            the number of elements in the array
 * Returns:        1 if successful; 0 otherwise
 * Modifies:       the pointer, r, will be used to store the reversed array
 * Error checking: checks that e and n are positive
 * Sample call:
 *    reverse(*myarray, *myreversedarray, sizeof(int), SIZE)
 */
int reverse(void *a, void *r, size_t e, size_t n) {
  int arrsize;
  void *i = NULL;
  void *j = NULL;

  if(e < 1 || n < 1)
    return 0;

  arrsize = e * n;

  for(i = a, j = VOID(r, arrsize-e); i < VOID(a, arrsize);
      i = VOID(i, e), j = VOIDSUB(j, e)) {
    memcpy(j, i, e);
  }

  return 1;
}

/*
 * Function:       reverseMyself
 * Purpose:        reverse a given array such that the reversed array replaces
 *                 the original array
 * Inputs:
 *   a:            the array to be reversed
 *   e:            the size of an element in the array
 *   n:            the number of elements in the array
 * Returns:        1 if successful; 0 otherwise
 * Modifies:       the provided array is reversed in place
 * Error checking: checks that n is positive
 * Sample call:
 *    reverse(*myarray, sizeof(int), SIZE)
 */
int reverseMyself(void *a, size_t e, size_t n) {
  int arrsize;
  void *i = NULL;
  void *j = NULL;
  void *t = NULL;

  if(e < 1 || n < 1)
    return 0;

  if((t = malloc(e)) == NULL)
    return 0;

  arrsize = e * n;

  for(i = a, j = VOID(i, arrsize-e); i < j; i = VOID(i, e), j = VOIDSUB(j, e)) {
    memcpy(t, i, e);
    memcpy(i, j, e);
    memcpy(j, t, e);
  }

  return 1;

}

