#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
/*
 * File: ex9-9.c
 * Function: modify
 * Purpose: return a copy of input string with the first argument 
 *     converted to the upper case
 * Inputs: s (parameter)
 * Returns: copy of modified s
 * Modifies: nothing
 * Error checking: does not do anything if parameter is NULL
 * Sample call:
 *    s1 = modify(s)  
 * where s represents "hi".
 * As a result s1 represents "Hi"
 */
char *modify(const char *s);

/*
 * Function: strdup
 * Purpose: create a copy of a string
 * Inputs: s (parameter)
 * Returns: pointer to a newly allocated block containing a copy of s
 *   The client is responsible for deallocating this block
 * Modifies: nothing
 * Error checking: returns NULL if the parameter is NULL or malloc failed
 * Sample call:
 *    char *p = strdup("hi");
 */
char *strdup(const char *s) {
	char *kopy;    /* copy of s */

	if((kopy = calloc(strlen(s)+1, sizeof(char))) == NULL)
		return NULL;
	/* memory allocated, now copy */
	strcpy(kopy, s);
	
	return kopy;
}

char *modify(const char *s) {
	char *news;
	 
	if(s == NULL)
		return NULL;
	news = strdup(s);
	news[0] = toupper(news[0]);

	return news;
}

