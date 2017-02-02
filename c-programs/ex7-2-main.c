/* 
 * File: ex7-2-main.c
 * Driver for digits from ex7-2.c and from ex7-21.c
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Function: digits
 * Purpose: compute the number of digits in the integer n
 * Inputs: n (parameter)
 * Returns: number of digits in n
 * Error checking: returns 0 if n is not positive
 * Sample call: i = digits(123);  
 *       i gets the value 3 
 */
int digits(int n);

/* 
 * File: ex7-21.c
 * Function: Rdigits
 * Purpose: compute the number of digits in the integer n
 *  (recursive solution)
 * Inputs: n (parameter)
 * Returns: number of digits in n
 * Modifies: Nothing
 * Error checking: Does nothing if n is not positive
 * Sample call:
 *    i = Rdigits(123);   
 *        i gets the value 3 
 */
int Rdigits(int n);

int main() {
	int n;

	printf("Testing function digits(n)\n");

	while(1) {
		printf("Enter n, <0 or invalid integer to terminate ");
		if(scanf("%d", &n) != 1 || n <= 0) 
			break;
		printf("Number of digits in %d is %d\n", n, digits(n));
			 
	}

	printf("Testing function recursive digits(n)\n");
	while(1) {
		printf("Enter n, <0 or invalid integer to terminate ");
		if(scanf("%d", &n) != 1 || n <= 0) 
			break;
		printf("Number of digits in %d is %d\n", n, Rdigits(n));
			 
	}
	return EXIT_SUCCESS;

}

