#include <stdio.h>
#include <stdlib.h>
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
int pathname(const char *path, char **fileName, char **dirName) {
	const int SEP = '/';
	char *fileP; /* will point to / just before filename */
	char *dirP; /* will point to / just before directory name */
	int fileLength;	/* length of the string filename */
	int dirLength;	/* length of the string directory name */
	int pathLength=strlen(path); /* length of the entire path */
	char *auxP;

	if(path[0] != SEP)  /* doesn't start with '/' */
		return 0;
	if(pathLength == 1) /* the path consists of a single '/' */
		return 0;

	fileP = strrchr(path, SEP);  /* last occurrence of '/' */
printf("len=%d fileP-path = %d fileP =%c (int %d) str=%s\n", pathLength, fileP-path, *fileP, *fileP, fileP);
	if(fileP - path == pathLength - 1)  /* the path ends with '/' */
		return 0;

	dirP = strchr(path, SEP);  /* first occurrence */
	if(dirP == fileP) {   /* single "/" */
  		dirLength = 1;
  		fileLength = pathLength -1;

  		if((*fileName = calloc(fileLength+1,sizeof(char)))== NULL)
			return 0;
  		if((*dirName = calloc(dirLength+1, sizeof(char)))== NULL){
			free(*fileName);
			return 0;
   		}
   		/* copy filename */
   		strcpy(*fileName, fileP+1);
   		strcpy(*dirName, "/");
   		return 1;
	}

	if(strchr(dirP+1, SEP) != fileP)
		while(1) {
			auxP = strchr(dirP+1, SEP);
			if(auxP == fileP)
				break;
			dirP = auxP;
		}

	/* now, fileP points to last '/' and dirP to the previous */
	fileLength = strlen(fileP + 1);
	dirLength = fileP - dirP - 1;
	if((*fileName = calloc(fileLength+1,sizeof(char)))== NULL)
		return 0;
	if((*dirName = calloc(dirLength+1, sizeof(char)))== NULL){
		free(*fileName);
		return 0;
 	}
	/* copy filename */
	strcpy(*fileName, fileP + 1);
	/* copy directory */
	memcpy(*dirName, dirP + 1, dirLength);
	(*dirName)[dirLength] = '\0';

	return 1;
}

