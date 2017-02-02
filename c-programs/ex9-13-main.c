/*
 * File: ex9-13-main.c
 * Driver for strip() from ex9-13.c
 */

/* File: ex9-13.c
 * Function: strip
 * Purpose: strip leading and trailing characters from a given set
 * Inputs: strings s, and set (parameters)
 * Returns: a copy of s with leading and trailing characters from set removed
 * Modifies: nothing
 * Error checking: returns NULL if memory allocation failed
 * Sample call:
 * char *str;
 * str = strip("   hello how   ", " ");
 * Now str points to "hello how"
 * Note: the client is responsible for deallocating memory for str
 */
char *strip(const char *s, const char *set);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *kopy;
	const char *white = " \t\n";
	char *set;
	char *s;
	const int Max = 81;
	int i;

	if((s = calloc(Max, sizeof(char))) == NULL) {
		fprintf(stderr, "calloc failed\n");
		return EXIT_FAILURE;
	}
	if((set = calloc(Max, sizeof(char))) == NULL) {
		fprintf(stderr, "calloc failed\n");
		free(s);
		return EXIT_FAILURE;
	}
	while(1) {
		printf("Enter a string (at most 80 characters)\n");
		printf("Enter q to terminate\n");
		if(fgets(s, 80, stdin) == NULL) {
			fprintf(stderr, "end-of-file encountered\n");
			break;
		}
		i = strlen(s);
        	s[i-1] ='\0';  /* remove end-of-line */
		if(strcmp(s, "q") == 0) {
			fprintf(stderr, "terminating\n");
			break;
		}

		printf("Enter a string defining leading and trailing characters\n");
		printf("Enter w to use whitespace characters\n");
		if(fgets(set, 80, stdin) == NULL) {
			fprintf(stderr, "end-of-file encountered\n");
			break;
		}
		i = strlen(set);
		set[i-1] = '\0';

		if((kopy = strip(s, strcmp(set, "w") == 0 ? white : set)) == NULL) {
			fprintf(stderr, "strip() failed\n");
			break;
		}
		printf("new string =%s=\n", kopy);
		free(kopy);
	}
	free(s);
	free(set);

	return EXIT_SUCCESS;
}
 
