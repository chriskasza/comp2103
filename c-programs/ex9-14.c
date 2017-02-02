#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*
 * File: ex9-14.c
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
int pathname(const char *path, char **fileName, char **dirName) {
	char *first;
	char *second;
	char *aux;
	char *pathCopy;
	char *white = "/";   
	int pathLength = strlen(path); /* length of the entire path */

	if(path[0] != '/')  /* doesn't start with '/' */
		return 0;
	if(pathLength == 1) /* the path consists of a single '/' */
		return 0;
	if(path[pathLength-1] == '/')  /* the path ends with '/' */
		return 0;
	/* make a local copy */
	if((pathCopy = malloc((pathLength+1)*sizeof(char))) == NULL)
		return 0;
	strcpy(pathCopy, path);

#define RETURN(i)   {free(pathCopy); return(i); }	
	first = NULL;	
	aux = second = strtok(pathCopy, white); 
	while(aux != NULL) {
		first = second;
		second = aux;
		aux = strtok(NULL, white);
	}

	if(strcmp(first, second) == 0) {   /* single "/" */
		if((*fileName = calloc(strlen(second)+1, sizeof(char))) == NULL ||
			(*dirName = calloc(2, sizeof(char))) == NULL)
				return 0;
		strcpy(*fileName, second);
		strcpy(*dirName, "/");
		RETURN(1);
	}
	
	if((*fileName = calloc(strlen(second) + 1, sizeof(char))) == NULL)
		RETURN(0);
        if((*dirName = calloc(strlen(first) + 1, sizeof(char))) == NULL) {
		free(fileName);
		RETURN(0);
	}
	/* copy filename */
	strcpy(*fileName, second);
	/* copy directory */
	strcpy(*dirName, first);
	RETURN(1);
}
