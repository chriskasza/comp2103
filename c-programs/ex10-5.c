#include <stdio.h>
#include <stdlib.h>

/*
 * File: ex10-5.c
 * Function: find
 * Purpose: find the largest value in a two-dimensional array
 * Inputs: array x and its size in the first dimension (parameters)
 * Returns:  the largest value
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *  double z[20][30];
 *  ... initialize z ...
 *    double max = find(z, 30);
 */
#define SIZE 5
double find(const double x[][SIZE], int n) {
   int i, j;
   double max = x[0][0];

   for (i = 0; i < n; i++)
      for(j = 0; j < SIZE; j++)
         if(max < x[i][j])
			max = x[i][j];
   
   return max;
}

double z[][SIZE] = {
	{0, 1, 2, 3, 4 },
	{0.0, 1.1, 2.2, 3.3, 4.4}
};

int main() {
	int i, j;

	printf("Input array:\n");
	for(i = 0; i < 2; i++)  /* for each row */  {
  		for(j = 0; j < 5; j++)   /* for each column */
			printf("z[%d][%d] = %3.1f ", i, j, z[i][j]);
   		putchar('\n');
	}
 	
	printf("The largest value is of this array %3.1f\n", find(z, 2));
	printf("The largest value in the first row is %3.1f\n", find(z,1));
	return EXIT_SUCCESS;
}

