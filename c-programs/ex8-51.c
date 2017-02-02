/* 
 * File: ex8-51.c
 * Function: show1
 * Purpose: print characters stored in a memory block, 
 * 	separated by blanks and enclosed by square brackets.
 * Recursive (incorrect) solution.
 */
void show1(char *p) {

     printf("[ ");
     if (*p != '\0') {
          printf("%c ", *p);
          show1(++p);               
     }
     printf("]\n");     
}
