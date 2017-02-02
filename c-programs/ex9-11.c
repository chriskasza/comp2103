/*
 * File: ex9-11.c
 * Reads in a sequence of strings from a file, 
 * stores pointers to these strings in a block of memory
 * sorts the strings using Insertion sort,
 * Finally, outputs sorted strings 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static char **block_;		/* stores a block of strings */
static long lines_;		/* number of lines */
const int LENGTH = 81;		/* max length of each line */

/*
 * Return the number of lines in the file fname
 * Inputs: fname (parameter)
 * Returns: number of lines
 * Modifies: nothing
 * Error checking: returns 0 if error
 * Sample call:
 *    long lo = numberOfLines("test.dat");
 */
extern long numberOfLines(const char *fname);

/*
 * Function: input
 * Purpose: read all lines from the file fname and store them in a block of strings
 *   For each line, at most 80 characters are read.
 * Inputs: file name
 * Returns: 1 if successful, 0 otherwise
 * Modifies: Nothing (for the client). Internally, modifies the block
 * Error checking: return 0 if the file does not exit, or a reading error,
 *	or a file is empty
 * Sample call:
 *  if(input("test.dat") == 1) ... 
 */
int input(const char *fname) {           
     FILE *f;
     long n;
     char *buffer;	/* to store a single line */
     int current;	/* a line may be shorter than 80 characters; current stores its length */

     if((lines_ = numberOfLines(fname)) < 1) 	 /* no lines? */
	return 0;
     if((buffer = calloc(LENGTH, sizeof(char))) == NULL)  /* memory for the buffer */
	return 0;
     if((block_ = calloc(lines_, sizeof(char*))) == NULL)	 {  /*memory for the entire block */
	free(buffer);
	return 0;
    }

     if((f = fopen(fname, "r")) == NULL)  {	/* can't open input file */
	free(buffer);
	free(block_);
	return 0;
    }

     for(n = 0; n < lines_ && fgets(buffer, LENGTH, f) != NULL; n++) { 
         current = strlen(buffer);
         /* fgets stores end-of-line which will be overwritten 
         buffer[current-1] = '\0';  */ 
         /* allocate memory for this line and copy from the buffer */
         if ((block_[n] = calloc(current + 1, sizeof(char))) == NULL) {
	 	/* failed, has to free everything that has been allocated so far */
		free(buffer);
		for(n--; n >= 0; n--)
			free(block_[n]);
		fclose(f);	/* no point in testing if successful */
		free(block_);
                return 0;
         }
         strcpy(block_[n], buffer);
     }

     /* now, buffer is not needed any more */
     free(buffer);
     /*   if(fclose(f) == EOF)  I neglect this error */      
     return 1;
 }

/*
 * Take all lines from the block of strings and store in a file
 * Inputs: file name
 * Returns: 1 if successful, 0 otherwise
 * Modifies: Nothing 
 * Error checking: return 0 if writing error
 * Sample call:
 *  if(output("test.dat") == 1) ... 
 */
int output(const char *fname) {          
	int i;
	FILE *f;

	if((f = fopen(fname, "w")) == NULL)
		return 0;

	for(i = 0; i < lines_; i++) {
		 if(fputs(block_[i], f) == EOF)  /* error */ {
			fclose(f);
		 	return 0;
		}
	}
	if(fclose(f) == EOF)
		return 0;
	return 1;
}

/*
 * Function: insertionSort
 * Purpose: sort a number of strings, using insertion sort
 * Inputs: a block of strings (pointers to char), and the size of the block (global variables)
 * Returns: nothing
 * Modifies: the block
 * Error checking: none
 * Sample call:
 * insertionSort();    
 */
void insertionSort() {
     int i, j;
     char *aux;

     for (i = 1; i < lines_; i++) 
        for (j = i; j > 0 && strcmp(block_[j], block_[j-1]) < 0; j--) {
               aux = block_[j];
               block_[j] = block_[j-1];
               block_[j-1] = aux;
         } 
}

/* Main program tests the above functions */
int main(int argc, char *argv[]) { 
	
	if(argc != 3) {
        	fprintf(stderr, "usage file1 file2\n");
		return EXIT_FAILURE;
	}
	if(input(argv[1]) == 0) {
		fprintf(stderr, "can't open %s or it doesn't have a line\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	insertionSort();

	if(output(argv[2]) == 0) {
        	fprintf(stderr, "can't open %s\n", argv[2]);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

