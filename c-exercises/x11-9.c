/*
 * File: x11-9.c
 * The file containing the application to build a table of integers,
 *	and remove all odd integers from the table
 * A main program is provided to test the function
 *
 * Operations: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EVEN( X )		((X) % 2 == 0)
#define MAX	100

typedef int IntType[MAX];

typedef struct {
	IntType integers;
	int counter;
} IntegersT;

/**** Local Variables ***********/

static IntegersT data_;

/*
 * Function:  killOdds
 * Purpose:   to remove all odd integers from the table
 * Inputs:    -- (operates on global table )
 * Returns:   --
 * Modifies:  removes all odd integers from the table
 * Error checking:  --
 */
static void KillOdds(){
	IntType temp;
	int i;
      int size = 0;

	/* 
       * we will make a copy of the array, copy all even numbers to it, and then 
	 * copy this back to integers ; the other option is to "shift all elements
       * down each time we "kill" an odd number
	*/

	for( i = 0; i < data_.counter; i++){
		if( EVEN( data_.integers[i] ))
			temp[size++] = data_.integers[i];	
	}

	/* now copy back */
	for(i = 0; i < size; i++)
		data_.integers[i] = temp[i];

	data_.counter = size;
}

/*
 * Function: PrintData
 * Purpose: to print all data
*/
static void PrintData(){
	int i;

	for(i = 0; i < data_.counter; i++)
		printf("%d\t", data_.integers[i]);
	printf("\n");
}


/*
 * Function: main
*/
int main(int argc, char *argv[]){
	int num;
	FILE *f;

	if( argc < 2){
            fprintf(stderr, "Usage: programName fileName\n");
            return EXIT_FAILURE;
        }

	if( (f = fopen(argv[1], "r")) == NULL){
	    fprintf(stderr, "Could not open the input file\n");
            return EXIT_FAILURE;
	}

	/* intialize the counter */
	data_.counter = 0;

	/* read in the data */
	num = 0;
	while(1){
           if( fscanf(f,"%d", &data_.integers[ num++ ]) != 1){
              if( feof(f) )
                 break;
              else {
		   fprintf( stderr, "Read error from file\n");
	   	   return EXIT_FAILURE;
		}
	   }
	   data_.counter = num;
	   if( num >= MAX ){
		printf("Size limitations exceeded - breaking\n");
		break;
	   }
	}

	if( data_.counter == 0){
		printf("The file was empty\n");
		return EXIT_SUCCESS;
	}

	PrintData();
	KillOdds();

	if( data_.counter  > 0){
		printf("killed odd values: new array is >\n");
		PrintData();
	}
	else printf("The array is now empty \n");

	return EXIT_SUCCESS;	
}

