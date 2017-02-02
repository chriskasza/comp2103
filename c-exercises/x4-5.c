/*
 * Exercise 4-5
 * Program that reads three double values (include a prompt) and 
 * outputs the largest value
 *   (for the output, use a field of width 10, and 4 significant
 *    digits). Full error checking should be provided. 
 *   The same program using float values.
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
   double one, two, three;

   printf("Enter three double values\n");
   if(scanf("%lf%lf%lf", &one, &two, &three) != 3) {
      fprintf(stderr, "Reading error\n");
      return EXIT_FAILURE;
   }
   
   printf("The largest values = %10.4f\n",
      one > two 
           ? (one > three ? one : three)
           : (two > three ? two : three)
    );

   return EXIT_SUCCESS;
}
 
