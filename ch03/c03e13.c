/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	ch03ex13.c
 *
 * Calculate area of rectangle.
 * Request length of two sides from user.
 */
#include <stdio.h>
#include <math.h>

int main() {
	int width;
	int length;
	int area;

	printf("Calculate area of a rectangle.\n");
	printf("Enter the size of the width and length as whole numbers:\n");
	if(scanf("%d%d", &width, &length) != 2) {
		printf("Sorry, I didn't see two integers. Quitting.\n");
	} else {
		area = width * length;
		printf("The corresponding integer value is %d\n", area);
	}
}
