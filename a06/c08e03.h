/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c08e03.h
 *
 * This module contains methods for creating and working with blocks of 
 * memory holding doubles.
 *
 */

#ifndef C08E03
#define C08E03

/*
 * Function: round
 * Purpose: round a double to an integer
 * Input: x is a double value
 * Returns: x, rounded to the nearest integer
 * Error checking: none
 * Sample call:
 *   a = round(3.1)
 *   -- will return 3
 *   b = round(3.5)
 *   -- will return 4
 *
 */
int myround(double x);

/*
 * Function: myAlloc
 * Purpose: allocates a block of memory to store n double values.
 * Inputs: n (parameter) - the size of the array to be created.
 * Returns: reference to memory where double array is stored.
 * Modifies: allocates memory for the double array.
 * Error checking: None.
 * Sample call:
 *   double arr[] = myAlloc(13);
 * Memory is allocated for a double array of size 13 and the reference to the 
 * array is assigned to x.
 */
double* myAlloc(int n);

/*
 * Function: get
 * Purpose: store values into the array, block[], provided via STDIN.
 * Inputs: block[] points to a block of memory of sufficient size to store
 *   `size` values.
 *         size represents the number of values the array, block[], can store.
 * Returns: the number of values read.
 * Modifies: block[] is populated with values provided by a user on STDIN.
 * Error checking: None.
 * Sample call:
 *   int num = get(arr[], 13);
 * Values provided by the user on STDIN are stored in arr[] and the number of 
 * stored values is stored in num.
 * 
 */
int get(double block[], int size);

/*
 * Function: show
 * Purpose: iterate over a double array and write each value on a separate line
 * Inputs: *block is the reference to a double array.
 *         size reflects the number of values stored in the array.
 * Returns: Nothing
 * Modifies: Nothing
 * Error checking: None.
 * Sample call:
 *   show(*arr, 13);
 * The array, arr, will be iterated over and the 13 elements it stores will be
 * written to STDOUT on separate lines.
 * 
 */
void show(double *block, int size);

/*
 * Function: max
 * Purpose: find the maximum value stored in a double array.
 * Inputs: *block is the reference to a double array.
 *         size reflects the number of values stored in the array.
 * Returns: the maximum value in the array.
 * Modifies: Nothing.
 * Error checking: None.
 * Sample call:
 *   double maxVal = max(*arr, 13);
 * The array, arr, will be iterated over and the maximum value in the array 
 * will be stored in maxVal.
 * 
 */
double max(double *block, int size);

#endif
