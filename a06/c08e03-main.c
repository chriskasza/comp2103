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
  double *b;

  b = myAlloc(10);

  get(b, 10);

  printf("\nValues entered were: \n");
  show(b, 10);

  printf("\nMax value entered was %f.\n", max(b, 10));

  /*  Dereferencing for practice */
  free(b);
  b = NULL;

  return EXIT_SUCCESS;
}
