/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	ch03ex04.c
 *
 * dbl_max, dbl_max_10_exp, dbl_max_exp
 */
#include <stdio.h>
#include <float.h>

int main() {
	printf("The max double is \t%f\n", DBL_MAX);
	printf("Double with exp is \t%f\n", DBL_MAX_EXP);
	printf("And base 10 is \t%f\n", DBL_MAX_10_EXP);

	printf("The min double is \t%f\n", DBL_MIN);
	printf("Double with exp is \t%f\n", DBL_MIN_EXP);
	printf("And base 10 is \t%f\n", DBL_MIN_10_EXP);
}
