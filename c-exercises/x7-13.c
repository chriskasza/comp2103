#include <stdio.h>
#include <stdlib.h>

/*
 * Function: f
 * Purpose:  to find the fibonnacci sequence
 * Inputs:   integer n
 * Returns:  the fibonnacci sum
 * Modifies: --
 * Error checking:  --
 */
int f(int n) {
	return  n < 2 ? 1 : f(n - 1) + f(n - 2);
}

int main() {
	printf("The value is %d \n", f(14));
	return EXIT_SUCCESS;
}
