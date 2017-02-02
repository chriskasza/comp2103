/*
 * File: ex8-1.c
 * Reads in two integers and then prints
 * the larger of the two values using an auxiliary pointer.  
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
     int i, j, *pi;

     printf("Enter two integer values\n");
     if(scanf("%d%d", &i, &j) != 2) {
	fprintf(stderr, "invalid integers\n");
	return EXIT_FAILURE;
     }
     pi = i > j ? &i : &j;
     printf("%d\n", *pi);

     return EXIT_SUCCESS;
}
