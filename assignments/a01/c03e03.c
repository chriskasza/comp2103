/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	c03e03.c
 *
 * Calculate and display the changes to two variables using different operators.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i = 4;
	int j = 6;

	printf("\nTo start, i = %d and j = %d.\n\n", i, j);
	
	++i - j--;
	printf("Perform \"++i - j--\".\n");
	printf("Now, i = %d and j = %d.\n\n", i, j);

	i += j/2;
	printf("Perform \"i += j/2\".\n");
	printf("Now, i = %d and j = %d.\n\n", i, j);

	i % 2 + (j+=4);
	printf("Perform \"i % 2 + (j+=4)\".\n");
	printf("Now, i = %d and j = %d.\n\n", i, j);
	
	return EXIT_SUCCESS;
}
