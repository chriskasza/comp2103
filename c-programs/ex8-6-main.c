#include <stdio.h>
#include <stdlib.h>

/* 
 * File: ex8-6-main.c
 * driver for get()
 */

/* 
 * File: ex8-6.c
 * Function: get
 * Purpose: read a single line from the standard input and returns 1
 *  if successful, 0 otherwise.
 * Returns through parameters the number of whitespace 
 *	characters and the number of lowercase letter.
 * Inputs: nothing
 * Returns: 1 if successful, otherwise 0
 * Modifies: two parameters ws and lc, also reads the standard input
 * Error checking: Full
 * Sample call:
 *    int spaces, lines;
 *    if((i = get(&spaces, &lines) == 0)
 *       error   
 */
int get(int *ws, int *lc);
 
#include <stdio.h>
#include <stdlib.h>

int main() {
     int white, letters;

     printf("Enter a line\n");

     if (get(&white, &letters) != 0) {
          printf("There are %d whitespace characters", white);
          printf("\nand %d lower case letters\n", letters);
     }
     else fprintf(stderr, "unexpected end-of-file\n");

	return EXIT_SUCCESS;
}

