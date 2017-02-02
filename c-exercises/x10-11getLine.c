#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "x10-11getLine.h"

#undef DEB
#define BUF_SIZE 5

/*
 * File: x10-11getLine.c
 * Function: getLine
 * Purpose: read from file a line of unlimited length using a single dynamic allocation
 * Inputs: FILE in (parameter)
 * The client is responsible for opening and closing this file.
 * Returns: pointer to the memory block that stores the line (through parameter)
 *  The client is responsible for deallocating this memory
 *  Through function returns 1 if a line has been read, 0 on error, and EOF on eof
 * Modifies: file
 * Error checking: returns 0 if fails
 * Sample call:
 *    char *p;
 *    FILE *f;
 *    ... open f ..
 *    if(getLine(f, &p) == 1)
 *       printf("line is %s\n", p);
 *
 */

      
int getLine(FILE *in, char **result) {

  char buf[BUF_SIZE];
  int c;	/* used to read characters */
  int i;	/* auxiliary variable */
  int base;	
  static int size_ = 0; /* used to accumulate the size of the line */

  /* try to read up to BUF_SIZE characters, stop on eoln and eof */
  for (i = 0; i < BUF_SIZE; i++) {

      c = fgetc(in); 

      if(c == EOF) {	/* eof or error */

			if(feof(in)) { /* end-of-file rather than error */
				if(i == 0 && size_ == 0) /* nothing read */
					return EOF;
				break; 
			}
			else /* error */ {
				size_ = 0;
				return 0;
			}
		}

      if (c == '\n') 
			break;
	
      buf[i] = c;
	}
 
  // increment the number of bytes
#ifdef DEB
{
   int j;

   printf("Debug mode: printing intermediate buffer  > ");
   for(j=0;j< i;j++)
      printf("%c", buf[j]);
	printf("\n");
}
#endif

  size_ += i;
  /* Recurse, when the recursion bottoms out, allocate the master buffer */
  if (c != EOF && c != '\n') {
 	if(getLine(in,result) == 0) {
		size_ = 0;
		return 0;
	}
  } else {
    if((*result = calloc((size_+1),sizeof(char))) == NULL) {
		size_ = 0;
		return 0;
    }
    /* store the terminating \0 */
    (*result)[size_] = '\0';

  }
  /* Copy buf into the appropriate location */
  base = size_ - i ;
  memcpy(*result + base, buf, i);
#ifdef DEB
{
	printf("Debug mode: printing final buffer  > " );
   printf("%s\n", *result + base );
}
#endif


  size_ -= i;
  return 1;
}
