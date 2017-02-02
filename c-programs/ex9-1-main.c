/* 
 * File: ex9-1-main.c
 * Driver for ex9-1.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * File: ex9-1.c
 * Function: modify
 * Purpose: convert the first character of the input string to the upper case
 * Inputs: s (parameter)
 * Returns: void
 * Modifies: the first character of s
 * Error checking:none
 * Sample call:
 *    modify(s)  
 * where s represents "hi".
 * As a result s represents "Hi"
 */
void modify(char *s);


int main() {
	char *s;
	const int S = 10;

	if((s = malloc(S+1)) == NULL) {
		fprintf(stderr, "malloc failed\n");
		return EXIT_FAILURE;
	}
	
	printf("Testing function modify\n");
	printf("enter a string that starts with a lower case letter\n");
	if(scanf("%s", s) != 1) {
		fprintf(stderr, "invalid string\n");
		return EXIT_FAILURE;
	}
	modify(s);
	printf("Modified string is:%s\n", s);
	return EXIT_SUCCESS;

}
