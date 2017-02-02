/*
 ************  INCORRECT VERSION - see ex8-92.c ***************
 * File: ex8-91.c
 * Function: searchGen
 * Purpose: search a block of memory of a given size for a given value
 * Generic solution that uses a function compare()
 * Inputs: block, size, value and compare() (parameters)
 * Returns: 1 if found, 0 otherwise
 * Modifies: nothing
 * Error checking: Returns 0 if block is NULL
 */

int searchGen(const void *block, size_t size, void *value,
  int (*compare)(const void *, const void *)) {

  void *p;

  if(block == NULL)
	return 0;
  for(p = block; p < block+size; p++)
	if(compare(p, value))
		return 1;
  
  return 0;
}
 
