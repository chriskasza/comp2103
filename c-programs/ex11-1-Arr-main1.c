/*
 * File: ex11-1-main1.c
 * Application of the module Arr that implements dynamic arrays of characters
 * The menu driven program to test Arr (using char)
 */
#include <stdlib.h>
#include <stdio.h>
#include "ex11-1-Arr.h"

/* Displays available commands */
void help() {
    printf("This is a dynamic array of char values. You can create up to 5 arrays\n");
    printf("and up to 5 enumerations. Enter\n");
    printf("\th for help\n");
    printf("\tc to construct an array\n");
    printf("\tg to get the element of the array\n");
    printf("\ts to set an element of the array\n");
    printf("\tl to show the length of the array\n");
    printf("\te to construct an enumeration\n");
    printf("\tm to test if there are more elements in enumeration\n");
    printf("\tn to get the next element in enumeration\n");
    printf("\tp to prints all elements using enumeration\n");
    printf("\tk to destruct the enumeration\n");
    printf("\td to destruct the array\n");
    printf("\tq to quit\n");
}

#define SKIP      while(getchar() != '\n');
#define SIZE 5

/* reads in user's command and executes the corresponding command */
void menu() {
	int c, i;
	int number;  /* initial size */
	size_t size = sizeof(char);
	void *p;
	char pc;
	Abstract_Arr col[SIZE];	/* five arrays */
	Abstract_Enumeration enu[SIZE];	/* five arrays */

  for(i = 0; i < SIZE; i++) {  /* initialize the arrays */
	col[i] = NULL;
	enu[i] = NULL;
  }
  printf("Testing this program remember that we do not check\n whether or nor arrays have been constructed\n");
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
	        printf("Enter array # (between 0 and 4) and initial size of the array:\n");
		if(scanf("%d%d", &i, &number) != 2 || i < 0 || i > 4) {
			fprintf(stderr, "invalid values\n");
			SKIP
			break;
		}
		SKIP
		if((col[i] = construct_Arr(size, number)) == NULL)
			fprintf(stderr, "can't initialize\n");
		break;
	case 'g':
	case 'G':
		printf("Enter array # (between 0 and 4) and the element index:\n");
		if(scanf("%d%d", &i, &number) != 2 || i < 0 || i > 4) {
			fprintf(stderr, "invalid values\n");
			SKIP
			break;
		}
		SKIP
		p = get_Arr(col[i], number);
		pc = *((char*)p);
		printf("%d-th array[%d] = %c (int value = %d)\n", i, number, pc, pc);
		break;
	case 's':
	case 'S':
		printf("Enter array # (between 0 and 4), the element index, \nsingle space and the value to be set:\n");
		if(scanf("%d%d%*c%c", &i, &number, &pc) != 3 || i < 0 || i > 4) {
			fprintf(stderr, "invalid values\n");
			SKIP
			break;
		}
		SKIP
		set_Arr(col[i], &pc, number);
		break;
	case 'l':
	case 'L': 
		printf("Enter array # (between 0 and 4): ");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		printf("The length of the array is %d\n", length_Arr(col[i]));
		break;
	case 'e':
	case 'E':
		printf("Enter enumeration # (between 0 and 4) \nand the array (to be enumerated) #: \n");
		if(scanf("%d%d", &i, &number) != 2 || i < 0 || i > 4 || number < 0 || number > 4) {
			fprintf(stderr, "invalid values\n");
			SKIP
			break;
		}
		SKIP
		if((enu[i] = construct_Enumeration(col[number])) == NULL)
			fprintf(stderr, "can't initialize\n");
		break;
	case 'm':
	case 'M':
		printf("Enter enumeration # (between 0 and 4): ");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		printf("There is %s more elements in the enumeration\n",
			hasMoreElements_Enumeration(enu[i]) ? "" : "not");
		break;
	case 'n':
	case 'N': 
		printf("Enter enumeration # (between 0 and 4): ");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		if((p = nextElement_Enumeration(enu[i])) == NULL) {
			printf("There are no more elements in the enumeration %d\n", i);
			break;
		}
		printf("The next element in the enumeration is %c (integer value %d)\n",
			 *((char*)p), *((char*)p) );
		break;
	case 'p':
	case 'P': 
		printf("Enter enumeration # (between 0 and 4): ");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		printf("Printing using an enumeration %d\n", i);
		while(hasMoreElements_Enumeration(enu[i])) 
			printf("%c\n", *(char*)nextElement_Enumeration(enu[i]));
		break;
	case 'k':
	case 'K':
		printf("Enter enumeration # (between 0 and 4): ");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		free(enu[i]);
		enu[i] = NULL;
		break;
	case 'd':
	case 'D':
		printf("Enter array # (between 0 and 4): ");
		if(scanf("%d", &i) != 1 || i < 0 || i > 4) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		destruct_Arr(&col[i]);
		col[i] = NULL;
		break;
	case 'q':
	case 'Q': 
		return;
	default :
             fprintf(stderr, "\nUnknown command\n");
             break;
    }

 }
}

int main() {
   menu();
   return EXIT_SUCCESS;
}

