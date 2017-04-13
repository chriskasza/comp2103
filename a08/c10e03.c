/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c09e03.c
 *
 * contains the function, lowerToUpper, which converts all characters to 
 * uppercase in a given string.
 *
 */

#include <ctype.h>
#include <stdio.h>

/*
 * Function:       lowerToUpper
 * Purpose:        convert all alpha characters in a given string to uppercase
 * Inputs:
 *   s:            a string
 * Returns:        nothing
 * Modifies:       the string provided
 * Error checking: none
 * Sample call:
 *    lowerToUpper(str)
 */
void lowerToUpper(char *s) {
  char *p;

  for(p = (char*)s; *p; p++) {
    *p = toupper(*p);
  }
}

