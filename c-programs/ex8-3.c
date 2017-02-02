/* 
 * File: ex8-3.c
 * Function: fileSize
 * Purpose:  Computes the length of a file
 * Inputs: filename (parameter)
 * Returns: file length or -1L if fails
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *    if(fileSize("ex8-3.c") == -1L)
 *      .. error      
 */
#include <stdio.h>
long fileSize(const char *filename) { 
      FILE *f;
      long size;

      if((f = fopen(filename, "r")) == NULL)
		return -1L;

      if(fseek(f, 0L, SEEK_END) == 0) {
		size = ftell(f);
		if(fclose(f) == EOF)
			return -1L;
		return size;
      }	
      /* if here, fseek failed */
      fclose(f);
      return -1L;
}

