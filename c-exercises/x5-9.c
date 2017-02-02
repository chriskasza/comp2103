/*
 * Exercise 5-9
 * A filter program that removes all empty lines (i.e. lines containing only the end-of-line character). 
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
   int current;
   int previous = EOF;
       
   /* traverse the file with previous pointing to the character preceding current */
   while((current = getchar()) != EOF)  {
      if(!(current == '\n' && (previous == '\n' || previous == EOF))) /* there was no empty line */
         putchar(current);
      previous = current;
   }
          
   return EXIT_SUCCESS;
}
 
