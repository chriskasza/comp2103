/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c09e11.c
 *
 * Given two characters and a filename as arguments, c09e11 will replace all
 * occurrences of the first character in the file with the second character
 * and write the output to stdout.  The file can be provided as the third 
 * argument or it can be redirected into c09e11.
 *
 */

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Usage:          `c09e11 A a file.txt1` OR `c09e11 A a < file.txt`
 * Purpose:        Replace all occurrencs of char1 in file with char2 and
 *                 and write to stdout.
 * Arguments:
 *   char1:        the character to be replaced
 *   char2:        the character to replace with
 *   file:         file to read for replacing
 * Modifies:       does not modify the original file
 * Error checking: requires that the character arguments are single characters
 *                 and not multi-character strings
 */

int main(int argc, char *argv[]) {
  int c;
  FILE *fp;

  switch(argc) {
    case 3: /* two chars */
      if(strlen(argv[1]) != 1) {
        fprintf(stderr, "usage: %s A a file.txt\n", argv[0]);
        return EXIT_FAILURE;
      };
      if(strlen(argv[2]) != 1) {
        fprintf(stderr, "usage: %s A a file.txt\n", argv[0]);
        return EXIT_FAILURE;
      };
      while((c = fgetc(stdin)) != EOF) {
        if((char)c == *argv[1])
          printf("%s", argv[2]);
        else
          printf("%c", c);
      }
      break;
    case 4: /* two chars and a filename */
      if(strlen(argv[1]) != 1) {
        fprintf(stderr, "usage: %s A a file.txt\n", argv[0]);
        return EXIT_FAILURE;
      };
      if(strlen(argv[2]) != 1) {
        fprintf(stderr, "usage: %s A a file.txt\n", argv[0]);
        return EXIT_FAILURE;
      };
      if((fp = fopen(argv[3], "r")) == NULL) {
        fprintf(stderr, "%d: unable to open file, %s.\n", errno, argv[3]); 
        return EXIT_FAILURE;
      }
      while((c = fgetc(fp)) != EOF) {
        if((char)c == *argv[1])
          printf("%s", argv[2]);
        else
          printf("%c", c);
      }
      break;
    default:
      fprintf(stderr, "usage: %s A a file.txt\n", argv[0]);
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

