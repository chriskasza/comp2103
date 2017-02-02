/*
 * File: ex3-3.c 
 * Program that reads two integers and prints their sum
 * and difference; each on a separate line
 * Error checking: None.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
     int i, j;

     printf("Enter two integers:");
     scanf("%d", &i);
     scanf("%d", &j);

     printf("%d\n", i + j);
     printf("%d\n", i - j);

     return EXIT_SUCCESS;
}
