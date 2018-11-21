#ifndef LINES_H
#define LINES_H
/*
 * File: ex7-4-lines.h
 * A header for the module with two simple operations on lines
 * Here, a line is of the form y = a*x + b, a!=0, and is represented
 * by a pair of double values.
 * Operations:
 *   check if two lines are parallel
 *   check if two lines are perpendicular
 */

/* 
 * Function: parallel_Lines
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
