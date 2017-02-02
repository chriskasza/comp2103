/*
 * File: x9-13.c
 * Program which prints the sum of all arguments in the command line
 *	that are valid integer values. If at least one arg is not an integer,
 * the program prints 0.
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
	int sum , i, j;

	for(sum = 0, i = 1; i < argc; i++)  
           if(sscanf(argv[i], "%d", &j) != 1) {
		sum = 0;
		break;
	   } else sum += j;
	
 	printf("The sum is %d\n", sum);

	return EXIT_SUCCESS;
}
	
