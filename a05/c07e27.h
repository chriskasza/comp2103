/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c07e27.h
 *
 * Extend ex7-4-lines.h, allowing for any type of line to provided
 * 
 */

#ifndef C07E27
#define C07E27

#include "ex7-4-lines.h"

/* 
 * Function: parallel_C07e27
 * Purpose: generate a pseudo-random integer in the range 0-100
 * Inputs: integer i; pseudo-random integer is based off this intger, i.
 * Returns: integer in range 0-100
 * Error checking: 
 * Sample call: rando = randomInt(5);
 */
int parallel_C07e27(int i);

int perpendicular_C07e27(

#endif

/* 
 * Function: parallel_C07e27
 * Purpose: check if two lines are parallel
 * Inputs: a1, b1, a2, b2 (parameters)
 * Returns: 1 if y=a1*x+b1 is parallel to y=a2*x+b2, 0 otherwise
 * Modifies: Nothing
 * Error checking: None
 * Sample call:
 *    i = parallel_Lines(4,2,4,7);
 * Since the lines y = 4x + 2 and y = 4x + 7 are parallel
 * the value of i will be 1.
 */
int parallel_Lines(double a1, double b1, double a2, double b2);

/* 
 * Function: perpendicular_Lines
 * Purpose: check if two lines are perpendicular 
 * Inputs: a1, b1, a2, b2 (parameters)
 * Returns: 1 if y=a1*x+b1 is perpendicular to y=a2*x+b2, 0 otherwise
 * Modifies: Nothing
 * Error checking: None
 * Bugs: Returns 0 if a2=0 
 * Sample call:
 *    i = perpendicular_Lines (4,2,4,7);
 * Since the lines y = 4x + 2 and y = 4x + 7 are not perpendicular 
 * the value of i will be 0.
 */
int perpendicular_Lines(double a1, double b1, double a2, double b2);

#endif
