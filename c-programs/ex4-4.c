/*
 * File: ex4-4.c
 * Reads characters until "." and outputs the ASCII value
 *   of the largest input character.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	const char SENTINEL = '.';
	int 	aux;
	int 	maxi = 0;

	printf("Enter characters, enter . to terminate\n");
	while(1) {
	   if((aux = getchar()) == EOF || aux == SENTINEL)
		break;

	   if(aux > maxi)
		maxi = aux;
	}

	printf("The largest ASCII value: %d\n", maxi);

	return EXIT_SUCCESS;
}
