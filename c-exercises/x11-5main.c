/*
 * File: x11-5main.c
 * Application of the module that operates on integer data
 * The application intializes the module using the command-line-provided
 * text file, and allows the user to enter values, that are then tested
 * using the divisible function exported by the module
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "x11-5.h"

int main(int argc, char *argv[]){
	DataTP data;
	int factor, num;

	if( argc < 2 ){
		fprintf(stderr, "Usage: programName fileName\n");
		return EXIT_FAILURE;
	}

	/* initialize the data structure */
	if( initialize( argv[1] ) == 0 ){
		fprintf(stderr, "Initialization failed\n");
		return EXIT_FAILURE;
	}

	printf("Printing data :\n");
	showData();
	
	/* get the data ptr */
	data = getDataPtr();
	if( data == NULL ){
		fprintf(stderr, "Could not get the data pointer - exiting\n");	
		return EXIT_FAILURE;
	}

	/* get factors from user and use them to test the divisible function */
	while(1){
            printf("Enter a factor, <0 to finish> > ");
            if( scanf("%d", &factor) != 1){
               fprintf(stderr, "Incorrect output\n");
               return EXIT_FAILURE;
            }
            if( factor == 0 ){
               printf("Done\n");
               break;
            }
	    if( (num = divisible( data, factor)) == -1)
		printf("Error in getting factor\n");
           else printf("The number of values divisible by %d is %d\n", 
			factor, num);
	}

	freeData();

	return EXIT_SUCCESS;	
}

