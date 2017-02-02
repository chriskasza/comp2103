/*
 * File: ex8-13-ops1-main.c
 * Application of the module Ops1 to search and sort a block of memory
 */

#include <stdlib.h>
#include <stdio.h>
#include "ex8-13-ops1.h"
#include "ex8-enum.h"

/* User-defined comparison of double values */
int doubleComp(const Element_Ops1 *x, const Element_Ops1 *y) {
	return *x == *y;
}

#define SIZE 3 /* elements in the block */
#define nextElement_Ops1  (Element_Ops1*)nextElement_Enum()

int main() {
	double d;
	double *dp;

	if(construct_Ops1(SIZE, doubleComp) == 0)
		return EXIT_FAILURE;

	(void)setSize_Ops1(SIZE);
	/* read all values */
	reset_Enum();
	while(hasMoreElements_Enum())  {
		printf("enter a double value: ");
		if(scanf("%lf", &d) != 1)
		  return EXIT_FAILURE;
            if((dp = nextElement_Ops1) == NULL) {
	        fprintf(stderr, "enumeration failed\n");
		  return EXIT_FAILURE;
            }
            *dp = d;
	}

 	/* show all values using an enumeration */
	reset_Enum();
	while(hasMoreElements_Enum()) 
		printf("%f\n", *(nextElement_Ops1));

	/* sort */
	sort_Ops1();

 	/* show again all values using an enumeration */
	reset_Enum();
	while(hasMoreElements_Enum()) 
		printf("%f\n", *(nextElement_Ops1));

	if(destruct_Ops1() == 0)
		return EXIT_FAILURE; 
 
 	return EXIT_SUCCESS;
}

