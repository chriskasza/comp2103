/*
 * File: ex8-2.c
 * Reads in two integers and then prints the
 * larger of the two values using two auxiliary pointers.  
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
     int i, j;
     int *pi = &i;
     int *pj = &j;

     printf("Enter two integer values\n");
     if(scanf("%d%d", &i, &j) != 2) {
	fprintf(stderr, "invalid integers\n");
	return EXIT_FAILURE;
     }
     printf("%d\n", *pi > *pj ? *pi : *pj);

     return EXIT_SUCCESS;
}
