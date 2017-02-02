/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	c03e11.c
 *
 * Request the radius of a circle from a user, then use the area
 * to calculate the area of the circle.
 *
 * To compile run `gcc c03e11.c -lm -o c03e11`
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	const double PI = 3.1415926535;
	double radius = 0;
	double area;

	printf("Enter the length of the radius of the circle: ");
	if(scanf("%lf", &radius) != 1) {
		printf("That was not a valid number. Quitting.\n");
		return EXIT_FAILURE;
	} else {
		area = PI * pow(radius,  2.0);
		printf("\nThe area of the circle with that radius in a field with width "
				"10) is \n");
		printf("%-10.4f (fixed-point notation, left justified, precision 4)"
				"\n", area);
		printf("%10.4f (fixed-point notation, right justified, precision 4)"
				"\n", area);
		printf("%010.4f (fixed-point notation, right justified, precision 4, "
				"padded with 0's)\n", area);
		printf("%-10.4e (scientific notation, left justified, precision 4)"
				"\n", area);
		printf("%010.4e (scientific notation, right justified, precision 4)"
				"\n\n", area);
		return EXIT_SUCCESS;
	}
}
