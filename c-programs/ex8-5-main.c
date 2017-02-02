/* 
 * File: ex8-5-main.c
 * Driver for functions from ex8-5.c and ex8-52.c
 */

#include <stdio.h>
#include <stdlib.h>

/* 
 * File: ex8-5.c
 * Function: show
 * Purpose: print characters stored in a memory block, 
 * 	separated by blanks and enclosed by square brackets.
 */
void show(char *);
 
/* 
 * File: ex8-52.c
 * Function: show2
 * Purpose: print characters stored in a memory block, 
 * 	separated by blanks and enclosed by square brackets.
 * Recursive (correct) solution.
 */
void show2(char *); 

int main() {
	char str[20];

	while(1) {
		printf("enter a string, eof to terminate: ");
		if(scanf("%19s", str) == EOF) {
		        fprintf(stderr, "could not read the string\n");
			return EXIT_SUCCESS;
	        }	
		printf("output from show\n");
		show(str);
		printf("output from show2\n");
		show2(str);
	
	}
}
