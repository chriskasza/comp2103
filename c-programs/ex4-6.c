/*
 * File: ex4-6.c
 * Uses the for loop and a comma operator to compute the
 *   sum of integers from 1 to 10.
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
	int i, sum;

	for(i = 1, sum = 0; i <= 10; i++, sum += i)
		;
	printf("sum of integers from 1 to 10 = %d\n", sum);

	return EXIT_SUCCESS;
}
