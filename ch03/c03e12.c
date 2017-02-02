/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	ch03ex11.c
 *
 * user provides radius.  calculate area
 */
#include <stdio.h>
#include <math.h>

int main() {
	int i;

	printf("Enter a character: ");
	if((i = getchar()) == EOF) {
		printf("That was not a valid character. Quitting.\n");
	} else {
		printf("The corresponding integer value is %d\n", i);
	}
}
