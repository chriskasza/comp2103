/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c04e07.c
 *
 * Read integers from STDIN then write the smallest 
 * inputted integer and average of all inputted integers.
 *
 * Boundary cases: 
 * If an input value equals -1 or exceeds 100, reading will stop.
 * Only integers are accepted, so input has to be in the bounds of
 * -2,147,483,648 to 100 (excluding -1).
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Read in integers. Calc avg and min when finished.
 */	
int main() {
	int i;
	int minInt = 101;
	int avgInt = -1;
	int totInt = 0;
	int numInts = 0;

	printf("Enter a bunch of integers no larger than 100.\n");
	printf("I'll calculate the average and minimum.\n");
	printf("Enter -1 when you're finished.\n");

	while(1) {
		if(scanf("%d", &i) != 1 || i == -1 || i > 100) {
			break;
		}
		totInt += i;		
		numInts++;
		if(i < minInt) {
			minInt = i;
		}
	}

	if(numInts == 0) {
		printf("No integers were inputted; therefore min and avg cannot "); 
		printf("be calculated.\n");
	} else {
		avgInt = totInt / numInts;
		printf("\nThank you for entering all %d of those integers.  ", numInts);
		printf("You're amazing.\nThe minimum integer you entered is ");
		printf("%d.\nThe average of all of the integers is ", minInt);
		printf("%d (rounded to the nearest integer).\n", avgInt);
	}
	
	return EXIT_SUCCESS;
}
