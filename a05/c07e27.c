/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c07e27.c
 *
 * Check whether two straight lines are parallel or perpendicular
 *
 */

#include "c07e27.h"
#include "ex7-4-lines.h"
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Function: parallel_c07e27
 * Purpose: check if two lines are parallel
 * Inputs: n - indicates the number of parameters that follow
 *         a minimum of two more parameters and a maximum of 6 representing
 *         the coffecients in the two lines.
 *         Two parameters after n correspond to line form y = b.
 *         Four parameters: y = m*x + b.
 *         Six parameters: 0 = a*x + b*y + c.
 * Returns: 1 if the lines are parallel; 0 otherwise
 * Modifies: Nothing
 * Error checking: Returns -1 if invalid number of parameters provided.
 * Sample call:
 *    i = parallel_c07e27(6, 1,2,3,1,2,3);
 * Since the lines 0 = 1*x + 2*y + 3*z and 0 = 1*x + 2*y + 3*z are parallel,
 * the value of i will be 1.
 */
int parallel_c07e27(int n, ...) {
  double l1[n], l2[n];
  double a1, b1, a2, b2;
  int i;
  va_list valist;

  va_start(valist, n);
  for (i = 0; i < n/2; i++) {
    l1[i] = va_arg(valist, double);
  }
  for (i = 0; i < n/2; i++) {
    l2[i] = va_arg(valist, double);
  }
  va_end(valist);

  switch(n) {
    case 2:
      a1 = 0;
      b1 = l1[0];
      a2 = 0;
      b2 = l2[0];
      break;
    case 4:
      a1 = l1[0];
      b1 = l1[1];
      a2 = l2[0];
      b2 = l2[1];
      break;
    case 6:
      a1 = l1[0] * -1 / l1[1];
      b1 = l1[2] * -1 / l1[1];
      a2 = l2[0] * -1 / l2[1];
      b2 = l2[2] * -1 / l2[1];
      break;
    default:
      return -1;
  }

  return parallel_Lines(a1,b1,a2,b2);
}

/*
 * Function: perpendicular_c07e27
 * Purpose: check if two lines are perpendicular
 * Inputs: n - indicates the number of parameters that follow
 *         a minimum of two more parameters and a maximum of 6 representing
 *         the coffecients in the two lines.
 *         Two parameters after n correspond to line form y = b.
 *         Four parameters: y = m*x + b.
 *         Six parameters: 0 = a*x + b*y + c.
 * Returns: 1 if the lines are perpendicular; 0 otherwise
 * Modifies: Nothing
 * Error checking: Returns -1 if invalid number of parameters provided.
 * Sample call:
 *    i = perpendicular_Lines (6, 1,2,3,1,2,3);
 * Since the lines 0 = 1*x + 2*y + 3*z and 0 = 1*x + 2*y + 3*z are not
 * perpendicular, the value of i will be 0.
 */
int perpendicular_c07e27(int n, ...) {
  double l1[n], l2[n];
  double a1, b1, a2, b2;
  int i;
  va_list valist;

  va_start(valist, n);
  for (i = 0; i < n/2; i++) {
    l1[i] = va_arg(valist, double);
  }
  for (i = 0; i < n/2; i++) {
    l2[i] = va_arg(valist, double);
  }
  va_end(valist);

  switch(n) {
    case 2:
      a1 = 0;
      b1 = l1[0];
      a2 = 0;
      b2 = l2[0];
      break;
    case 4:
      a1 = l1[0];
      b1 = l1[1];
      a2 = l2[0];
      b2 = l2[1];
      break;
    case 6:
      a1 = l1[0] * -1 / l1[1];
      b1 = l1[2] * -1 / l1[1];
      a2 = l2[0] * -1 / l2[1];
      b2 = l2[2] * -1 / l2[1];
      break;
    default:
      return -1;
  }

  return perpendicular_Lines(a1,b1,a2,b2);
}

