/*
 * File: x9-1.c
 * the charInString() function and a simple program to test it.
 */

#include <stdlib.h>
#include <stdio.h>

#define SIZE		(1000)

/*
 * Function:  charInString
 * Purpose:   returns the character at position pos in the string s
 * Inputs:    the string s, the position pos, and the reference to 
 *			the character to be intialized with the value of the
 *			character at position pos in the string
 * Returns:   1 if success, 0 if pos is an illegal position in the string
 * Modifies:  the value of the character value
 * Error checking:  checks to make sure pos is valid
 */
int charInString(const char *s, int pos, char *value ) {

	int len = strlen(s);

	if(pos <= 0 || pos >= len)
		return 0; /* invalid position */

	*value = s[pos];
	return 1;
}

/*
 * Purpose: to skip all remaining characters until end of line
 */
void skipLine() {
	while(getchar () != '\n') 
		;
}

int main() {
	char ch;
        char* input;
	int len, pos;

	/* allocate memory for the string */
	if((input = calloc(SIZE, sizeof(char ))) == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return EXIT_FAILURE;
	}

	/* read in string and call function */
	while(1) {
		printf("Enter a string; a single word (q to quit) > ");
		if(scanf("%s", input) != 1) {
			fprintf(stderr, "invalid input\n");
			free(input);
			return EXIT_FAILURE;
		}
		len = strlen(input);
		if(len == 1 && input[0] == 'q') { /* done reading */
			printf("Done.\n");
			break;
		}

		/* call the function */
		while(1){
			printf("Enter a position in the string > ");
			if( scanf("%d", &pos) != 1){
				printf("Invalid input, try again > ");
				skipLine();
			}
			else break;
		}

		skipLine();
		if(charInString(input, pos, &ch) == 0 )
			printf("You entered an invalid number! \n");
		else printf("The character at position %d is %c\n", pos, ch);
	}	

	free(input);
	return EXIT_SUCCESS;
}

