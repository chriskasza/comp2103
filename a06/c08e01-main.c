/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c08e01-main.c
 *
 * Driver for c08e01.
 *
 */

#include "c08e01.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Function: alter
 * Purpose: modify two variables using references
 * Inputs: x, y - parameters of references for doubles
 * Returns: Nothing
 * Modifies: the two references passed
 * Error checking: None
 * Sample call:
 *    alter(a, b)
 * a will be modified to (a - b) and b will be modified to 2.
 */
int main() {
  double a = 5;
  double b = 10;


  printf("a is %f and b is %f.\n", a, b);
  alter(&a, &b);
  printf("\"alter\" 'em up and you get a = %f and b = %f.\n", a, b);

  return EXIT_SUCCESS;
}
