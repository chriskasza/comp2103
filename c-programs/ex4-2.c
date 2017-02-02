/* 
 * File: ex4-2.c
 * Program that reads two integer values, and outputs the
 * maximum of these values.
 * No error checking for valid integer numbers.
 */

#include <stdlib.h>
#include <stdio.h>

int main( ) {
	int i, j;

	/* "Read Two Integers" idiom from Chapter 3. */
	printf("Enter two integers:");
	scanf("%d%d", &i, &j);

	printf("The maximum value of %d and %d is %d\n", 
                         i, j, i > j ? i : j);

	return EXIT_SUCCESS;
}
