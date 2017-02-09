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
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* 
 * Function: parallel_c07e27
 * Purpose: check if two lines are parallel
 * Inputs: a1, b1, c1, a2, b2, c2 (parameters)
 * Returns: 1 if a1*x + b1*y + c1*z = 0 is parallel to a2*x + b2*y + c2*z = 0, 0 otherwise
 * Modifies: Nothing
 * Error checking: None
 * Sample call:
 *    i = parallel_c07e27(1,2,3,1,2,3);
 * Since the lines 1*x + 2*y + 3*z = 0 and 1*x + 2*y + 3*z = 0 are parallel
 * the value of i will be 1.
 */
int parallel_c07e27(double a1, double b1, double c1, double a2, double b2, double c2) {
	return a1 == a2;
}

/* 
 * Function: perpendicular_c07e27
 * Purpose: check if two lines are perpendicular 
 * Inputs: a1, b1, c1, a2, b2, c2 (parameters)
 * Returns: 1 if a1*x + b1*y + c1*z = 0 is perpendicular to a2*x + b2*y + c2*z = 0, 0 otherwise
 * Modifies: Nothing
 * Error checking: None
 * Sample call:
 *    i = perpendicular_Lines (1,2,3,1,2,3);
 * Since the lines 1*x + 2*y + 3*z = 0 and 1*x + 2*y + 3*z = 0 are not perpendicular 
 * the value of i will be 0.
 */
int perpendicular_c07e27(double a1, double b1, double c1, double a2, double b2, double c2) {
	return (a2 == 0) ? 0 : (a1 == -1/a2);
}

#endif