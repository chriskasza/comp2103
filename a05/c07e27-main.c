/*
 * Author:    Chris Kasza
 * Student #:  100133723
 * Course:    COMP 2103 N1
 * Version:   1.0
 * File:     c07e27-main.c
 *
 * Check whether two lines are parallel or perpendicular

 * An application of a module with two operations for lines.
 * The user enters coefficients of two lines, and the program
 *  checks if these two lines are parallel and perpendicular
 *
 */

#include "c07e27.h"
#include <stdlib.h>
#include <stdio.h>

int main( ) {
  int s;
  double a1, b1, c1, a2, b2, c2;

  printf("Which format are your lines?  ");
  printf("The selection corresponds to the number of values expected:\n");
  printf("1) y = b\n");
  printf("2) y = mx + b\n");
  printf("3) Ax + By + C = 0\n");

  if(scanf("%d", &s) != 1 || s < 1 || s > 3) {
    fprintf(stderr, "invalid choice\n");
    return EXIT_FAILURE;
  }

  printf("\n");
  switch(s) {
  case 1:
    while ((s = getchar()) != EOF && s != '\n');
    printf("Enter the value corresponding to b for the first line: ");
    if(scanf("%lf", &a1) != 1) {
      fprintf(stderr, "invalid value\n");
      return EXIT_FAILURE;
    }
    while ((s = getchar()) != EOF && s != '\n');
    printf("Enter the value corresponding to b for the second line: ");
    if(scanf("%lf", &a2) != 1) {
      fprintf(stderr, "invalid value\n");
      return EXIT_FAILURE;
    }
    printf("\nLine1: y = %f\n", a1);
    printf("Line2: y = %f\n", a2);
    printf("\nLines are %sparallel\n",
      parallel_c07e27(2, a1,a2)? "" : "not ");
    printf("Lines are %sperpendicular\n",
      perpendicular_c07e27(2, a1,a2)? "" : "not ");
    break;
  case 2:
    while ((s = getchar()) != EOF && s != '\n');
    printf("Enter the two values corresponding to m and b for the first line: ");
    if(scanf("%lf%lf", &a1, &b1) != 2) {
      fprintf(stderr, "invalid value\n");
      return EXIT_FAILURE;
    }
    while ((s = getchar()) != EOF && s != '\n');
    printf("Enter the two values corresponding to m and b for the second line: ");
    if(scanf("%lf%lf", &a2, &b2) != 2) {
      fprintf(stderr, "invalid value\n");
      return EXIT_FAILURE;
    }
    printf("\nLine1: y = %fx + %f\n", a1, b1);
    printf("Line2: y = %fx + %f\n", a2, b2);
    printf("\nLines are %sparallel\n",
      parallel_c07e27(4, a1,b1,a2,b2)? "" : "not ");
    printf("Lines are %sperpendicular\n",
      perpendicular_c07e27(4, a1,b1,a2,b2)? "" : "not ");
    break;
  case 3:
    while ((s = getchar()) != EOF && s != '\n');
    printf("\nEnter the three values corresponding to A, B, C for the first line: ");
    if(scanf("%lf%lf%lf", &a1, &b1, &c1) != 3) {
      fprintf(stderr, "invalid value\n");
      return EXIT_FAILURE;
    }
    while ((s = getchar()) != EOF && s != '\n');
    printf("Enter the three values corresponding to A, B, C for the second line: ");
    if(scanf("%lf%lf%lf", &a2, &b2, &c2) != 3) {
      fprintf(stderr, "invalid value\n");
      return EXIT_FAILURE;
    }
    printf("\nLine1: %fx + %fy + %f = 0\n", a1, b1, c1);
    printf("Line2: %fx + %fy + %f = 0\n", a2, b2, c2);
    printf("\nLines are %sparallel\n",
      parallel_c07e27(6, a1,b1,c1,a2,b2,c2)? "" : "not ");
    printf("Lines are %sperpendicular\n",
      perpendicular_c07e27(6, a1,b1,c1,a2,b2,c2)? "" : "not ");
    break;
  default:
    printf("Unknown line selection.\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
