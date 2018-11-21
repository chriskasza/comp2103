/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c09e03-main.c
 *
 * Driver for c09e03.
 *
 */

#include "c09e03.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main() {
  char *str;
  const int SIZE = 30;

  if((str = calloc(SIZE, sizeof(char))) == NULL) {
    fprintf(stderr, "calloc failed\n");
    return EXIT_FAILURE;
  }

  printf("Enter a short sentence (thirty characters or less) which will be "
      "converted to all upper case:\n");

  if(fgets(str, SIZE, stdin) == NULL) {
    fprintf(stderr, "fgets failed\n");
    return EXIT_FAILURE; 
  }

  lowerToUpper(str);

  printf("\n%s\n", str);

  return EXIT_SUCCESS;
}
