/*
 * File: ex9-10.c
 * Reads number of lines from standard input until an
 * empty line is encountered and then outputs the longest line.
 * I assume that the longest line cannot be longer than 80 characters.  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
     const int MAX = 81;
     char *longest;
     char *current;
     int  curLen, lonLen;

	if((current = calloc(MAX, sizeof(char))) == NULL || 
		(longest = calloc(MAX, sizeof(char))) == NULL) {
			fprintf(stderr, "calloc failed\n");
			return EXIT_FAILURE;
	}
		 
	printf("Enter lines, to terminate enter an empty line\n");
	if(fgets(longest, MAX-1, stdin) == NULL) { /* get first line */
		fprintf(stderr, "first call to fgets failed\n");
		return EXIT_FAILURE;
	}
  
	lonLen = strlen(longest);   

	while(fgets(current, MAX-1, stdin) != NULL && (curLen = strlen(current)) > 1)
		if (curLen > lonLen) { 
			strcpy(longest, current);
			lonLen = curLen;
	}
	printf("the longest line is:\n");
	puts(longest);

	return EXIT_SUCCESS;
}
