/*
 * File: ex9-12-main.c
 * Driver for ex9-12.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
 * File: ex9-12.c
 * Function: pathname
 * Purpose: retrieve the filename and the directory
 * Inputs: pathname (parameters)
 * Returns: 1 if pathname correct (at least one /); 0 otherwise
 * Modifies: fileName and dirName (parameters). 
 *  It allocates memory for these names.
 * Error checking: returns 0 if error
 * Sample call:
 * char *fileName;
 * char *dirName;
 *   if(pathname("/c/archive/ex1.c", &fileName, &dirName)) ... ;
 * Note: the client is responsible for deallocating memory for names
 */
int pathname(const char *path, char **fileName, char **dirName);

/* 
 * Main program tests the above function 
 * The user can enter a pathname and see the filename and a directory name
 * To terminate the program, the user enters q
 */
int main() { 
	char *path;
	char *fname;
	char *dir;

	if((path = calloc(101, sizeof(char))) == NULL) {
		fprintf(stderr, "calloc failed\n");
		return EXIT_FAILURE;
	}

	while(1) {
		printf("enter pathname (no more than 100 character long), q to terminate:\n");
		if(fgets(path, 100, stdin) == NULL) { /* didn't read anything */
			fprintf(stderr, "didn't read anything\n");
			return EXIT_FAILURE;
		}

		if(path[0] == 'q')		
			break;
		path[strlen(path)-1] = '\0'; /* kill end of line */
		if(pathname(path, &fname, &dir) == 1) {
			printf("for pathname %s file is %s and directory is %s\n",
				path, fname, dir);
               		free(fname);
         		free(dir);
       		} else printf("incorrect path\n");
	}

	return EXIT_SUCCESS;
}

