/*
 * File: x11-21list.c
 * The implementation file for the module that implements lists of 
 * homogenous objects.
 * Each element of the list contains three integers.
 * Operations:  a constructor
 *       a destructor
 *       the reading of integers stored in a file
 *       the writing of contents of list to a file
 *       the appending of a new integer to the end of the list
 *       the removing of the first element from the list
 *       the displaying of the i-th element
 *       a destructor
*/


#include <stdlib.h>
#include <stdio.h>
#include "x11-21list.h"

#define NUM_ELE 		(3)

typedef struct{
	EleType *block;
	int currentSize;
	int maxSize;
} List;


/*** PRIVATE VARIABLES ********************/
static  List list_ = {NULL,0,0};
static  int init_ = 0;


/*** FUNCTION DEFINITIONS ****************/

/*
 * Function: constructList
 * Purpose:  to initialize a list with values in a text file
 * Inputs:   maxSize
 * Returns:  1 is successful; 0 otherwise
 * Modifies: creates memory for the list
 * Error checking:  checks the result of memory call; ensures list is not
 *          already initialized
 */
int constructList( int maxSize ){
	if( init_ )
		return 0;

	if( (list_.block = (EleType *)calloc( maxSize * NUM_ELE, sizeof( EleType))) == NULL)
		return 0;

	init_ = 1;
	list_.maxSize = maxSize * NUM_ELE;
	list_.currentSize = 0;

	return 1;
}

/*
 * Function: readFile
 * Purpose:  to read values from a file and store them in the list
 * Inputs:   name, The text file must contain only integer values,
 *             seperated by whitespace
 * Returns:  1 is successful; 0 otherwise
 * Modifies: initializes the memory in the list
 * Error checking:  checks the result of read operations; ensures list is
 *          already initialized
 */
int readFile( const char *name ){

	FILE *f;
	int pos = 1;

	if( !init_)
		return 0;

	if( (f = fopen(name, "r")) == NULL)
		return 0;

	while(1){
		if( list_.currentSize+2 >= list_.maxSize ){ /* size exceeded */
			fclose(f);
			return 0;
		}
		pos = list_.currentSize + 1;
		if( fscanf( f, "%d%d%d", &list_.block[ NUM_ELE*(pos-1) ],
			&list_.block[ NUM_ELE*(pos-1)+1 ], &list_.block[ NUM_ELE*(pos-1)+2 ] ) != 3){
			if( !feof(f)){
				fclose(f);
				return 0;
			}
			break; /* done reading */
		}

		list_.currentSize++;
	}

	fclose(f);	
	return 1;
}

/*
 * Function: writeFile
 * Purpose:  to write the contents of the list to the file
 * Inputs:   name
 * Returns:  1 is successful; 0 otherwise
 * Modifies: creates text file
 * Error checking:  ensures list is initialized
 */
int writeFile( const char *name ){
	int i;
	FILE *f;

	if( !init_)
		return 0;

	if( (f = fopen(name, "w")) == NULL)
		return 0;

	for(i = 0; i < list_.currentSize; i++){
		fprintf(f, "%d %d %d\n", list_.block[NUM_ELE*i], 
			list_.block[ NUM_ELE*i+1], list_.block[NUM_ELE*i+2]);
	}
			
	fclose(f);
	return 1;
}

/*
 * Function: appendEle
 * Purpose:  to add an element at the end of the list
 * Inputs:   the three integers representing a new element
 * Returns:  1 is successful; 0 otherwise
 * Modifies: the list
 * Error checking:  ensures list is initialized and not full
 */
int appendEle( EleType newEle1, EleType newEle2, EleType newEle3 ){
	if( !init_ || list_.currentSize + NUM_ELE > list_.maxSize )
		return 0;

	list_.block[ NUM_ELE*list_.currentSize ] = newEle1;
	list_.block[ NUM_ELE*list_.currentSize + 1  ] = newEle2;
	list_.block[ NUM_ELE*list_.currentSize + 2 ] = newEle3;

	list_.currentSize ++;

	return 1;
}

/*
 * Function: removeFirstEle
 * Purpose:  to remove the first element from the list
 * Inputs:   --
 * Returns:  1 is successful; 0 otherwise
 * Modifies: the list
 * Error checking:  ensures list is initialized and not empty
 */
int removeFirstEle( ){

	int i;

	if( !init_ || list_.currentSize <= 0)
           return 0;

	for(i = 3; i < list_.currentSize * NUM_ELE; i++)
	 	list_.block[i-NUM_ELE ] = list_.block[i];

        list_.currentSize--;

        return 1;
}

/*
 * Function: showEle
 * Purpose:  to show the i'th element
 * Inputs:   pos
 * Returns:  --
 * Modifies: --
 * Error checking:  ensures list is initialized and pos is correct
 */
void showEle( int pos ){

	if( !init_ || pos <= 0 || pos > list_.currentSize){
		fprintf(stderr, "Bad position given\n");
		return;
	}
	
	printf("%d %d %d \n", list_.block[NUM_ELE*(pos-1)],
		list_.block[ NUM_ELE * (pos-1)+1], list_.block[NUM_ELE*(pos-1) +2]);
}

/*
 * Function: destructList
 * Purpose:  to free memory occupied by the list
 * Inputs:   --
 * Returns:  1 if ssuccessful; 0 otherwise
 * Modifies:  the internal state of module
 * Error checking:  ensures list is initialized
 */
int destructList (){
	if( !init_)
		return 0;

	free( list_.block);
	list_.currentSize = list_.maxSize = 0;

	return 1;	
}
