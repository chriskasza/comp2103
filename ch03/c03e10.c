/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	ch03ex10.c
 *
 * convert inches to cm
 */
#include <stdio.h>

int main() {
	float inch;
	float cm;

	printf("Enter the inch value: ");
	if(scanf("%f", &inch) != 1) {
		printf("That was not a valid integer value. Quitting.\n");
	} else {
		cm = inch * 2.2;
		printf("The equivalent length in cm is %5.2f\n", cm);
	}
}
