/*
 * Exercise 6-5
 * Suppose that MAX is a macro defined like this
 * # define MAX(x,y) x < y ? y : x
 * Is it possible to rewrite the macro MAX so that it will work correctly even if the
 * evaluation of arguments results in side-effects? Justify your answer.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX(x,y) (x, y, x < y ? y : x)  
int main() {  /* simple application */
   int i = 2;
   int j = 3;

   printf("%d\n", MAX(i--, j++));
   return EXIT_SUCCESS;
} 
 
