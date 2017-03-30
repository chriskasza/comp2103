/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c08e11.c
 *
 * This module provides a generic "bag" - a set where duplicate elements are
 * permitted.  The module provides simple add and remove operations, as well
 * as enumeration.
 */

#include "c08e11.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_INITIALIZED 0
#define INITIALIZED 1
#define VOID(targ,size) ((void *)(((char *)(targ)) + (size)))
#define VOIDSUB(targ,size) ((void *)(((char *)(targ)) - (size)))

static int initialized_ = NOT_INITIALIZED;
static int num_eles_;  /* number of elements in bag */
static size_t bag_size_;  /* size of the whole bag */
static size_t ele_size_;  /* size of an element in the bag */
static void *bag_ = NULL;  /* the bag */
static void *current_ = NULL; /* current item for enumeration */

/*
void print_statics() {
  printf("initialized %d  num_eles %d", initialized_, num_eles_);
  printf("bag_size %lu  ele_size %lu", bag_size_, ele_size_);
  printf("bag %p  current %p\n", bag_, current_);
}
*/

/*
 * Function:       bag_construct
 * Purpose:        construct a bag
 * Input:
 *    count:       number of elements in the bag
 *    size:        size of a single element
 * Returns:        1 for successful construction; 0 for unsuccessful;
 *                 0 if bag is already initialized
 * Modifies:       sets state of module
 * Error checking: checks that count and size are positive values
 *                 checks if bag is already initialized
 * Sample call:
 *    if(bag_construct(100, sizeof(double)) == 0)
 *      printf("failed to make the bag");
 *
 */
int bag_construct(size_t count, size_t size) {
  if(initialized_ == INITIALIZED)
    return 0;

  if(count < 1 || size < 1)
    return 0;

  if((bag_ = malloc(count*size)) == NULL)
    return 0;

  ele_size_ = size;
  bag_size_ = count*size;
  num_eles_ = 0;
  current_ = bag_;
  initialized_ = INITIALIZED;

  return 1;
}

/*
 * Function:       bag_destruct
 * Purpose:        destruct a bag
 * Input:          -
 * Returns:        1 for successful destruction; 0 for unsuccessful
 * Modifies:       resets state of module
 * Error checking: checks if bag is initialized before destructing
 * Sample call:
 *    if(bag_destruct() == 0)
 *      printf("failed to destruct the bag");
 *
 */
int bag_destruct() {
  if(initialized_ == NOT_INITIALIZED)
    return 0;

  free(bag_);
  ele_size_ = 0;
  bag_size_ = 0;
  num_eles_ = 0;
  initialized_ = NOT_INITIALIZED;
  current_ = NULL;
  bag_ = NULL;

  return 1;
}

/*
 * Function:       bag_add
 * Purpose:        add an element to the bag
 * Input:
 *    item:        an element to be added to the bag
 * Returns:        1 upon success and 0 if unsuccessful
 * Modifies:       adds an element to the bag
 * Error checking: checks if bag is initialized
 *                 checks if there is room for the item
 * Sample call:
 *    double number = 123.4
 *    if(bag_add(number) == 0)
 *      printf("failed to add number to the bag");
 *
 */
int bag_add(void *item) {
  if(initialized_ == NOT_INITIALIZED)
    return 0;

  if(current_ == VOID(bag_, bag_size_))
    return 0;

  memcpy(current_, item, ele_size_);
  current_ = VOID(current_, ele_size_);
  num_eles_++;
  return 1;
}

/*
 * Function:       bag_remove
 * Purpose:        remove an element from the bag
 * Input:          item to remove
 * Returns:        1 upon success and 0 if unsuccessful
 * Modifies:       removes the first occurrence of an element from the bag
 * Error checking: checks if the bag is initialized
 *                 checks if the bag is empty
 * Sample call:
 *    double number1 = 123.4
 *    if(bag_remove(number1) == 0)
 *      printf("failed to remove number1 from the bag");
 *
 */
int bag_remove(void *item, int (*compare)(const void *, const void *)) {
  void *itemenum = NULL;

  if(initialized_ == NOT_INITIALIZED)
    return 0;

  if(current_ == bag_)
    return 0;

  for(itemenum = bag_; itemenum < VOID(bag_, ele_size_*num_eles_);
      itemenum = VOID(itemenum, ele_size_)) {
    if(compare(itemenum, item) == 1)
      break;
  }

  if(itemenum == VOID(bag_, bag_size_))
    return 0;

  for(; itemenum < VOID(bag_, ele_size_*num_eles_);
      itemenum = VOID(itemenum, ele_size_)) {
    memmove(itemenum, VOID(itemenum, ele_size_), ele_size_);
  }

  num_eles_--;
  current_ = VOIDSUB(current_, ele_size_);

  return 1;
}
