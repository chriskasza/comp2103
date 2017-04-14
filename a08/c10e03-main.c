/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c10e03-main.c
 *
 * Driver for c10e03.
 *
 */

#include "c10e03.h"
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, type, n) (((p) = malloc((n)*sizeof(type))) == NULL)

/*
 * Function:       myround
 * Purpose:        round a double to an integer
 * Input:
 *   x:            a double value
 * Returns:        x, rounded to the nearest integer
 * Error checking: none
 * Sample call:
 *   a = myround(3.1)
 *     // will return 3
 *   b = myround(3.5)
 *     // will return 4
 */
int myround(double x) {
  return (x >= 0) ? (int)(x + 0.5) : (int)(x - 0.5);
}


/*
 * Function:       get
 * Purpose:        requests values from STDIN and stores them into an array
 * Inputs:
 *   block[]:      points to a block of memory of sufficient size to store
 *                 `size` values.
 *   size:         represents the number of values `block[]` can store
 * Returns:        the number of values read in
 * Modifies:       block[] is populated with values provided via STDIN
 * Error checking: None.
 * Sample call:
 *   int num = get(arr[], 13);
 */
int get(double *block, size_t size) {
  int c;
  int i;

  printf("\nEnter %lu values which will be stored in an array.\n", size);

  for (i = 0; i < size; i++) {
    if (scanf("%lf", &block[i]) != 1) {
      fprintf(stderr, "invalid value\n");
      i--;
    }
    while ((c = getchar()) != EOF && c != '\n');
  }

  return i;
}

/*
 * Function:       printarray
 * Purpose:        prints each element of an array on a separate line
 * Inputs:
 *   block:        the array to be printed
 *   size:         the size of the array
 * Returns:        1 if successful; otherwise 0
 * Modifies:       nothing
 * Error checking: none
 * Sample call:
 *   get(arr[], 13);
 */
int printarray(double *block, size_t size) {
  int i;

  for (i = 0; i < size; i++) {
    if (printf("%f", block[i]) != 1)
      return 0;
  }

  return 1;
}

/*
 * main
 */
int main(int argc, char *argv[]) {
  double *myarray;
  double *myreversedarray;
  int i;
  size_t size;

  if(argc != 2 || (sscanf(argv[1], "%lu", &size) != 1)) {
    fprintf(stderr, "usage: %s <size of array>\nex. %s 10\n", argv[0],argv[0]);
    return EXIT_FAILURE;
  }

  if(MALLOC(myarray, double, size)) {
    fprintf(stderr, "failed to allocate memory for array\n");
    return EXIT_FAILURE;
  }

  if(MALLOC(myreversedarray, double, size)) {
    fprintf(stderr, "failed to allocate memory for reversed array\n");
    return EXIT_FAILURE;
  }

  if(get(myarray, size) < 0) {
    fprintf(stderr, "failed to store values\n");
    return EXIT_FAILURE;
  }

  if(reverse(myarray, myreversedarray, sizeof(double), size) == 0) {
    fprintf(stderr, "failed to reverse array\n");
    return EXIT_FAILURE;
  }

  printf("\nReversing the array, we have\n");
  for(i = 0; i < size; i++) {
    printf("Original array: %f\tReversed array: "
      "%f\n", myarray[i], myreversedarray[i]);
  }

  if(reverseMyself(myarray, sizeof(double), size) == 0) {
    fprintf(stderr, "failed to reverse array\n");
    return EXIT_FAILURE;
  }

  printf("\nReversing and overwriting the original array, we have\n");
  for(i = 0; i < size; i++) {
    printf("Original array: %f\n", myarray[i]);
  }

  return EXIT_SUCCESS;
}
