#include <stdio.h>
#include <ctype.h>
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
int get(int *ws, int *lc) {
     int c;

     *ws = *lc = 0;

     while ((c = getchar()) != EOF) 
          switch (c) {
          case ' ':
          case '\t': (*ws)++;
                     break;

          case '\n': return 1;

          default:   if(islower(c))
                          (*lc)++;
                     break;
          }

     return 0;
}
