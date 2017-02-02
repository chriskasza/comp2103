/*
 * File: ex9-16.c
 * Displays the number of arguments on the command line
 *  followed by each of these arguments  
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
     int i;

     printf("This program has %d arguments\n", argc);
     for (i = 0; i < argc; i++)
          printf("%s\n", argv[i]);

     return EXIT_SUCCESS;
}
