/*
 * Exercise 6-1
 * Find the output produced by the following program:
 */
#include <stdio.h>
#include <stdlib.h>

#define LOW 2
#define HIGH (LOW + 5)
#define PR(arg) printf("%d\n", (arg))
#define FOR(arg) for(; (arg); (arg)--)
#define SHOW(x) x
int main() {
   int i = LOW;
   int j = HIGH;

   FOR(j)
      switch(j) {
      case 1: PR(i++);
      case 2: PR(j);
              break;
      default : PR(i);
    }
   printf("\n%s\n", SHOW("3"));
   return EXIT_SUCCESS;
} 
 
