/*
 * File: ex3-2.c
 * Program that reads two characters and prints them in 
 *   reverse order, separated by a tab and ending with end of line.
 * Single character, unformatted I/O operations are used. 
 * Error checking: Program terminates if either of the 
 *  input operations fails.
 *  No error checking for the output operations.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
     int c, d;		 

     if((c = getchar()) == EOF) {
	  fprintf(stderr, "input operation failed\n");
	  return EXIT_FAILURE;
     }
     if((d = getchar()) == EOF) {
	  fprintf(stderr, "input operation failed\n");
	  return EXIT_FAILURE;
     }

     putchar(d);		 
     putchar('\t');		 
     putchar(c);		 
     putchar('\n');		 

     return EXIT_SUCCESS;
}
