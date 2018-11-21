/* File: strdup.c */
#include <stdlib.h>
#include <string.h>

/*
 * Function: strdup
 * Purpose: create a copy of a string
 * Inputs: s (parameter)
 * Returns: pointer to a newly allocated block containing a copy of s
 *   The client is responsible for deallocating this block
 * Modifies: nothing
 * Error checking: returns NULL if malloc failed
 * Sample call:
 *    char *p = strdup("hi");
 */
char *strdup(const char *s) {
	char *kopy;    /* copy of s */
	char *ps;	     /* used for copying */
	char *pkopy;	/* for copying */

	if((kopy = calloc((strlen(s)+1), sizeof(char))) == NULL)
		return NULL;

	/* memory allocated, now copy */
	for(ps = (void*)s, pkopy = kopy; *ps; ps++, pkopy++)
		*pkopy = *ps;
	/* do not forget to copy \0 */
	*pkopy = *ps;
	
	return kopy;
}
