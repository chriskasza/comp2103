/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c07e23.c
 *
 * Function to generate a random number in range 0-100
 * 
 */

#include "c07e23.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Function: randomInt */
int randomInt(int i) {
	const int A = 11; /* prime number */
	const int B = 49; 
	const int C = 101;
	int rand;

	/* if negative number, convert to positive */
	if(i < 0) {
		i = abs(i);
	}

	/* return 91 at end of recursion */
	if(i <= 1) {
		return 91;
	}

	rand = (A*randomInt(i-1) + B) % C;
	return rand;
}

int main(int argc, char *argv[]) {
	double inNum;
	int    outNum;

	if(argc > 2 || argc < 2) {
		printf("err: %s requires one numerical argument\n\n", argv[0]);
		return EXIT_FAILURE;
	}

	inNum = atof(argv[1]);

	outNum = randomInt((int)inNum);

	printf("%d\n\n", outNum);

	return EXIT_SUCCESS;	
}
