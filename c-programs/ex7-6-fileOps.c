/*
 * File: ex7-6-fileOps.c
 * Implementation of the module with various file processing operations
 * The constructor uses a filename to open a file.
 * The following functions are supported:
 *   find the number of words in the file
 *   find the number of lines in the file
 *   find the number of characters in the file
 * 
 * If suitable, these functions cache data for other functions.
 * The cache is cleared when a destructor is called.
 */

#include <stdio.h>
#include <ctype.h>
#include "ex7-6-fileOps.h"

/**************  Local cache, value -1 indicates no cache ***********/
#define CLEAR -1
static long words_ = CLEAR ;    
static long chars_ = CLEAR ; 
static long lines_ = CLEAR ;
#define NOT_INITIALIZED 0	/* macros for testing initialization */
#define INITIALIZED 1
static int initialized_ = NOT_INITIALIZED;
static FILE *f;			/* file handle */

/* 
 * Function: construct_fileOps
 * Purpose: constructor for the file module
 * Inputs: filename (parameter)
 * Returns: 1 if successful, 0 otherwise
 * Modifies: Nothing (for the client)
 * Error checking: fails if the file has been opened, or can not be opened
 * Sample call:
 *   if(construct_fileOps("a.dat") == 1) ... success
 */
int construct_fileOps(char *filename) {
	if(initialized_ == INITIALIZED)
		return 0;

	if((f = fopen(filename, "r")) == NULL)
		return 0;

	initialized_ = INITIALIZED;

	return 1;
}

/* 
 * Function: words_fileOps
 * Purpose: read from a given file and count the number of words
 *   Also cache characters and lines.
 * Inputs: nothing
 * Returns: number of words or EOF if failed. 
 * A word is the longest sequence of characters that
 *	does not include whitespace.
 * Modifies: Internal cache for words, lines and characters
 *         (also the file is rewound before termination)
 *          Note: side effects on global variables used for cache
 * Error checking: Fails if the module is not initialized
 *		or input will fail
 * Sample call:
 *    long i = words_fileOps();
 *
 */
long words_fileOps() {
     int flag = 1;
     int c;

     if(initialized_ == NOT_INITIALIZED)
		return EOF;

     if(words_ != CLEAR)  /* use cache */
		return words_;

     /* reset cache */
     words_ = 0;   

     /* read and process the input file */
     rewind(f);
     while ((c = getc(f)) != EOF) {

	  if(chars_ < 0) /* cache characters? */
		chars_--;

	  if(lines_ < 0 && c == '\n') /* cache lines? */
		lines_--;

       if(isspace(c))  /* take care of words */
          flag = 1;
       else if(flag) {
               flag = 0;
               words_++;
#ifdef DEB
               printf("\nword #: %ld\n", words_);
               fputc(c, stderr);
#endif
          }
#ifdef DEB
          else fputc(c, stderr);
#endif
      }
	rewind(f);

      /* set cache for characters and lines to their actual values */
      chars_ = -chars_ - 1;
      lines_ = -lines_ - 1;
      return words_;   
}


/* 
 * Function: chars_fileOps
 * Purpose: read from a given file and count the number of characters
 *   Also, cache the number of lines
 * Inputs: nothing
 * Returns: number of characters or EOF if failed
 * Modifies: Internal cache (also the file is rewound before termination)
 *          Note: side effects on global variables used for cache
 * Error checking:  Fails if the module is not initialized
 *		or input will fail
 * Sample call:
 *    long i = chars_fileOps();
 *
 */
long chars_fileOps() {
  int c;

  if(initialized_ == NOT_INITIALIZED)
		return EOF;
  if(chars_ != CLEAR)
	return chars_;

     /* reset cache */
     chars_ = 0;   

     /* read and process the input file */
  rewind(f);
  while((c = getc(f)) != EOF) {
      chars_++;
      if(lines_ < 0 && c == '\n') /* cache lines? */
		lines_++;
  }
  rewind(f);
  lines_ = -lines_ - 1;

  return chars_;
}

/* 
 * Function: lines_fileOps
 * Purpose: read from a given file and count the number of lines
 *   Also, cache the number of characters
 * Inputs: nothing
 * Returns: number of lines or EOF if failed
 * Modifies: Internal cache (the file is rewound before termination)
 *          Note: side effects on global variables used for cache
 * Error checking: Fails if the module is not initialized
 *		or input will fail
 * Sample call:
 *    long i = lines_fileOps();
 *
 */
long lines_fileOps() {
  int c;

   if(initialized_ == NOT_INITIALIZED)
		return EOF;

  if(lines_ != CLEAR)
	return lines_;

   /* reset cache */
     lines_ = 0;    

  rewind(f);
  while((c = getc(f)) != EOF) {
      if(c == '\n')
         lines_++;

      if(chars_ < 0) /* cache characters? */
		chars_++;
  }
  rewind(f);
  chars_ = -chars_ - 1;

  return lines_;
}

/* 
 * Function: destruct_fileOps
 * Purpose: destructor for the file module
 * Inputs: nothing
 * Returns: 1 if successful, 0 otherwise
 * Modifies: Closes the file and clears the cache
 * Error checking: fails if the file has not been opened, or can not be closed
 * Sample call:
 *   if(destruct_fileOps() == 1) ... success
 */
int destruct_fileOps() {
  if(initialized_ == NOT_INITIALIZED)
	return 0;

  if(fclose(f) == EOF)
	return 0;

  words_ = chars_ = lines_ = CLEAR;
  initialized_ = NOT_INITIALIZED;

  return 1;
}

