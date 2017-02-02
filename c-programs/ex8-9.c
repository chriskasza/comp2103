/*
 * File: ex8-9.c
 * Function: search
 * Purpose: search a block of memory of a given size for a given double value
 * Inputs: block, size and value (parameters)
 * Returns: 1 if found, 0 otherwise
 * Modifies: nothing
 * Error checking: Returns 0 if block is NULL
 * Sample call:
 *    if(search(block, 10, 12.3))  ... 
 */
#include <stddef.h>
int search(const double *block, size_t size, double value) {
  double *p;

  if(block == NULL)
	return 0;
  for(p = (void*)block; p < block+size; p++)
	if(*p == value)
		return 1;
  
  return 0;
}
