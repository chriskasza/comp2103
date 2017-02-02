/*
 * File: x7-17.c
 * function to output Pascal triangle, and a simple program to test it.
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Function:  factorial
 * Purpose:   to find n factorial defined as the product n * (n-1) * (n-2) *...*1
 * Inputs:    integer n
 * Returns:   the factorial product of n; 0 if n < 0
 * Modifies:  --
 * Error checking: return 0 if n < 0 
 */
int factorial(int n) {
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;
	return n * factorial(n - 1);
}

/*
 * Function:  combination
 * Purpose:   to find the number of combinations of r values
 * Inputs:    integers n and r
 * Returns:   the number of combinations of r values selected from n values;
 *				  0 upon error
 * Modifies:  --
 * Error checking:  if n<r, 0 is returned
 */
int combination(int n, int r) {
	
	if(n < r) /* error checking */
		return 0;

	return factorial(n) / (factorial(r) * factorial(n - r));
}

/*
 * Function:  pascalTriangle
 * Purpose:   to print the Pascal triangle
 * Inputs:    integer n
 * Returns:   --
 * Modifies:  --
 * Error checking:  --
 */
void pascalTriangle(int n) {
	int i, j;

	for(i = 1; i <= n; i++) {
           for(j = 0; j < i + 1; j++) 
              printf("%d ", combination(i, j));
           printf("\n");
       }
}

int main() {
	int n;

	while( 1 ){

		/* get user input */
		printf("Enter the number of lines of the Pascal triangle to be printed OR 0 to quit: ");

		if(scanf("%d", &n) != 1) {
			fprintf(stderr, "Incorrect input, exiting\n");
			return EXIT_FAILURE;
		}
		
		if(n == 0) {
			printf("Done reading \n");
			return EXIT_SUCCESS;		}

		pascalTriangle( n );
	}

}
