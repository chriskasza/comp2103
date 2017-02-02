#include <stdio.h>
#include <stdlib.h>

/*
 * File: ex10-2.c
 * Return the largest and the smallest value in a double array
 * Inputs: array arr and its size (parameter)
 * Returns: max and min (through parameters)
 *  1 if successful, 0 otherwise
 * Modifies: nothing
 * Error checking: returns 0 if array is NULL or size not positive
 * Sample call:
 *    double x[10; 
 *    double max, min;
 *    ... initialize x
 *    if(maxMin(x, 10, &max, &min)) ...
 *
 */
int maxMin(const double arr[], int size, double *max, double *min) {
	double *p;

	if(arr == NULL || size <= 0)
		return 0;
	
	for(*max = *min = arr[0], p = (double*)arr + 1; p < arr+size; p++) {
		if(*max < *p)
			*max = *p;
		if(*min > *p)
			*min = *p;
	}
	return 1;
}

/* application of the above function */
#define SIZE 5 
int main() {
   double x[SIZE];
   double max, min;
   int i;

   printf("enter %d double values:\n", SIZE);
   for(i = 0; i < SIZE; i++) {
	if(scanf("%lf", &x[i]) != 1) {
		fprintf(stderr, "invalid double\n");
		return EXIT_FAILURE;
	}
   }
   if(maxMin(x, SIZE, &max, &min) == 0) {
	fprintf(stderr, "this could not happen\n");
	return EXIT_FAILURE;
   }

   printf("maximum = %f, minimum = %f\n", max, min);
   return EXIT_SUCCESS;
}

