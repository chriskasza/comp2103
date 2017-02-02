/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c07e07.c
 *
 * multiplies two integers and returns the result
 */

#include <errno.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Function: multiplier
 * Purpose: multiply two integers together
 * Inputs: integers m and n
 * Returns: result of multiplying m and n
 * Error checking: function will only process integers
 * Sample call: result = multiplier(m, n);
 */
double multiplier(double m, double n);

int main(int argc, char *argv[]) {
	double num1, num2, result;

	if(argc > 3 || argc < 3) {
		printf("err: %s requires two numerical arguments\n\n", argv[0]);
		return EXIT_FAILURE;
	} 

	num1 = atof(argv[1]);
	num2 = atof(argv[2]);

	result = multiplier(num1, num2);

	printf("%f\n\n", result);

	return EXIT_SUCCESS;
}


double multiplier(double m, double n) {
	double o;
	o = m * n;
	return o;
}

