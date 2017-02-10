/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c07e27-main.c
 *
 * Check whether two lines are parallel or perpendicular

 * An application of a module with two operations for lines.
 * The user enters coefficients of two lines, and the program
 *   checks if these two lines are parallel and perpendicular
 * 
 */

#include "c07e27.h"
#include <stdlib.h>
#include <stdio.h>

int main( ) {
   double a1 = 1;
   double b1 = 1;
   double c1 = 1;
   double a2 = 1;
   double b2 = 1;
   double c2 = 1;

   printf("\nLines are %sparallel\n", 
      parallel_c07e27(a1,b1,c1,a2,b2,c2)? "" : "not ");

   printf("Lines are %sperpendicular\n", 
      perpendicular_c07e27(a1,b1,c1,a2,b2,c2)? "" : "not ");

   return EXIT_SUCCESS;
}
