/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c08e01.c
 *
 * This module contains methods for creating and working with blocks of
 * double arrays.
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, type, n)  \
  (((p) = malloc((n)*sizeof(type))) == NULL)

/*
 * Function: myAlloc
 * Purpose: allocates a block of memory to store n double values.
 * Inputs: n (parameter) - the size of the block to be created.
 * Returns: reference to memory where the block is stored.
 * Modifies: allocates memory for the block.
 * Error checking: None.
 * Sample call:
 *   double arr[] = myAlloc(13);
 * Memory is allocated store 13 values of type double and the reference to the
 * block is assigned to x.
 * Idiom used: Memory Allocation for n Integers.
 *
 */
double* myAlloc(int n) {
  double *a;

  if(MALLOC(a, double, n))
    exit(EXIT_FAILURE);

  return a;
}

/*
 * Function: get
 * Purpose: store values into the array, block[], provided via STDIN.
 * Inputs: block[] points to a block of memory of sufficient size to store
 *   `size` values.
 *         size represents the number of values the array, block[], can store.
 * Returns: the number of values read.
 * Modifies: block[] is populated with values provided by a user on STDIN.
 * Error checking: None.
 * Sample call:
 *   int num = get(arr[], 13);
 * Values provided by the user on STDIN are stored in arr[] and the number of
 * stored values is stored in num.
 * The iterator will stop when `size` values have been ented, a value rounded
 * to a whole number equals 1 or an invalid value is entered.
 * Idiom used: The ith Object.
 *
 */
int get(double block[], int size) {
  int c, i;

  printf("\nEnter a maximum of %d values which will be stored in an ", size);
  printf("array. Enter 1 to quit before %d values ", size);
  printf("have been entered.\n");

  for (i = 0; i < size; i++) {
    if (scanf("%lf", &block[i]) != 1) {
      fprintf(stderr, "invalid value\n");
      return EXIT_FAILURE;
    }
    while ((c = getchar()) != EOF && c != '\n');
    if (round(block[i]) == 1) {
      break;
    }
  }

  return i;
}

/*
 * Function: show
 * Purpose: iterate over a double array and write each value on a separate line
 * Inputs: *block is the reference to a double array.
 *         size reflects the number of values stored in the array.
 * Returns: Nothing
 * Modifies: Nothing
 * Error checking: None.
 * Sample call:
 *   show(*arr, 13);
 * The array, arr, will be iterated over and the 13 elements it stores will be
 * written to STDOUT on separate lines.
 * Idiom used: Block Traversal.
 *
 */
void show(double *block, int size) {
  int i;

  for (i = 0; i < size; i++) {
    printf("%lf\n", block[i]);
  }
}

/*
 * Function: max
 * Purpose: find the maximum value stored in a double array.
 * Inputs: *block is the reference to a double array.
 *         size reflects the number of values stored in the array.
 * Returns: the maximum value in the array.
 * Modifies: Nothing.
 * Error checking: None.
 * Sample call:
 *   double maxVal = max(*arr, 13);
 * The array, arr, will be iterated over and the maximum value in the array
 * will be stored in maxVal.
 * Idiom used: Block Traversal.
 *
 */
double max(double *block, int size) {
  double m;
  int i;

  m = block[0];
  for (i = 1; i < size; i++) {
    if (m < block[i])
      m = block[i];
  }

  return m;
}

