/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c09e07-main.c
 *
 * Driver for c09e07.
 *
 */

#include "c09e07.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function: readStdin
 * Purpose:  read a line from STDIN of 
 */
char *readStdin(const int SIZE) {
  char *str;

  if((str = calloc(SIZE, sizeof(char))) == NULL) {
    fprintf(stderr, "failed to allocate string buffer\n");
    return NULL;
  }

  if(fgets(str, SIZE, stdin) == NULL) {
    fprintf(stderr, "failed to read stdin\n");
    return NULL;
  }

  return str;
}

/*
 * main
 */
int main() {
  char *inFile;
  char *lcFile;
  char *ucFile;
  const int SIZE = 64;

  printf("Name of file to be read: ");
  if((inFile = readStdin(SIZE)) == NULL)
    return EXIT_FAILURE;
  inFile[strcspn(inFile, "\n")] = 0;

  printf("Name of output file for lowercase characters: ");
  if((lcFile = readStdin(SIZE)) == NULL)
    return EXIT_FAILURE;
  lcFile[strcspn(lcFile, "\n")] = 0;

  printf("Name of output file for uppercase characters: ");
  if((ucFile = readStdin(SIZE)) == NULL)
    return EXIT_FAILURE;
  ucFile[strcspn(ucFile, "\n")] = 0;

  if(split(inFile, lcFile, ucFile) == EXIT_FAILURE)
    fprintf(stderr, "failed to process file\n");

  free(inFile);
  free(lcFile);
  free(ucFile);

  return EXIT_SUCCESS;
}
