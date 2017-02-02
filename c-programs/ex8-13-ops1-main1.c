/*
 * File: ex8-13-ops1-main1.c
 * Application of the module Ops1 to search and sort a collection
 * The menu driven program to test Ops1 with enumerations
 */
#include <stdlib.h>
#include <stdio.h>
#include "ex8-13-ops1.h"
#include "ex8-enum.h"
#include <string.h>

/* User-defined callback function */
int doubleComp(const Element_Ops1 *x, const Element_Ops1 *y) {
	if(*x < *y)
		return -1;
	if(*x > *y)
		return 1;
	return 0;
}

/* User-defined sorting function 
 * Insertion sort; here defined for double values
 */
void doubleSort(Element_Ops1 *base, size_t nElements) {
	int i, j;
	Element_Ops1 temp;

	for(i = 1; i < nElements; i++) {
		temp = base[i];
		for(j = i-1; j >= 0 && base[j] > temp; j--)
			base[j+1] = base[j];
		base[j+1] = temp;
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
    printf("\ty to set the size of the collection\n");
    printf("\te to reset an enumeration\n");
    printf("\tm to test if there are more elements in enumeration\n");
    printf("\tn to get the next element in enumeration\n");
    printf("\tp to prints all elements using enumeration\n");
    printf("\td to destruct collection\n");
    printf("\tQ to quit\n");
}

#define SKIP      while(getchar() != '\n');

/* reads in user's command and executes the corresponding command */
void menu() {
	int c;
	int number;  /* of elements */
	char filename[FILENAME_MAX];
	double value;
	int res;
	Element_Ops1 *p;

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
		if(construct_Ops1(number, doubleComp) == 0)
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
		if(read_Ops1(filename, &number) == 0)
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
		if(search_Ops1(&value, &res) == 0) 
			fprintf(stderr, "search failed\n");
        	else printf("%f was %s found\n", value, res == 1 ? "" : "not");
                break;
	case 'o':
	case 'O':  
	        if(sort_Ops1() == 0)
			fprintf(stderr, "sort failed to execute\n");
		break;
	case 'd':
	case 'D': 
	       if(destruct_Ops1() == 0)
		   fprintf(stderr, "failed to destruct\n");
		break;
	case 'e':
	case 'E':
		reset_Enum();
		break;
	case 'm':
	case 'M':
		printf("There is %s more elements in the enumeration\n",
			hasMoreElements_Enum() ? "" : "not");
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
	        if(setSort_Ops1(doubleSort) == 0)
			fprintf(stderr, "setSort failed to execute\n");
		break;
	case 'y':
	case 'Y':
		printf("Enter new size of the collection ");
		if(scanf("%d", &number) != 1) {
			fprintf(stderr, "invalid size\n");
			SKIP
			break;
		}
		SKIP
	        if((number = setSize_Ops1(number)) == 0)
			fprintf(stderr, "setSize failed to execute\n");
		else printf("new size is %d\n", number);
		break;
	case 'q':
	case 'Q': 
	       if(destruct_Ops1() == 0)
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
