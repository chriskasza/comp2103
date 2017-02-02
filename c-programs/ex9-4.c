#include <stdio.h>
#include <ctype.h>
/*
 * File: ex9-4.c
 * Function: isNumber
 * Purpose: check if a string represents an integer value
 *    in decimal or hexadecimal 
 * Inputs: s (parameter)
 * Returns: 1 if s represents a number, 0 otherwise
 * Modifies: nothing
 * Error checking: does not do anything if parameter is NULL
 * Sample call:
 *    if(isNumber("0xFa")) ...
 */
int isNumber(const char *s) {
	
	if(s == NULL || s[0] == '\0') /* null or empty string */
		return 0;
	
	if(s[0] == '0') { /* check if there is a leading 0 */
		if(s[1] == '\0')  /* just a single 0 */
			return 1;

		if(s[1] == 'x' || s[1] == 'X') { /* hex ? */
			if(s[2] == '\0')
				return 0; /* just "0x" is not enough */

			/* traverse characters beyond 0x */
			for(s += 2; *s; s++)
				if(!isxdigit(*s))
					return 0;
			return 1; /* correct hex */
		}
	}
	/* traverse the entire string */
	for(; *s; s++)
		if(!isdigit(*s))
			return 0;
	return 1;
}
