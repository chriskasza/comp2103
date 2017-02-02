/* 
 * File: ex9-2-main.c
 * Driver for ex9-2.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * File: ex9-2.c
 * Function: modify
 * Purpose: create a copy of input string with the first argument 
 *     converted to the upper case
 * Inputs: s (parameter)
 * Returns: copy of modified s
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *    s1 = modify(s)  
 * where s represents "hi".
 * As a result s1 represents "Hi"
 */
char *modify(const char *s);

int main() {
	char *s;
	char *t;
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
	t = modify(s);
	printf("Original string %s, modified string is:%s\n", s, t);
	
	return EXIT_SUCCESS;

}
