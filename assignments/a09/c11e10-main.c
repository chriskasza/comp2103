/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c11e10-main.c
 *
 * a driver for c11e10
 *
 */

#include "c11e10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * main
 ** create first element, 1.1, in list
 ** insert 5.5 in list
 ** insert 9.9 in list
 ** insert 11.1 in list
 ** insert 2.2 in list
 ** insert 3.3 in list
 ** insert 4.4 in list
 ** insert 5.5 in list
 ** insert 6.6 in list
 ** insert 7.7 in list
 ** insert 8.8 in list
 ** find and print largest element
 ** dupe 1.1 and insert in list
 ** print list
 ** del 3rd element from list
 ** print list
 ** kill last five elements
 ** print list
 ** kill last five elements
 ** kill last five elements
 ** print list
 */
int main() {
  NodeTP *element;    /* first element, to start off the list */
  double value = 1.1; /* value to store in element */

  NodeTP *second;     /* next item in list after element */
  NodeTP *largest;    /* largest element in list */
  NodeTP *dupe;      /* element for testing dupNode */

  element = genElemPtr();
  second  = genElemPtr();
  largest = genElemPtr();
  dupe    = genElemPtr();

  if((*element = genElement(value)) == NULL) {
    fprintf(stderr, "failed on first element\n");
    return EXIT_FAILURE;
  }
  if(insert(element, 5.5) == 0) {
    fprintf(stderr, "failed to add 5.5\n");
    return EXIT_FAILURE;
  }
  if(insert(element, 9.9) == 0) {
    fprintf(stderr, "failed to add 5.5\n");
    return EXIT_FAILURE;
  }
  if(insert(element, 11.1) == 0) {
    fprintf(stderr, "failed to add 5.5\n");
    return EXIT_FAILURE;
  }
  if(insert(element, 2.2) == 0) {
    fprintf(stderr, "failed to add 5.5\n");
    return EXIT_FAILURE;
  }
  if(insert(element, 3.3) == 0) {
    fprintf(stderr, "failed to add 5.5\n");
    return EXIT_FAILURE;
  }
  if(insert(element, 4.4) == 0) {
    fprintf(stderr, "failed to add 5.5\n");
    return EXIT_FAILURE;
  }
  if(insert(element, 5.5) == 0) {
    fprintf(stderr, "failed to add 5.5\n");
    return EXIT_FAILURE;
  }
  if(insert(element, 6.6) == 0) {
    fprintf(stderr, "failed to add 5.5\n");
    return EXIT_FAILURE;
  }
  if(insert(element, 7.7) == 0) {
    fprintf(stderr, "failed to add 5.5\n");
    return EXIT_FAILURE;
  }
  if(insert(element, 8.8) == 0) {
    fprintf(stderr, "failed to add 5.5\n");
    return EXIT_FAILURE;
  }

  printf("\nOrdered list of double values:\n");
  if(print(*element) == 0) {
    fprintf(stderr, "failed to print list\n");
    return EXIT_FAILURE;
  }

  /*if((*element = genElement(0)) == NULL) {
    fprintf(stderr, "failed to create element to hold largest\n")
    return EXIT_FAILURE;
  }*/
  if(maxi(element, largest) == 0) {
    fprintf(stderr, "failed to get largest element\n");
    return EXIT_FAILURE;
  } else {
    printf("\nLargest element is %f\n", (*largest)->value);
  }

  if((*dupe = dupNode(element)) == NULL) {
    fprintf(stderr, "failed to get duplicate element\n");
    return EXIT_FAILURE;
  } else {
    printf("\nValue of duplicated element is %f\n", (*dupe)->value);
  }

  printf("\nOrdered list of double values:\n");
  if(print(*element) == 0) {
    fprintf(stderr, "failed to print list\n");
    return EXIT_FAILURE;
  }

  *second = (*element)->next->next;
  if((deleteNode(second, element)) == 0) {
    fprintf(stderr, "failed to delete third element\n");
    return EXIT_FAILURE;
  } else {
    printf("\nDeleted third element\n");
  }

  printf("\nOrdered list of double values:\n");
  if(print(*element) == 0) {
    fprintf(stderr, "failed to print list\n");
    return EXIT_FAILURE;
  }

  if(kill(element) == 0) {
    fprintf(stderr, "failed to delete last five items in list\n");
    return EXIT_FAILURE;
  } else {
    printf("\nDeleted last five elements\n");
  }

  printf("\nOrdered list of double values:\n");
  if(print(*element) == 0) {
    fprintf(stderr, "failed to print list\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}


