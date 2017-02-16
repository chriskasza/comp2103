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
#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main() {
  double *b;

  b = myAlloc(10);
  get(b, 10);
  show(b, 10);
  max(b, 10);

  return EXIT_SUCCESS;
}
