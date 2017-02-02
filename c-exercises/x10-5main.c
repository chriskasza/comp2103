/*
 * File: x10-5main.c
 * Application of the module create to create dynamic array
*/

#include <stdio.h>
#include <stdlib.h>
#include "x10-5create.h"

#define SIZE	(10)

/*
 * Purpose: local helper function, prints the contents of the array arr
*/
static void printArr( double arr[], int size ){
	int i;

	for( i = 0; i < size; i++ )
		printf("%.2f ", arr[i] );

	printf("\n");
}

int main(){
	double *arr;
	int result;
	
	/* create the array */
	create( SIZE, &arr, &result );
	if( result == 0 ){ /* error */
		fprintf(stderr, "Create failed\n");
		return EXIT_FAILURE;
	}
	
	/* otherwise print array : should be initialized to 0 */
	printf("creation successful, printing the array >\n ");
	printArr( arr, SIZE );

	return EXIT_SUCCESS;	
}

