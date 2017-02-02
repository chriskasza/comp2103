/*
 * File: x7-21.c
 * the sum() and sumRec() functions and a simple program to test 
 * them.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Function:  sum
 * Purpose:   to find integer n for which the sum 1 + 1/2 + 1/3 + ... 1/n
 *				  is greater then the input integer m
 * Inputs:    integer m
 * Returns:   the integer n as defined above; -1 upon error
 * Modifies:  --
 * Error checking:  if m is less or equal to zero, -1 is returned
 */
int sum(int m) {
	int n;
	double sum;

	if(m <= 0) /* error checking */
		return -1;

        for(n = 1, sum = 1.0; sum <= m; n++)
           sum += 1.0 / n;
        return n;
}


/*
 * Function:  sumRec
 * Purpose:   to find integer m for which  sum 1 + 1/2 + 1/3 + ... 1/n
 *				  is greater then the input integer m; do this recursively
 * Inputs:    integer m
 * Returns:   the integer n as defined above; -1 upon error
 * Modifies:  --
 * Error checking: if m is less or equal to zero, -1 is returned 
 */
int sumRec(int m) {
	double sum = 1.0;
	int n = 1;

	if(m == 1)
		return n; /* base case */

	n += sumRec(m - 1);
	sum += 1.0 / n;

	if(sum > m) /* done */
         return n;
}

int main() {
	int n;

	while(1) {
		/* get user input */
		printf("Enter a number OR 0 to quit: ");

		if(scanf("%d", &n) != 1) {
			fprintf(stderr, "Incorrect input, exiting\n");
			return EXIT_FAILURE;
		}
		
		if(n == 0) {
		      printf("Done reading \n");
		      return EXIT_SUCCESS;
		}

		printf("The smallest n such that the sum is greater than input is: %d \n",										
                       sumRec(n));
		printf("The smallest n such that the sum is greater than input is: %d \n", 
				sum(n));
	}

}
