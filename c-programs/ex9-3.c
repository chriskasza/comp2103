#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
extern char* strdup(const char*);

/*
 * File: ex9-3.c
 * Function: modify
 * Purpose: return through the second parameter
 * 	a copy of input string passed as the first parameter
 *      with the first letter converted to the upper case
 * Inputs: s (parameter)
 * Returns: nothing
 * Modifies: the second parameter: allocates memory and sets it to
 *	the copy of the first parameter with the first letter
 *	changed to the upper case.
 * Error checking: does not do anything if parameter is NULL
 * Sample call:
 *    modify(s, &s1); 
 * where s represents "hi".
 * As a result s1 represents "Hi"
 */
void modify(const char *s, char **news) { 
	if(s == NULL)
		return;

	*news = strdup(s);
	(*news)[0] = toupper((*news)[0]);
}
