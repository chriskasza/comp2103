/*
 * Exercise 4-13
 * Program that inputs the integer value representing a year, and prints whether this
 * year is a leap year. Include full error checking.
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
   int n;
   int leap;

  /* a leap year is divisable by 4, but not by 100 unless it is divisable by 400 */
  
   printf("Enter a value representing a year\n");
   if(scanf("%d", &n) != 1 || n < 1) {
      fprintf(stderr, "incorrect value\n");
      return EXIT_FAILURE;
   }
   
   leap = n%4 == 0 && (n%400 == 0 || n%100 != 0);
   printf("Year %d is %s leap\n", n, leap ? "" : "not");

   return EXIT_SUCCESS;
}
 
