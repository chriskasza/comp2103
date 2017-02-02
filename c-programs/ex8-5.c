#include <stdio.h>
/* 
 * File: ex8-5.c
 * Function: show
 * Purpose: print characters stored in a memory block, 
 * 	separated by blanks and enclosed by square brackets.
 */
void show(char *p) { 
     char *q;

     printf("[ ");
     for (q = p; *q != '\0'; q++)
          printf("%c ", *q);
     printf("]\n");
}
