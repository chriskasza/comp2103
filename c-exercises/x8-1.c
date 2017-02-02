/*
 * File: x8-1.c
 * the alter() function and a simple program to test it.
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Function: alter
 * Purpose:  to change the values of x to x-y and the value of y to 2
 * Inputs:  two references to double values
 * Returns: --
 * Modifies:  the two incoming double values, as specified above
 * Error checking:  --
 */
void alter(double *x, double *y) {
	*x = *x - *y;
	*y = 2;
}

int main() {
	double x, y;

	while(1) {

		/* get user input */
		printf("Enter two doubles ( 0 0 to quit) > ");

		if(scanf("%lf%lf?", &x, &y) != 2) { /* error */
			fprintf(stderr, "Incorrect input, exiting\n");
			return EXIT_FAILURE;
		}

		/* check to see if user is done */
		if(x == 0.0 && y == 0.0) {
			printf("Done \n");
			return EXIT_SUCCESS;
		}

		/* call alter */
		alter(&x, &y);
		printf("After calling alter, x = %f and y = %f\n", x, y);
	}

}
