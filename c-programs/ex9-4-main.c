/* 
 * File: ex9-4-main.c
 * Driver for ex9-4.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * File: ex9-4.c
 * Function: isNumber
 * Purpose: check if a string represents an integer value
 *    in decimal or hexadecimal 
 * Inputs: s (parameter)
 * Returns: 1 if s represents a number, 0 otherwise
 * Modifies: nothing
 * Error checking: does not do anything if parameter is NULL
 * Sample call:
 *    if(isNumber("0xFa")) ...
 */
int isNumber(const char *s);

int main() {
	char *s;
	const int S = 10;

	if((s = malloc(S+1)) == NULL) {
		fprintf(stderr, "malloc failed\n");
		return EXIT_FAILURE;
	}
	
	printf("Testing function isNumber\n");
	while(1) {
		printf("enter a string that represents a (hexa)decimal number\n");
		printf("Enter Q to terminate\n");
		if(scanf("%s", s) != 1) {
			fprintf(stderr, "invalid string\n");
			return EXIT_FAILURE;
		}
		if(strcmp(s, "Q") == 0)
			return EXIT_SUCCESS;

		printf("%s is %s a valid number\n", s,
			isNumber(s) ? "" : "not");
	}
	return EXIT_SUCCESS;

}
