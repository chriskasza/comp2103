#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/*
 * File: ex9-8.c
 * Function: comptext
 * Purpose: compare two text files fname1 and fname2, line by line
 * Inputs: fname1, fname2, max (parameters)
 * Returns: 1 if identical, 0 if error or not identical
 * Modifies: nothing
 * Error checking: considers only first max characters in each line
 * Sample call:
 *    if(compText("a.dat", "b.dat", 80)  == 1) ...
 */
int comptext(const char *fname1, const char *fname2, const int max) {     
	char *line1;
	char *line2;
	FILE *f1;
	FILE *f2;
	int c;
	
        if( (f1 = fopen(fname1, "r")) == NULL || (f2 = fopen(fname2, "r")) == NULL )
          	return 0;
	if((line1 = calloc(max,sizeof(char))) == NULL)
		return 0;
	if((line2 = calloc(max,sizeof(char))) == NULL) {
		free(line1);
		return 0;
	}

	for(c = 0; fgets(line1, max, f1) != NULL; c++)
          if(fgets(line2, max, f2) == NULL || strcmp(line1, line2) != 0)
                   	return 0;
        if(fclose(f1) == EOF) {
                fclose(f2);
		return 0;
        }
        if(fclose(f2) == EOF)
             return 0;
	return 1;
}
