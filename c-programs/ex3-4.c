/* 
 * File: ex3-4.c
 * Program that reads two integers and prints their sum
 *   and difference; each on a separate line
 * Error checking: terminates if either of the read 
 *   operations fails.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
     double i, j;

     printf("Enter two double values:");
     if(scanf("%lf%lf", &i, &j) != 2) {
	 printf("incorrect double values\n");
         return EXIT_FAILURE;
     }
      
     printf("sum = %f\ndifference = %f\n", i + j, i - j);

     return EXIT_SUCCESS;
}
