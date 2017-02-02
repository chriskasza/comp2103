/*
 * File: ex9-5.c
 * Reads a single word of at most 10 characters
 * and counts the number of lower case letters
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
     char *s;	/* to store a word */
     char *p;   /* to traverse */
     int count = 0;  /* number of lowercase letters */

	if((s = calloc(11, sizeof(char))) == NULL) {
		fprintf(stderr, "calloc failed\n");
		return EXIT_FAILURE;
	}
	printf("Enter a single word of at most 10 characters\n");
	if(scanf("%10s", s) != 1) {
		fprintf(stderr, "invalid string\n");
		return EXIT_FAILURE;
	}

	for(p = s; *p; p++)
		if(islower(*p))
			count++;

	printf("%s contains %d lowercase letters\n", s, count);

	return EXIT_SUCCESS;
}
