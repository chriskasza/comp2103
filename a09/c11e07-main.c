/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c11e07-main.c
 *
 * driver for c11e07
 *
 */

#include "c11e07.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * main
 */
int main() {
  char *names[] = {"Bob", "Clare", "Don", "Jon", "Claire", "Klaar", "Clear"};
  int ids[] = {123, 3221, 121, 344, 555, 666, 111};
  int i;
  int items = sizeof(ids) / sizeof(int);

  for(i = 0; i < items; i++) {
    printf("adding %s (%d)\n", names[i], ids[i]);
    add(names[i], ids[i]);
  }
  printf("\nOrdered student record array:\n");

  if(printarray() == 0) {
    fprintf(stderr, "failed to print array\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
} 

