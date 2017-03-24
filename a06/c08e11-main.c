/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c08e11-main.c
 *
 * Driver for c08e11.
 *
 */

#include "c08e11.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main() {
  int i;
  double num;

  if(bag_construct(10, sizeof(double)) == 0) {
    fprintf(stderr, "bag_construct failed\n");
    return EXIT_FAILURE;
  }

  if(bag_add(1.1) == 0) {
    fprintf(stderr, "bag_add(1.1) failed\n");
    return EXIT_FAILURE;
  }

  if(bag_add(num) == 0) {
    fprintf(stderr, "bag_add(num) failed\n");
    return EXIT_FAILURE;
  }

  for(i=0; i<8; i++) {
    if(bag_add(i) == 0) {
      fprintf(stderr, "bag_add(i) failed\n");
      return EXIT_FAILURE;
    }
  }

  if(bag_add(1) == 0) {
    fprintf(stderr, "bag_add(1) - 11th value failed\n");
  }

  /* if(bag_next() == NULL) {
    fprintf(stderr, "bag_next() returned null\n");
  }
  */

  if(bag_remove(1.1) == 0) {
    fprintf(stderr, "bag_remove(1.1) failed\n");
    return EXIT_FAILURE;
  }

  if(bag_remove(num) == 0) {
    fprintf(stderr, "bag_remove(num) failed\n");
    return EXIT_FAILURE;
  }

  for(i=0; i<8; i++) {
    if(bag_remove(i) == 0) {
      fprintf(stderr, "bag_remove(i) failed\n");
      return EXIT_FAILURE;
    }
  }

  if(bag_remove(1) == 0) {
    fprintf(stderr, "bag_remove(1) - non-existent value failed\n");
  }

  if(bag_destruct() == 0) {
    fprintf(stderr, "bag_destruct() failed\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
