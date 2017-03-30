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
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * comparison function for ints
 */
int intCompare(const void *a, const void *b) {
  double inta = *(int*)a;
  double intb = *(int*)b;

  if(inta == intb)
    return 1;
  else
    return 0;
}

/*
 * comparison function for doubles
 */
int doubleCompare(const void *a, const void *b) {
  double dbla = *(double*)a;
  double dblb = *(double*)b;

  if(dbla == dblb)
    return 1;
  else
    return 0;
}

/*
 * driver for c08e11
 */
int main() {
  /*
  int i;
  int num = 1;
  int num2 = 2;
  */
  double d;
  double num = 2.2;
  double num2 = 1.0;

  /*if(bag_construct(10, sizeof(int)) == 0) {*/
  if(bag_construct(10, sizeof(double)) == 0) {
    fprintf(stderr, "bag_construct failed\n");
    return EXIT_FAILURE;
  }
  else {
    printf("bag_construct() successful\n");
  }

  if(bag_add(&num) == 0) {
    fprintf(stderr, "bag_add(&num) failed\n");
    return EXIT_FAILURE;
  }

  for(d=0; d<9; d++) {
    if(bag_add(&d) == 0) {
      fprintf(stderr, "bag_add(&d), %f, failed\n", d);
      return EXIT_FAILURE;
    }
  }

  if(bag_add(&num) == 0) {
    fprintf(stderr, "bag_add(&num) - 11th value failed\n");
  }

  /*if(bag_remove(&num, intCompare) == 0) {*/
  if(bag_remove(&num, doubleCompare) == 0) {
    fprintf(stderr, "bag_remove(&num, doubleCompare) failed\n");
    return EXIT_FAILURE;
  }

  for(d=0; d<9; d++) {
    /*if(bag_remove(&d, intCompare) == 0) {*/
    if(bag_remove(&d, doubleCompare) == 0) {
      fprintf(stderr, "bag_remove(&d, doubleCompare) failed\n");
      return EXIT_FAILURE;
    }
  }

  /*if(bag_remove(&num2, intCompare) == 0) {*/
  if(bag_remove(&num2, doubleCompare) == 0) {
    fprintf(stderr, "bag_remove(&num2, doubleCompare) - non-existent value\n");
  }

  if(bag_destruct() == 0) {
    fprintf(stderr, "bag_destruct() failed\n");
    return EXIT_FAILURE;
  }
  else {
    printf("bag_destruct() successful\n");
  }

  return EXIT_SUCCESS;
}
