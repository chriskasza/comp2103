/*
 * File: x7-1.c
 * isBetween() function and a test program. The test program
 * prompts the user for input and then calls the function.
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Function: isBetween
 * Purpose:  determines if w is between x and y (inclusive)
 * Inputs:   integers x, y, z
 * Returns:  1 if w is between x and y and 0 otherwise
 * Modifies: --
 * Error checking: --
 */
int isBetween(int x, int y, int w) {
	return w >= x && w <= y;
}

int main() {
	int x, y, z;

	while(1){
		/* get user input */
		printf("Enter three numbers: x y z OR 0 0 0 to quit: ");

		if(scanf("%d%d%d", &x, &y, &z) != 3) {
			fprintf(stderr, "Incorrect input, exiting\n");
			return EXIT_FAILURE;
		}
		
		if(x == 0 && y == 0 && z == 0) {
			printf("Done reading \n");
			return EXIT_SUCCESS;  
		}

		printf("The value z=%d is %s between x=%d and y=%d\n", z,
                  isBetween( x, y, z ) ? "" : "not", x, y);
	}

}
