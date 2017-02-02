#include <stdio.h>
/* 
 * File: ex8-52.c
 * Function: show2
 * Purpose: print characters stored in a memory block, 
 * 	separated by blanks and enclosed by square brackets.
 * Recursive (correct) solution.
 */
void show2(char *p) {
     static int first = 1;

     if (first) {
          printf("[ ");
          first = 0;
     }
     if (*p != '\0') {
          printf("%c ", *p);
          show2(++p);               
     } else {
          printf("]\n");
          first = 1;  /* reset first for next call */
     }
}

