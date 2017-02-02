/* 
 * File: ex8-3-main.c
 * Driver for fileSize from ex8-3.c
 */

#include <stdio.h>
#include <stdlib.h>

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
long fileSize(const char *filename);


int main() {
	char filename[FILENAME_MAX];
	long size;

	printf("filename: ");
	scanf("%s",filename);
	
	if((size = fileSize(filename)) == EOF)
		printf("%s doesn't exist\n", filename);
	else printf("file %s is of size %ld\n", filename, size);

	return EXIT_SUCCESS;

}
