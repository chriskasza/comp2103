/* 
 * File: ex9-3-main.c
 * Driver for ex9-3.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern char* strdup(const char*);

/*
 * File: ex9-3.c
 * Function: modify
 * Purpose: return through the second parameter
 * 	a copy of input string passed as the first parameter
 *      with the first letter converted to the upper case
 * Inputs: s (parameter)
 * Returns: nothing
 * Modifies: the second parameter: allocates memory and sets it to
 *	the copy of the first parameter with the first letter
 *	changed to the upper case.
 * Error checking: does not do anything if parameter is NULL
 * Sample call:
 *    modify(s, &s1); 
 * where s represents "hi".
 * As a result s1 represents "Hi"
 */
void modify(const char *s, char **news);

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
	modify(s, &t);
	printf("Original string %s, modified string is:%s\n", s, t);
	
	return EXIT_SUCCESS;

}
