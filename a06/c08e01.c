/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c08e01.c
 *
 * modify two values to demonstrate the functionality of the Pass by
 * Reference idiom.
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
void alter(double *x, double *y) {
  *x = *x - *y;
  *y = 2;
}
