#include <stddef.h>
/*
 * File: ex8-92.c
 * Function: searchGen
 * Purpose: search a block of memory of a given size for a given value
 * Generic solution that uses a function compare()
 * Inputs: block, size, value and compare() (parameters)
 * Returns: 1 if found, 0 otherwise
 * Modifies: nothing
 * Error checking: Returns 0 if block is NULL
 */
int searchGen(const void *block, size_t size, void *value, size_t elsize,
  int (*compare)(const void *, const void *));

/* Two sample compare functions; to compare doubles and integers */
int doubleComp(const void *x, const void *y) {
  return *(double*)x == *(double*)y;
}

int intComp(const void *x, const void *y) {
  return *(int*)x == *(int*)y;
}

#include <stdlib.h>
#include <stdio.h>
#define SIZE 3
/* 
 * Sample application
 * Create a block of SIZE doubles, read in values from the standard 
 *   input and then check if 1.0 was one of the values entered.
 * Then repeat this process for integers.
 */
int main() {
	double *b;
	double v;
	int i;
	int *bi;
	int vi;

	if((b = malloc(SIZE*sizeof(double))) == NULL) {
		  fprintf(stderr, "malloc failed\n");
		  return EXIT_FAILURE;
	}
	printf("Enter %d double values:", SIZE);
	for(i = 0; i < SIZE; i++) 
		if(scanf("%lf", &b[i]) == 0) {
		        fprintf(stderr, "invalid double\n");
			free (b);
			return EXIT_FAILURE; 
		}
	printf("Enter a double value to search for ");
	if(scanf("%lf", &v) != 1) {
		fprintf(stderr, "invalid double\n");
		free(b);
		return EXIT_FAILURE;
	}
	printf("%f was %s one of the values\n", 
   		v, searchGen(b, SIZE, &v, sizeof(double), doubleComp)
                        ? "" : "not");

	free(b);
	b = NULL;

	if((bi = malloc(SIZE*sizeof(int))) == NULL) {
		fprintf(stderr, "malloc failed\n");	
  		return 0;
	}

	printf("Enter three integer values:");
	for(i = 0; i < SIZE; i++) 
		if(scanf("%d", &bi[i]) == 0) {
			fprintf(stderr, "invalid integer\n");
			free (b);
			return EXIT_FAILURE; 
		}

	printf("Enter a integer value to search for ");
	if(scanf("%d", &vi) != 1) {
		fprintf(stderr, "invalid integer\n");
		free(bi);
		return EXIT_FAILURE;
	}
	printf("%d was %s one of the values\n", 
   		vi, searchGen(bi, SIZE, &vi, sizeof(int), intComp)
                 ? "" : "not");

	return EXIT_SUCCESS;
}

#define VOID(targ,size) ((void *)(((char *)(targ)) + (size)))
int searchGen(const void *block, size_t size, void *value, size_t elsize,
  	int (*compare)(const void *, const void *)) {
  void *p;

  if(block == NULL)
	return 0;

  for(p = (void*)block; p < VOID(block, size*elsize); p = VOID(p, elsize))
	if(compare(p, value))
		return 1;
  
  return 0;
}
