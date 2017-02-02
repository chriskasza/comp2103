/*
 * File: x7-9.c
 * findSum() function and a simple program to test it.
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Function:  findSum
 * Purpose:   to find the sum of all integers between n and m
 * Inputs: 	  two integers n and m
 * Returns:   the sum of all the integers between n and m (inclusive)
 * Modifies:  --
 * Error checking: none
 * Assumes: that n <= m
 */
int findSum(int n, int m) {
   int i;
   int sum = 0;

   for(i = n; i <= m; i++)
      sum += i;

   return sum;	
}

int main() {
   int x, y;

   while( 1 ){
	/* read in the data */
	printf("Enter two numbers: x y (x<=y) OR 0 0  to quit: ");

	if( scanf("%d%d", &x, &y) != 2 || x > y) {
		fprintf(stderr, "Incorrect input, exiting\n");
		return EXIT_FAILURE;
	}
		
	if(x == 0 && y == 0) {
		printf("Done reading \n");
		return EXIT_SUCCESS;
	}

	printf("The sum of integers between x=%d and y=%d is %d\n", x, y, findSum(x,y));
   }

}

