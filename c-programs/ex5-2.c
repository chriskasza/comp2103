/*
 * File: ex5-2.c
 * Copies a single line from the keyboard and redisplays it 
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
     int c;

     printf("Enter a line of characters\n");

     while((c = getchar()) != '\n')
          putchar(c);
     putchar(c);              /* to print end-of-line */

     return EXIT_SUCCESS;
}
