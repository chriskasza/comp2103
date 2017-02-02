/*
 * File: ex7-4-lines-main.c
 * An application of the module with two simple operations on lines.
 * The user enters coefficients of two lines, and the program
 *   checks if these two lines are parallel and perpendicular
 */

#include "ex7-4-lines.h"
#include <stdlib.h>
#include <stdio.h>
int main( ) {
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
