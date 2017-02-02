#include <ctype.h>
#include <stdlib.h>
/*
 * File: ex9-2.c
 * Function: modify
 * Purpose: create a copy of input string with the first argument 
 *     converted to the upper case
 * Inputs: s (parameter)
 * Returns: copy of modified s
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *    s1 = modify(s)  
 * where s represents "hi".
 * As a result s1 represents "Hi"
 */
char *modify(const char *s);

/*
 * Function: length
 * Purpose: compute the length of a string
 * Inputs: s (parameter)
 * Returns: length (number of characters before \0, excluding \0)
 * Modifies: nothing
 * Error checking: fails if the parameter is NULL
 * Sample call:
 *    int i = length("hi");   returns 2 
 */
int length(const char *s) {
	char *p = (char*)s;

	for(p = (char*)s; *p; p++)
		;

	return p - s;
}

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

	if((kopy = calloc(length(s)+1, sizeof(char))) == NULL)
		return NULL;

	/* memory allocated, now copy */
	for(ps = (char*)s, pkopy = kopy; *ps; ps++, pkopy++)
		*pkopy = *ps;
	/* do not forget to copy \0 */
	*pkopy = *ps;
	
	return kopy;
}

char *modify(const char *s) {
	char *news;

	if((news = strdup(s)) == NULL)
		return NULL;
	news[0] = toupper(news[0]);

	return news;
}
