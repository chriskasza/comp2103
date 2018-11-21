/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c08e03-main.c
 *
 * Driver for c08e03.
 *
 */

#include "c08e03.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main() {
  const int NUMVALS = 10;
  int numVals2 = NUMVALS * 2;
  int numReadIn;
  double *b;

  b = myAlloc(NUMVALS);

  numReadIn = get(b, NUMVALS);

  printf("\n%d values were entered: \n", numReadIn);
  show(b, numReadIn);

  printf("\nMax value entered was %f.\n", max(b, numReadIn));

  free(b);
  b = NULL;

  b = myAlloc(numVals2);

  numReadIn = get(b, numVals2);

  printf("\n%d values were entered: \n", numReadIn);
  show(b, numReadIn);

  printf("\nMax value entered was %f.\n", max(b, numReadIn));

  free(b);
  b = NULL;

  return EXIT_SUCCESS;
}
