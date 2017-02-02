#include <ctype.h>
/*
 * File: ex9-1.c
 * Function: modify
 * Purpose: convert the first character of the input string to the upper case
 * Inputs: s (parameter)
 * Returns: void
 * Modifies: the first character of s
 * Error checking:none
 * Sample call:
 *    modify(s)  
 * where s represents "hi".
 * As a result s represents "Hi"
 */
void modify(char *s) {
	s[0] = toupper(s[0]);
}
