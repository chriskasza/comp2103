/*
 * File: x9-9.c
 * File contains sstr function and a simple program to test it.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BIG_SIZE		(30)
#define SMALL_SIZE	        (3)
#define NEW_STR	"hello"

/*
 * Function:  sstr
 * Purpose:   overwrites the string s with the value of NEW_STR; it returns
 *					the new string through its parameter
 * Inputs:   pointer to pointer to string str
 * Returns:  1 on success, 0 if memory allocation fails
 * Modifies:  string str
 * Error checking:  checks to make sure memory allocation was successful
 */
int sstr(char **s) {
	int newLen = strlen(NEW_STR);
	int oldLen = strlen(*s);
	
	if(newLen <= oldLen) { /* string is long enough to hold new string */
		strcpy(*s, NEW_STR);	
		return 1;
	}

	/* otherwise we have to allocate memory */
	free(*s);
	
	if((*s = calloc(newLen + 1, sizeof(char ))) == NULL)
		return 0;

	strcpy(*s, NEW_STR);
	return 1;
}

/*
 * Purpose: to skip all remaining characters until end of line is encountered
*/
void skipLine() {
	while( getchar () != '\n' ) 
			;
}

int main() {
      char *input1;
      char *input2;

	/* allocate memory for the string , remember to add one for the '\0' char !*/
	if((input1 = calloc(BIG_SIZE + 1, sizeof(char ))) == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return EXIT_FAILURE;
	}

	if((input2 = calloc(SMALL_SIZE + 1, sizeof(char ))) == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
	    free(input1);
            return EXIT_FAILURE;
      }

	/* initialize the strings */
	strncpy(input1, "jack", BIG_SIZE);
	strncpy(input2, "awk", SMALL_SIZE);

	printf("The original strings are %s %s\n", input1, input2);

	/* call the function */
	sstr(&input1);
	sstr(&input2);

	printf("The new strings are %s %s\n", input1, input2);

	free(input1);
	free(input2);

	return EXIT_SUCCESS;
}
