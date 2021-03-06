/*
 * File: ex8-11-ops-main1.c
 * Application of the module Ops to search and sort a collection
 * The menu driven program to test Ops with enumerations
 */
#include <stdlib.h>
#include <stdio.h>
#include "ex8-11-ops.h"
#include "ex8-enum.h"
#include <string.h>

#define VOID(targ,size) ((void *)(((char *)(targ)) + (size)))
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

/* User-defined sorting function 
 * Bubblesort; here defined for double values
 */
void doubleSort(void *base, size_t nElements, size_t elSize, 
	    int (*compare)(const void *, const void *)) {
	int i, j;
	double temp;

	for(i = 0; i < nElements - 1; i++) 
		for(j = nElements - 1; j > i; j--)
			if((*compare)(VOID(base, j*elSize), VOID(base, (j-1)*elSize)) < 0) {
				memcpy(&temp, VOID(base, j*elSize), elSize);
				memcpy(VOID(base, j*elSize), VOID(base, (j-1)*elSize), elSize);
				memcpy(VOID(base, (j-1)*elSize), &temp, elSize);
			}
}

/* Displays available commands */
void help() {
    printf("This is a collection of double value. Enter\n");
    printf("\th for help\n");
    printf("\tc to construct collection\n");
    printf("\tr to read collection from a file\n");
    printf("\ts to search collection\n");
    printf("\to to sort collection\n");
    printf("\tx to set another sort routine\n");
    printf("\te to reset an enumeration\n");
    printf("\tm to test if there are more elements in enumeration\n");
    printf("\tn to get the next element in enumeration\n");
    printf("\tp to print all elements using enumeration\n");
    printf("\td to destruct collection\n");
    printf("\tQ to quit\n");
}

#define SKIP      while(getchar() != '\n');

/* reads in user's command and executes the corresponding command */
void menu() {
	int c;
	size_t elSize = sizeof(double);
	int number;  /* of elements */
	char filename[FILENAME_MAX];
	double value;
	int res;
	void *p;

  while(1) {
	printf("> (h for help): ");
	c = getchar();
	SKIP

	switch (c) {
	case 'h':
	case 'H':
		help();
                break;
	case 'c':
	case 'C':	
	        printf("number of elements: ");
		if(scanf("%d", &number) != 1) {
			fprintf(stderr, "invalid number\n");
			SKIP
			break;
		}
		SKIP
		if(construct_Ops(number, elSize, doubleComp) == 0)
			fprintf(stderr, "can't initialize\n");
		break;
	case 'r':
	case 'R':
		printf("filename: ");
		if(scanf("%s", filename) != 1) {
			SKIP
			fprintf(stderr, "can't read\n");
			break;
		}
		SKIP
		if(read_Ops(filename, &number) == 0)
			fprintf(stderr, "can't read file %s\n", filename);
		else printf("%d values read from the file\n", number);
		break;
	case 's':
	case 'S':
		printf("Enter a value to search for: ");
		if(scanf("%lf", &value) != 1) {
			fprintf(stderr, "invalid double\n");
			SKIP
			break;
		}
		SKIP
		if(search_Ops(&value, &res) == 0) 
			fprintf(stderr, "search failed\n");
        	else printf("%f was %s found\n", value, res == 1 ? "" : "not");
                break;
	case 'o':
	case 'O':  
	        if(sort_Ops() == 0)
			fprintf(stderr, "sort failed to execute\n");
		break;
	case 'd':
	case 'D': 
	       if(destruct_Ops() == 0)
		   fprintf(stderr, "failed to destruct\n");
		break;
	case 'e':
	case 'E':
		reset_Enum();
		break;
	case 'm':
	case 'M':
		printf("There is %s more elements in the enumeration\n",
			hasMoreElements_Enum() ? "" : "no");
		break;
	case 'n':
	case 'N': 
		if((p = nextElement_Enum()) == NULL) {
			printf("There are no more elements in the enumeration\n");
			break;
		}
		printf("The next element in the enumeration is %f\n",
			 *((double*)p));
		break;
	case 'p':
	case 'P': 
		printf("Printing using an enumeration\n");
		reset_Enum();
		while(hasMoreElements_Enum()) 
			printf("%f\n", *(double*)nextElement_Enum());
		break;
	case 'x':
	case 'X':
		printf("setting another sort routine\n");
	        if(setSort_Ops(doubleSort) == 0)
			fprintf(stderr, "setSort failed to execute\n");
		break;
	case 'q':
	case 'Q': 
	       if(destruct_Ops() == 0)
		   fprintf(stderr, "failed to destruct\n");
		return;
	default :
             fprintf(stderr, "\nunknown command\n");
             break;
    }

 }
}

int main() {
   menu();
   return EXIT_SUCCESS;
}

