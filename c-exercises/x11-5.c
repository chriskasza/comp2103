#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "x11-5.h"

/*
 * File: x11-5.c
 * The implementation file for the module x11-5 that operates on integer data
 *
 * Operations:  operations to construct and destruct the module
 *              showing the data in the module
 *              getting a constant pointer to data in the module
 *              getting the number of elements from the module that are
 *                divisible by user-provided number
*/

/*** PRIVATE VARIABLES ********************/

static DataTP dataPtr_ = NULL;


/*** FUNCTION DEFINITIONS ****************/

/*
 * Function:  freeData
 * Purpose:   to free the memory occupied by the internal state of the module
 * Inputs:    --
 * Returns:   1 on success, 0 otherwise
 * Modifies:  the internal state of the module
 * Error checking:  ensures the module is initialized
 */
int freeData(){

	if( dataPtr_ == NULL )
		return 0;

	free(dataPtr_->data);
	free(dataPtr_);
	dataPtr_ = NULL;
	return 1;
}

/*
 * Function:  initialize
 * Purpose:   to initialize the memory of the internal state of the module by
 *             reading the data contained in file fname
 * Inputs:    fname; contains integer values
 *                
 * Returns:   1 on success, 0 otherwise
 * Modifies:  the internal state of the module 
 * Error checking:  ensures the module is not initialized
 */
int initialize( const char *fname ){
	FILE *f;
	int  i, numInts, num;

	if( !dataPtr_ ){ /* not yet intialized */
		/* allocate memory for the structure first ! */
		if( (dataPtr_ = (DataTP)calloc(1, sizeof(*dataPtr_))) == NULL)
			return 0;
         } else /* already intialized */
		return 0;
	
	dataPtr_->size = 0;


	if( (f = fopen(fname, "r")) == NULL) {
		free( dataPtr_ );
		return 0;
	}

	/* figure out how much memory to allocate for the data */
	numInts = 0;
	while(1){
		if( fscanf(f,"%d", &num) != 1){
			if( feof(f) )
				break;
			else {
				free( dataPtr_);
				dataPtr_ = NULL;
				fclose( f );
				return 0; /* read error */
			}
		}
		numInts++;
	}


	if( numInts == 0 ){
		dataPtr_->data = NULL;
		fclose( f );
		return 1;
	}
		
	/* now allocate memory for the data */
	if( (dataPtr_->data = (int *)calloc(numInts, sizeof(int))) == NULL){
		free( dataPtr_ );
		fclose( f );
		dataPtr_ = NULL;
		return 0; /* memory allocation failed */
	}

	/* now read in the data */

	/* first reset the file pointer */
	rewind(f);

	i = 0;
	while(1){
		if(fscanf(f,"%d", &dataPtr_->data[ i++ ]) != 1){
			if( feof(f) )
				break;
			else {
				free( dataPtr_->data);
				free( dataPtr_);
				dataPtr_ = NULL;
                                fclose( f );
				return 0; /* read error */
			}
		}
		(dataPtr_->size)++;
	}

	fclose(f);

	return 1;
}

/*
 * Function:  getDataPtr
 * Purpose:   to get a pointer to the block containing the data
 * Inputs:    --
 * Returns:   a pointer to the data
 * Modifies:
 * Error checking:  --
 */
const DataTP getDataPtr(){
	return dataPtr_;
}

/*
 * Function:   divisible
 * Purpose:   returns the number of elements divisible by factor
 * Inputs:    a pointer to data d, factor
 * Returns:   the number of elements divisible by factor; -1 on error
 * Modifies:  --
 * Error checking:  ensures factor != 0 and module is initialized
 */
int divisible( const DataTP d, int factor ){
	int i, numElem;

	if( !dataPtr_ || factor == 0 ) /* error */
		return -1;

	numElem = 0;
	for(i = 0; i < dataPtr_->size; i++)
		if( dataPtr_->data[i] % factor == 0 )
			numElem++;
	return numElem;
}

/*
 * Function:  showData
 * Purpose:  shows the contents of the data memory block
 * Inputs:   --
 * Returns:  --
 * Modifies:  --
 * Error checking:  checks module is initialized
 */
void showData(){
	int i;

	if( !dataPtr_ )
		return;

	for(i = 0; i < dataPtr_->size; i++)
		printf("%d\t", dataPtr_->data[i]);

	printf("\n");
}

