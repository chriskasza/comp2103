/*
 * File: x9-5.c
 * File contains function fill and a simple program to test it.
*/

#include <stdlib.h>
#include <stdio.h>

#define SIZE		(1000)


/*
 * Function:  fill
 * Purpose:   initializes n bytes of memory with the value pat, starting at address n
 * Inputs:    string s,  address n, nd character pat
 * Returns:   --
 * Modifies:  the string s
 * Error checking:  makes sure n is valid
 */
void fill(char *s, int n, char pat) {

	char *p;
        char *end;

	if(n <= 0) 
		return;

	/* make sure you don't fall off the end of the string */
	end = s + n < s + strlen(s) ? s + n : s + strlen(s);

	for(p = s; p < end; p++)
	   *p = pat;
}

/*
 * Purpose: to skip all remaining characters until end of line is encountered
 */
void skipLine() {
	while( getchar () != '\n' ) 
		;
}

int main() {
	char pat;
        char *input;
	int len, pos, n;

	/* allocate memory for the string */
	if((input = calloc(SIZE, sizeof(char))) == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return EXIT_FAILURE;
	}

	/* read in string and call function */
	while(1) {
		printf("Enter a string; a single word (q to quit) > ");
		if(scanf("%s", input) != 1) {
			fprintf(stderr, "invalid input\n");
			skipLine();
			continue;
		}
		len = strlen( input );
		if(len == 1 && input[0] == 'q') { /* done reading */
			printf("Done.\n");
			break;
		}
		printf("Enter a pattern character (q to quit) > ");
		skipLine();
                if(scanf("%c", &pat) != 1 ){
                  fprintf(stderr, "invalid input\n");
		  skipLine();
                  continue;
                }

		skipLine();
		/* call the function */
		while(1) {
			printf("Enter a position in the string AND number of pat characters > ");
			if(scanf("%d%d", &pos, &n) != 2) {
				printf("Invalid input, try again > ");
				skipLine();
			}
			else break;
		}
		skipLine();
		if(pos <= 0 || pos >= strlen(input))
			printf("You entered an invalid position\n");
		else {
			fill(input+pos, n, pat);
			printf("The new string is %s\n", input);
		}
	}	

	free(input);
	return EXIT_SUCCESS;
}
