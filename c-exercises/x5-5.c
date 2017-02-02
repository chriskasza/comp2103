/*
 * Exercise 5-5
 * A filter program that replaces all sequences of consecutive whitespace characters by a single space.
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
   int wasWhite = 0;
   int c;

   /* reading an input, wasWhite is 1 if the previous character was whitespace */
   while((c = getchar()) != EOF) 
      if(c == ' ' || c == '\t' || c == '\n') 
         wasWhite = 1; /* it does not matter whether the previous character was whitespace */
      else if(wasWhite) {  /* first non-whitespace after a sequence of whitespace */
             wasWhite = 0;
             putchar(' ');
      } else putchar(c);  /* not a whitespace; just copy */
         
  /* check if there was a sequence of whitespace just before the end of file */
  if(wasWhite)
    putchar(' ');
  /* this may not be correct; the file is not terminated by the end-of-line */
  return EXIT_SUCCESS;
}
 
 