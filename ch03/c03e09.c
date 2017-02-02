/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	ch03ex09.c
 *
 * what are values of check, d, e, f?
 *
 */
#include <stdio.h>

int main() {
	int condition1 = 1;
	int condition2 = 0;
	int check;
	double d, e, f;

	check = condition1 && condition2 != 0; /* 1 & 0 = 1 */
	printf("check = %d\n", check);

	check = condition2 != 0;
	printf("check = %d\n", check);

	d = 1 / 2 * check; /* 1/2 = 0.5 * 1 = 0.5 (int) = 0 */
	e = (double)1 * 2; /* 1*2 = 2(double) = 2.0 */
	//f = double(3/2); /* compile error */
	
	printf("check = %d\nd = %f\ne = %f\n", check, d, e);
}
