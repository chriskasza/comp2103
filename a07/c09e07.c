/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c09e07.c
 *
 * read a given file and output lowercase and uppercase characters to
 * separate, specified files
 *
 */

#include <ctype.h>
#include <stdio.h>

/*
 * Function:       split
 * Purpose:        Read characters from the file inName and output:
 *                   all lowercase letters to the file outName1
 *                   all uppercase letters to the file outName2
 *                   all other characters to the standard output stream
 * Inputs:
 *   inName:       the file to be read from
 *   outName1:     file where the lowercase characters will be written
 *   outName2:     file where the uppercase characters will be written
 * Returns:        0 if any errors occur
 * Modifies:       the two output files provided
 * Error checking: will quit if the files are inaccessible
 * Sample call:
 *    if(split(ORIGFILE, LCASEFILE, UCASEFILE) == 0)
 *      fprintf(stderr, "err: trouble spliting the file\n");
 */
int split(const char* inName, const char* outName1, const char* outName2) {
  
}
