/*
 * File: ex10-6-main1.c
 * Application of the module Arr that implements dynamic arrays of characters
 * The menu driven program to test Arr
 */
#include <stdlib.h>
#include <stdio.h>
#include "ex10-6-Arr.h"

/* Displays available commands */
void help() {
    printf("This is a dynamic array of chars. Enter\n");
    printf("\th for help\n");
    printf("\tc to construct an arrayn\n");
    printf("\tg to get the element of the array\n");
    printf("\ts to set an element of the array\n");
    printf("\te to show the length of the array\n");
    printf("\td to destruct the array\n");
    printf("\tQ to quit\n");
}

#define SKIP      while(getchar() != '\n');

/* reads in user's command and executes the corresponding command */
void menu() {
	int c;
	int number;  /* initial size */
	Element_Arr i;

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
	        printf("initial size of the array: ");
		if(scanf("%d", &number) != 1) {
			fprintf(stderr, "invalid number\n");
			SKIP
			break;
		}
		SKIP
		if(construct_Arr(number) == 0)
			fprintf(stderr, "can't initialize\n");
		break;
	case 'g':
	case 'G':
		printf("Specify which element of the array you want to get: ");
		if(scanf("%d", &number) != 1) {
			fprintf(stderr, "invalid number\n");
			SKIP
			break;
		}
		SKIP
		i = get_Arr(number);
		printf("array[%d] = %c (int value = %d)\n", number, i, i);
		break;
	case 's':
	case 'S':
		printf("Specify which element of the array you want to set: ");
		if(scanf("%d", &number) != 1) {
			fprintf(stderr, "invalid number\n");
			SKIP
			break;
		}
		SKIP

		printf("Specify the value: ");
		if(scanf("%c", &i) != 1) {
			fprintf(stderr, "invalid value\n");
			SKIP
			break;
		}
		SKIP
		set_Arr(i, number);
		break;
	case 'e':
	case 'E': 
		printf("The length of the array is %d\n", length_Arr());
		break;
	case 'q':
	case 'Q': 
	        destruct_Arr();
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
