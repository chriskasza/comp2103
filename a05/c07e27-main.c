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

/*
 * File: ex7-4-lines-main.c
 * An application of the module with two simple operations on lines.
 * The user enters coefficients of two lines, and the program
 *   checks if these two lines are parallel and perpendicular
 */

#include "ex7-4-lines.h"
#include <stdlib.h>
#include <stdio.h>

static int *coefficients;

int main( ) {
	int exes;
	
	printf("Enter the highest power of x in the equation (ex. highest power of x in y=x^3+4x-2 is 3): ");
	if(scanf("%d", &exes) != 1) {
		fprintf(stderr, "invalid power\n");
		return EXIT_FAILURE;
	}

	int size = atoi(exes);
	coefficients = malloc(size * sizeof(*coefficients));

	/* for x = exes; x>=0; x--; {
		printf("Enter the coefficient of x^%d", x); 
		if(scanf("%d", &coefficient) != 1) {
			fprintf(stderr, "invalid power\n");
			return EXIT_FAILURE;
		}
		coefficients[x] = coefficient;
	}
	*/


	double a1, b1, a2, b2;

	printf("Enter 4 values representing two lines\n");
	if(scanf("%lf%lf%lf%lf", &a1, &b1, &a2, &b2) != 4) {
		fprintf(stderr, "invalied coefficients\n");
		return EXIT_FAILURE;
	}
	printf("Line1: y = %fx +%f\n", a1, b1);
	printf("Line2: y = %fx +%f\n", a2, b2);
	printf("Lines are %s parallel\n", 
		parallel_Lines(a1,b1,a2,b2)? "" : "not");
	printf("Lines are %s perpendicular\n", 
		perpendicular_Lines(a1,b1,a2,b2)? "" : "not");

	return EXIT_SUCCESS;
}
