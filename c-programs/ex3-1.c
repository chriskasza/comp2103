/*
 * File: ex3-1.c
 * Program that reads two characters and prints them in 
 * reverse order, separated by a tab and ending with end of line.
 * Single character, unformatted I/O operations are used. 
 * Error checking: none.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
     int c, d;		/* chars must be read as ints */


     c = getchar();
     d = getchar();		 

     putchar(d);		 
     putchar('\t');		 
     putchar(c);		 
     putchar('\n');		 

     return EXIT_SUCCESS;
}
