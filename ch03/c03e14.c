/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	ch03ex14.c
 *
 * Calculate product of two double, float, and longs.
 * Be aware of overflow.
 */
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	double d1;
	double d2; 
	double product; 

	printf("Enter two decimal values:\n");
	if(scanf("%lf%lf", &d1, &d2) != 2) {
		printf("Sorry, I didn't see two numbers. Quitting.\n");
	} else {
		if(abs(d1) > abs(DBL_MAX / d2)) {
			printf("Sorry; we can't calculate that.  too big.\n");
		} else {
			product = d1 * d2;
			printf("The corresponding product is %f\n", product);
		}
	}
}
