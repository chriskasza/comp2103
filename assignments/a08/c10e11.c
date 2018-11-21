/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c10e11.c
 *
 * read lines from a file provided on the command line
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1
#define BUF_SIZE 5

/*
 * Function:       getLine
 * Purpose:        read from file a line of unlimited length using a single
 *                   dynamic allocation
 * Inputs:
 *   in:           file handle of file to be read from
 * The client is responsible for opening and closing this file.
 * Returns:
 *                 pointer to the memory block that stores the line (through
 *                   parameter)
 *                 The client is responsible for deallocating this memory
 *                 Through function returns 1 if a line has been read, 0 on
 *                   error, and EOF on eof
 * Modifies:       file
 * Error checking: returns 0 if fails
 * Sample call:
 *    char *p;
 *    FILE *f;
 *    ... open f ..
 *    if(getLine(f, &p) == 1)
 *       printf("line is %s\n", p); *
 *
 * Implementation of getLine:
 *  read until the local buffer is full and then recurse
 *  Allocate the final buffer based on the number of local
 *  buffers read and as the recursive calls bottom out,
 *  copy them in reverse order into the resulting buffer.
 */
int getLine(FILE *in, char **result) {
  char buf[BUF_SIZE];
  int c;        /* used to read characters */
  int i;        /* auxiliary variable */
  int base;
  static int size_ = 0; /* used to accumulate the size of the line */
  static int j_ = 0; /* counter for recursion depth */

  if(DEBUG)
    j_++;

  if(DEBUG && size_ == 0)
    fprintf(stderr, "\n");

  /* try to read up to BUF_SIZE characters, stop on eoln and eof */
  for (i = 0; i < BUF_SIZE; i++) {
    c = fgetc(in);

    if(c == EOF) {  /* eof or error */
      if(feof(in)) {  /* end-of-file rather than error */
        if(i == 0 && size_ == 0)  /* nothing read */
          return EOF;
        break;
      } else {   /* error */
        size_ = 0;
        return 0;
      }
    }

    if (c == '\n')
      break;

    buf[i] = c;
  }

  /* increment the number of bytes */
  size_ += i;
  /* Recurse, when the recursion bottoms out, allocate the master buffer */
  if (c != EOF && c != '\n') {
    if(getLine(in,result) == 0) {
      size_ = 0;
      return 0;
    }
    if(DEBUG)
      fprintf(stderr, "\t\t(DEBUG) buffer filled: %s\n", buf);
    j_--;
  } else {
    if((*result = malloc((size_+1)*sizeof(char))) == NULL) {
      size_ = 0;
      return 0;
    }
    /* store the terminating \0 */
    (*result)[size_] = '\0';
  }

  /* Copy buf into the appropriate location */
  base = size_ - i ;
  memcpy(*result + base, buf, i);
  size_ -= i;

  if(DEBUG && j_ == 1) {
    fprintf(stderr, "\t(DEBUG) buffers concatenated: %s\n", *result);
    j_--;
  }

  return 1;
}


/*
 * main
 */
int main(int argc, char ** argv) {
  FILE *f;
  char *line;
  int count;
  int result;

  if(argc != 2) {
    fprintf(stderr, "usage %s filename\n", argv[0]);
    return EXIT_FAILURE;
  }
  if((f = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "can not open %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  printf("Displaying lines using a buffer of %3d\n", BUF_SIZE);
  for(count = 1; (result = getLine(f, &line)) != EOF; count++) {
    if(result == 0) {
      fprintf(stderr, "error encountered, terminating\n");
      return EXIT_FAILURE;
    }
    printf("line #%d :%s\n", count, line);
    free(line);
  }

  if(fclose(f) == EOF) {
    fprintf(stderr, "could not close %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
