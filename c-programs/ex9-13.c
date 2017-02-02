#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * File: ex9-13.c
 * Function: strip
 * Purpose: strip leading and trailing characters from a given set
 * Inputs: strings s, and set (parameters)
 * Returns: a copy of s with leading and trailing characters from set removed
 * Modifies: nothing
 * Error checking: returns NULL if memory allocation failed
 * Sample call:
 * char *str;
 * str = strip("   hello how   ", " ");
 * Now str points to "hello how"
 * Note: the client is responsible for deallocating memory for str
 */
char *strip(const char *s, const char *set) {
	int start = strspn(s, set);  /* number of leading characters */
	int end; /* number of trailing characters */
	char *kopy;
	int length = strlen(s);

	if(length != start)  { /* there are characters not in s */
		/* find trailing */
		for(end = length; end > 1; end--)
			if(strchr(set, s[end]) == NULL)
				break;
		length = end - start + 1;  /* what is left after strip */
		if((kopy = calloc(length + 1, sizeof(char))) == NULL)
			return NULL;
	
		memcpy(kopy, s+start, length);
		kopy[length] = '\0';
	} else {
		if((kopy = calloc(length + 1, sizeof(char))) == NULL)
			return NULL;
		strcpy(kopy, s);
	}
	return kopy;
}
