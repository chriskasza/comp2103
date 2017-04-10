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
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  typedef enum { false, true } bool;
  FILE *inFile;
  FILE *lcFile;
  FILE *ucFile;
  int c;
  bool fail = false;

  if((inFile = fopen(inName, "r")) == NULL) {
    fprintf(stderr, "%d: unable to open file, %s.\n", errno, inName);
    return EXIT_FAILURE;
  }

  if((lcFile = fopen(outName1, "w")) == NULL) {
    fprintf(stderr, "%d: unable to open file, %s.\n", errno, outName1);
    return EXIT_FAILURE;
  }

  if((ucFile = fopen(outName2, "w")) == NULL) {
    fprintf(stderr, "%d: unable to open file, %s.\n", errno, outName2);
    return EXIT_FAILURE;
  }

  while((c = fgetc(inFile)) != EOF) {
    if(islower(c) && (fputc(c, lcFile) == EOF)) {
      fprintf(stderr, "failed to write to %s.\n", outName1);
      return EXIT_FAILURE;
    }
    else if(isupper(c) && (fputc(c, ucFile) == EOF)) {
      fprintf(stderr, "failed to write to %s.\n", outName2);
      return EXIT_FAILURE;
    }
  }

  if(fputc('\n', lcFile) == EOF) {
    fprintf(stderr, "failed to write to %s.\n", outName1);
    return EXIT_FAILURE;
  }

  if(fputc('\n', ucFile) == EOF) {
    fprintf(stderr, "failed to write to %s.\n", outName1);
    return EXIT_FAILURE;
  }

  if(fclose(inFile) == EOF) {
    fprintf(stderr, "failed to close %s.\n", inName);
    fail = true;
  }

  if(fclose(lcFile) == EOF) {
    fprintf(stderr, "failed to close %s.\n", outName1);
    fail = true;
  }

  if(fclose(ucFile) == EOF) {
    fprintf(stderr, "failed to close %s.\n", outName2);
    fail = true;
  }

  if(fail == true)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
