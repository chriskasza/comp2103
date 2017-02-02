/*
 * Exercise 4-17
 * Program that reads an integer value n, and then prints all of the prime numbers less than n. 
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
   int n, i, j, prime;

   printf("Enter a positive integer value\n");
   if(scanf("%d", &n) != 1 || n < 1) {
      fprintf(stderr, "incorrect value\n");
      return EXIT_FAILURE;
   }
   
   printf("prime numbers less than %d\n", n);
   for(i = 3; i < n; i += 2) {
      for(prime = 1, j = 3; j < i; j++) 
         if(i%j == 0) { /* not prime */
            prime = 0;
            break;
         }
      if(prime)
        printf("%d\n", i);
   }

   return EXIT_SUCCESS;
}
 
