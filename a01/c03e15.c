/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	c03e15.c
 *
 * Read up to five characters from STDIN 
 * and output characters two and four to STDOUT.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Function to determine what type of character was entered and 
 * print finding to STDOUT.
 */
int printCharMsg(int i, char c) {
	switch(c) {
	case '\n':	
		printf("Character #%d is [NEWLINE].\n", i); 
		break;
	case '\t':	
		printf("Character #%d is [TAB].\n", i); 
		break;
	case ' ' :
		printf("Character #%d is [SPACE].\n", i); 
		break;
	default  :
		printf("Character #%d is %c.\n", i, c); 
		break;
	}

	return EXIT_SUCCESS;
}

/*
 * Request a string from user.
 */	
int main() {
	const int LIMIT = 5;
	char c, c2, c4;
	int i;

	printf("Please enter a string with five characters.\n");
	printf("The second and fourth characters will be identified.\n");
	for(i = 1; i <= LIMIT; i++) {
		if((c = getchar()) == EOF) { 
			break;
		}

		if(i == 2) {
			c2 = c;
		} else if (i == 4) {
			c4 = c;
		}
	}

	printf("\n");
	if(c2 != 0) {
		printCharMsg(2, c2);
	}

	if(c4 != 0) {
		printCharMsg(4, c4);
	}
	
	printf("\nWhat happens if the third character is the EOF character?\n");
	printf("\tIf the EOF character is entered as the third character, the for "
			"loop will exit and the fourth character will not be read.  In UNIX "
			"the EOF character is ^D; however, I was not able to reproduce this "
			"behaviour with gcc 5.3.1 on Fedora 23.\n\n");
	return EXIT_SUCCESS;
}
