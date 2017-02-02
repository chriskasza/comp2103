/*
 * File: ex4-9.c
 * Reads at most 20 characters and prints the number of blanks,
 *  tabs, asterisks, and lowercase chars
 */
#include <stdio.h>
#include <stdlib.h>
int main() { 
	const int LIMIT = 20;
	int i, c;
	int cblank = 0;
	int ctabs  = 0; 
	int cstars = 0;
	int clower = 0;

	printf("Enter at most 20 characters\n");
	for(i = 01; i <= LIMIT; i++) {

		if((c = getchar()) == EOF)
			break;

		switch (c) {

		case ' ' : cblank++; 
			   break;

		case '\t': ctabs++;  
			   break;

		case '*' : cstars++;  
 			   break;

	        default  : if(c >= 'a' && c <= 'z')
                            clower++;
                           break;
		}
	}

	printf("\nNumber of blanks\t%d\n", cblank);
	printf("Number of  tabs\t%d\n", ctabs);
	printf("Number of asterisks\t%d\n", cstars);
	printf("Number of lower case letters\t%d\n", clower);

	return EXIT_SUCCESS;
}
