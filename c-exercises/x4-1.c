/*
 * Exercise 4-1
 * Output from the following program
*/
#include <stdio.h>
#include <stdlib.h>
int main() {
   double x = 16.5;
   double y = 2.5;
   int z = 0; 

   while(x > y) {
      x -= y;
      z++;
   }

   printf("%d %g\n", z, x);
   /* z is equal to 16.5/2.5, truncated */

   return EXIT_SUCCESS;
}
