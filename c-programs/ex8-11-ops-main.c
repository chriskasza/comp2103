/*
 * File: ex8-11-ops-main.c
 * Application of the module Ops to search and sort a collection
 * 	using enumerations
 */

#include <stdlib.h>
#include <stdio.h>
#include "ex8-11-ops.h"
#include "ex8-enum.h"

/* User-defined callback function */
int doubleComp(const void *x, const void *y) {
	double dx = *(double*)x;
	double dy = *(double*)y;

	if(dx < dy)
		return -1;
	if(dx > dy)
		return 1;
	return 0;
}

#define SIZE 3  /* elements in the block */

int main() {
	size_t elements;
        double d;
        double *dp;

	if(construct_Ops(SIZE, sizeof(double), doubleComp) == 0) {
		fprintf(stderr, "construction failed\n");
		return EXIT_FAILURE;
	}

   	if(read_Ops("8-10.dat", &elements) == 0) {
		fprintf(stderr, "read from %s failed\n", "8-10.dat");
		return EXIT_FAILURE;
	}
	printf("%d values read from the file\n", elements);

 	/* show all values using an enumeration */
	reset_Enum();
	while(hasMoreElements_Enum()) 
		printf("%f\n", *(double*)nextElement_Enum());
	
	/* read SIZE values */
	printf("Enter %d double values\n", SIZE); 	
	setSize_Ops(SIZE);
	reset_Enum();
	while(hasMoreElements_Enum()) {
	    if(scanf("%lf",  &d) != 1) {
		fprintf(stderr, "wrong double\n");
		return EXIT_FAILURE;
            }
            if((dp = (double*)nextElement_Enum()) == NULL) {
		fprintf(stderr, "enumeration failed\n");
		return EXIT_FAILURE;
	    }
            *dp = d;
        } 
 	/* show all values using an enumeration */
	reset_Enum();
	while(hasMoreElements_Enum()) 
		printf("%f\n", *(double*)nextElement_Enum());

	if(destruct_Ops() == 0) {
		fprintf(stderr, "destruction failed\n");
		return EXIT_FAILURE;
	}
 
 	return EXIT_SUCCESS;
}
