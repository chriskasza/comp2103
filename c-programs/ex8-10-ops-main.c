/*
 * File: ex8-10-ops-main.c
 * Application of the module Ops to search and sort a collection
 * The program assumes that there is a binary file "8-10.dat" 
 *   containing double values
 * It constructs a collection to hold double values, and reads in from 
 *   the file values to be stored in this collection. Then it asks the 
 *   user for the value and searches the collection looking
 *   for this value.
 */
#include <stdlib.h>
#include <stdio.h>
#include "ex8-10-ops.h"

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

#define SIZE 10  /* 10 elements in the collection */
int main() {

	size_t elements;
	double value;
	int result;

	if(construct_Ops(SIZE, sizeof(double), doubleComp) == 0) {
	        fprintf(stderr, "failed to construct\n");
		return EXIT_FAILURE;
	}
	if(read_Ops("8-10.dat", &elements) == 0)  {
	        fprintf(stderr, "failed to read data\n");
		return EXIT_FAILURE;
	}
	printf("%d values read from the file\n", elements);

	printf("Enter a value to search for: ");
	if(scanf("%lf", &value) != 1) {
		fprintf(stderr, "invalid double\n");
		return EXIT_FAILURE;
	}
	if(search_Ops(&value, &result) == 0) 
		fprintf(stderr, "search failed\n");
        else printf("%f was %s found\n", value, result == 1 ? "" : "not");
	
	if(destruct_Ops() == 0) {
	        fprintf(stderr, "failed to destruct\n");
		return EXIT_FAILURE; 
	}
       
	return EXIT_SUCCESS;
}

