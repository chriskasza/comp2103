/*
 * File: ex4-7.c
 * Reads two positive integers a and b and
 *  outputs the sum and the product
 *  of odd integers from a (inclusive) to b (exclusive).
 * Error checking: Keep reading when a >= b or a or b is negative.
 *     Aborts if an incorrect integer has been entered 
 */

#include <stdlib.h>
#include <stdio.h>
int main() {
	int i, a, b;
	int sum = 0;
	int product = 1;

	while(1) {
		printf("enter two integers a and b, a < b:");
		if(scanf("%d%d", &a, &b) != 2) {
		    fprintf(stderr, "invalid integer\n");
		    return EXIT_FAILURE;
                }
		if(a > 0 && b > 0 && a < b)
			break;
	}
	/* check if there are any values between a and b */
        if(a%2 == 0 && a+1 == b) { /* if a is even */
            printf("There are no odd values between %d and %d\n", a, b);
            return EXIT_SUCCESS;
        }

        if(a%2 == 0)  /* if a is even, then start from a+1 */
      		a++;

        for(i = a; i < b; product *= i, sum += i, i += 2)
		;

	printf("The sum = %d, the product = %d\n", sum, product);

	return EXIT_SUCCESS;
}
