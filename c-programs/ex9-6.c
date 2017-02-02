/*
 * File: ex9-6.c
 * Shows output to a string. It reads in an integer
   value and outputs a string of characters derived from this value
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
     int i;
     char *s;

	printf("Enter integer value\n");
	if(scanf("%d", &i) != 1) {
		fprintf(stderr, "invalid integer\n");
		return EXIT_FAILURE;
	}
	if((s = calloc(21,sizeof(char))) == NULL) {
		fprintf(stderr, "invalid string\n");
		return EXIT_FAILURE;
	}

	if(sprintf(s, "The input value was %d", i) == EOF) {
		fprintf(stderr, "sprintf failed\n");
		return EXIT_FAILURE;
	}
	printf("The converted string is: %s\n", s);

	return EXIT_SUCCESS;
}
