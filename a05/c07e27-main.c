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

#include "ex7-4-lines.h"
#include <stdlib.h>
#include <stdio.h>

int main( ) {
   int s;
   double x1, y1, c1, x2, y2, c2;
   double a1, b1, a2, b2;

   printf("Enter a maximum of 3 values.  The number of values corresponds to the following line formats:\n");
   printf("1) y = b\n");
   printf("2) y = mx + b\n");
   printf("3) Ax + By + C = 0\n");

   if(scanf("%d", &s) != 1 || s < 1 || s > 4) {
      fprintf(stderr, "invalid choice\n");
      return EXIT_FAILURE;
   }

   switch(s) {
   case 1:
      printf("\nEnter the three values corresponding to A, B, C for the first line: ");
      if(scanf("%lf%lf%lf", &x1, &y1, &c1) != 3) {
         fprintf(stderr, "invalid value\n");
         return EXIT_FAILURE;
      }
      printf("Enter the three values corresponding to A, B, C for the second line: ");
      if(scanf("%lf%lf%lf", &x2, &y2, &c2) != 3) {
         fprintf(stderr, "invalid value\n");
         return EXIT_FAILURE;
      }
      printf("\nLine1: %fx + %fy + %f = 0\n", x1, y1, c1);
      printf("Line2: %fx + %fy + %f = 0\n", x2, y2, c2);
      a1 = x1 * -1 / y1;
      b1 = c1 * -1 / y1;
      a2 = x2 * -1 / y2;
      b2 = c2 * -1 / y2;
      break;
   case 2:
      printf("Enter the three values corresponding to m and b for the first line: ");
      if(scanf("%lf%lf", &a1, &b1) != 2) {
         fprintf(stderr, "invalid value\n");
         return EXIT_FAILURE;
      }
      printf("Enter the three values corresponding to m and b for the second line: ");
      if(scanf("%lf%lf", &a2, &b2) != 2) {
         fprintf(stderr, "invalid value\n");
         return EXIT_FAILURE;
      }
      printf("\nLine1: y = %fx + %f\n", a1, b1);
      printf("Line2: y = %fx + %f\n", a2, b2);
      break;
   case 3:
      printf("Enter the three values corresponding to A, B, C for the first line: ");
      if(scanf("%lf%lf%lf", &x1, &y1, &c1) != 3) {
         fprintf(stderr, "invalid value\n");
         return EXIT_FAILURE;
      }
      printf("Enter the three values corresponding to A, B, C for the second line: ");
      if(scanf("%lf%lf%lf", &x2, &y2, &c2) != 3) {
         fprintf(stderr, "invalid value\n");
         return EXIT_FAILURE;
      }
      printf("\nLine1: %fx + %fy = %f\n", x1, y1, c1);
      printf("Line2: %fx + %fy = %f\n", x2, y2, c2);
      a1 = x1 * -1 / y1;
      b1 = c1 / y1;
      a2 = x2 * -1 / y2;
      b2 = c2 / y2;
      break;
   case 4:
      printf("Enter the value corresponding to m for the first line: ");
      if(scanf("%lf", &b1) != 1) {
         fprintf(stderr, "invalid value\n");
         return EXIT_FAILURE;
      }
      printf("Enter the value corresponding to m for the second line: ");
      if(scanf("%lf", &b2) != 1) {
         fprintf(stderr, "invalid value\n");
         return EXIT_FAILURE;
      }
      printf("\nLine1: y = %f\n", b1);
      printf("Line2: y = %f\n", b2);
      a1 = 0;
      a2 = 0;
      break;
   default:
      printf("Unknown line selection.\n");
      return EXIT_FAILURE;
   }

   printf("\nLines are %sparallel\n", 
      parallel_c07e27(a1,b1,a2,b2)? "" : "not ");
   printf("Lines are %sperpendicular\n", 
      perpendicular_c07e27(a1,b1,a2,b2)? "" : "not ");

   return EXIT_SUCCESS;
}
