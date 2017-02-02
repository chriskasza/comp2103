/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	ch03ex04.c
 *
 * 
 */
#include <stdio.h>

int main() {
	double i = 1+(3-2)*4 / 5 % 6; //1.66
	double j = 9 % 2 % 3 % 4 % 5; //4
	int k = (int)((double)5 + 3.14) % 2;

	printf("\ni = %f\n", i);
	printf("\nj = %f\n", j);
	printf("\nk = %d\n", k);
}
