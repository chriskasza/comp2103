/*
 * File: ex9-7.c
 * Reads two strings representing double value
 *   and outputs the sum of these values.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
     char *s;
     char *r;
     double sd;
     double sr;

	if( (s = calloc(21,sizeof(char))) == NULL ||
		(r = calloc(21,sizeof(char))) == NULL ) {
			fprintf(stderr, "calloc failed\n");
			return EXIT_FAILURE;
	}
	printf("Enter two strings representing double values ");
	printf("each on a separate line\n");
	if(scanf("%s", s) != 1 || scanf("%s", r) != 1) {
		fprintf(stderr, "invalid string\n");
		return EXIT_FAILURE;
	}
	if(sscanf(s, "%lf", &sd) != 1 || sscanf(r, "%lf", &sr) != 1) {
		fprintf(stderr, "sscanf failed\n");
		return EXIT_FAILURE;
	}

	printf("The sum of %f and %f is %f\n", sd, sr, sd + sr);

	return EXIT_SUCCESS;
}
