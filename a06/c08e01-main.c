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
 *
 */
int main() {
  double a = 5;
  double b = 10;


  printf("a is %f and b is %f.\n", a, b);
  alter(&a, &b);
  printf("\"alter\" 'em up and you get a = %f and b = %f.\n", a, b);

  return EXIT_SUCCESS;
}
