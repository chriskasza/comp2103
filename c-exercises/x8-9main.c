/*
 * File: x8-9main.c
 * Application of the module compare, to compare two blocks of memory
 * the program prompts user for values to initialize both blocks,
 *	and calls the compare function
 * The program uses a block of doubles, and a block of pointers to doubles
 * to test the function.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "x8-3mem.h"
#include "x8-9com.h"

#define SIZE1		(100)
#define SIZE2		(100)

/*
 * Function:  memoryCleanUp
 * Purpose:  cleans up any residual memory
 * Inputs:   the blocks to be released
 * Returns:  --
 */
static void memoryCleanUp( double **firstBlock, int size1, double *secondBlock){
	int i;

   for(i = 0; i < size1; i++)
      free( firstBlock[i]);

   free(*firstBlock);
   free(secondBlock);
}


/*
 * Function:  readInSize
 * Purpose:   to get the size of a block from the user
 * Inputs:    reference to size, and max allowable size
 * Returns:   --
 */
static void readInSize(int *size , int maxSize) {
	int s;

   printf("enter the number of double values to be contained in the block (less than %d) > ",
            maxSize);
	
   while(1){
	if(scanf("%d", &s ) == 1) {
		if(s <= 0 || s >= maxSize)
			printf("Size must be > 0 and < %d; try again... \n", maxSize);
		else break;
	}
	while( getchar() != '\n') /* skip remaining characters */
              ;
   }

   while( getchar() != '\n') /* skip remaining characters */
		;
  *size = s;
}


/*
 * Function:  compareDouble
 * Purpose:   to compare two doubles (function required by compareGen )
 * Inputs:    the two elements
 * Returns:   0 if elements are equal; 1 if the first is smaller; -1 otherwise
 */      
static int compareDouble(const void *elem1, const void *elem2) {
	double *d1, *d2;

	d1 = (double *) elem1;
	d2 = (double *) elem2;

	if( *d1 == *d2 ) return 0;
	if( *d1 < *d2 ) return 1;
	return -1;
}

/*
 * Function:  compareDouble
 * Purpose:   to compare two pointers to doubles (function required by compareGen )
 * Inputs:    the pointers to the two elements
 * Returns:   0 if elements are equal; 1 if the first is larger; -1 otherwise
 */      
static int compareDoublePtr(const void *elem1, const void *elem2) {
   double **d1, **d2;

   d1 = (double **) elem1;
   d2 = (double **) elem2;

   if(*d1[0] == *d2[0]) return 0;
   if( *d1[0] < *d2[0] ) return 1;
   return -1;
}


/*
 * Function:  copyData
 * Purpose:   to copy the data in block to the block of pointers
 * Returns:   --
 */      
static void copyData(double **blockOfPtrs, double *block, int size) {
	int i;

	for(i = 0; i < size; i++)
		*(blockOfPtrs[i]) = block[i];
}

/*
 * Function:  allocBlockOfPtrs
 * Purpose:   to allocate a block of pointers to doubles
 * Inputs:    the size of the block
 * Returns:   a pointer to the block of pointers to doubles; NULL if an
 *				  error occured
 */      
static double **allocBlockOfPtrs(int size) {
	double **blockOfPtrs;
	int i;

   if((blockOfPtrs = (double **)calloc( size, sizeof(double *))) == NULL) {
         fprintf(stderr, "Memory attempt failed ");
         return NULL;
   }

   /* initialize the second block */
   for(i = 0; i < size; i++)
      if((blockOfPtrs[i] = (double *)calloc(1, sizeof( double ))) == NULL) {
         fprintf(stderr, "Memory attempt failed; garbages left\n");
         return NULL;
      }
   return blockOfPtrs;
}


int main() {
	double *block1, *block2;
	double **blockOfPtrs1, **blockOfPtrs2;
	int res, numRead1, numRead2;
	int size1, size2;

	/* allocate memory for blocks of doubles */
	if((block1 = (double *)calloc(SIZE1, sizeof(double))) == NULL) {
		fprintf(stderr, "Memory attempt failed\n");
		return EXIT_FAILURE;	
	}
	if((block2 = (double *)calloc( SIZE2, sizeof(double))) == NULL) {
               fprintf(stderr, "Memory attempt failed ");
               free(block1);
               return EXIT_FAILURE;
        }

	/* read in the values for the first block, use function from ex 8-3 */
	readInSize(&size1, SIZE1);
	numRead1 = get(block1, size1);	

	if(numRead1 != size1) {
            printf("Error in reading: exiting\n");
	    free(block1);
	    free(block2);
            return EXIT_FAILURE;
	}
       printf("Read %d values \n", numRead1);

	readInSize( &size2, SIZE2 );
	numRead2 = get(block2, size2);	
	if(numRead2 == 0) {
		printf("Error in reading: exiting \n");
		free( block1 ); 
		free( block2 );
		return EXIT_FAILURE;
	}
	
	if(numRead2 != size2)
           printf("Error in reading; only read %d values \n", numRead2);
        else printf("Read %d values\n", numRead2);

	/* now test the compare function */
	res = compareGen(sizeof(double), (void *)block1, size1,
			 (void *)block2, size2, compareDouble);

	printf("Testing with doubles \n");
	if(res == 0) printf("The blocks are equal \n");
           else if(res == 1) 
               printf("The first block is lexicographically smaller \n");
	else printf("The first block is lexicographically bigger \n");
	
	/* now allocate block of pointers to doubles */
	blockOfPtrs1 = allocBlockOfPtrs(size1);
	blockOfPtrs2 = allocBlockOfPtrs(size2);

	/* copy data over from block1, block2); */
	copyData(blockOfPtrs1, block1, size1);
	copyData(blockOfPtrs2, block2, size2);

	/* now test genCompare with block of pointers */
	res = compareGen(sizeof(double *), (void *)blockOfPtrs1, size1,
          (void *)blockOfPtrs2, size2, compareDoublePtr);

       printf("Testing with pointers to double \n");
       if(res == 0) printf("The blocks are equal \n");
       else if(res == 1) 
         printf("The first block is lexicographically smaller\n");
       else printf("The first block is lexicographically bigger\n");

	memoryCleanUp(blockOfPtrs1, size1, block1);
	memoryCleanUp(blockOfPtrs2, size2, block2);


	return EXIT_SUCCESS;
}

