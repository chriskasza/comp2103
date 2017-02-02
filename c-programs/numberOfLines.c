/*
 * File: numberOfLines.c
 */

#include <stdio.h>
#include <ctype.h>
 
/* 
 * Function: numberOfLines
 * Purpose: read from a given file and count the number of lines
 * Inputs: file name
 * Returns: number of lines or EOF if failed
 * Error checking: Fails if the file can not be opened
 * Sample call:
 *    long i = numberOfLines("test.dat");
 *
 */
long numberOfLines(const char *fname) {
  int c;
  FILE* in;
  long lines = 0;


  if((in = fopen(fname, "r")) == NULL) 
	return EOF;

  while ((c = getc(in)) != EOF) 
      if (c == '\n')
         lines++;
  if(fclose(in) == EOF)
	return EOF;

  return lines;
}

