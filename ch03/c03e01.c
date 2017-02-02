/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	ch03ex01.c
 *
 * Calculate and display the changes to two variables using different operators.
 */
#include <stdio.h>

int main() {
	int x = 4;
	int y = 6;

	printf("\nTo start, x = %d and y = %d.\n\n", x, y);
	
	x+++y;
	printf("Perform \"x+++y\".\n");
	printf("Now, x = %d and y = %d.\n\n", x, y);

	x++>=++y;
	printf("Perform \"x++>=++y\".\n");
	printf("Now, x = %d and y = %d.\n\n", x, y);
}
