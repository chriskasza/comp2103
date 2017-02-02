/*
 * File: ex8-7.c
 * Demonstrates the dangling reference 
 */

#include <stdio.h>
#include <stdlib.h>

int *pi;    /* global pointer  */
     
void f() {
     int i = 2;

     pi = &i;      /* global pointer now points to the value
                      allocated on the stack  */
     printf("Inside f the value pointed to by pi is %d\n", *pi);
/* 
 * when f terminates, the location used by i can be reused  
 */
}

/* merely reuses the stack location  */
void confuse() {
     int x = 5;
}

/* calls f and then confuse  */
int main() {
     f();
     printf("After f terminates this value is %d\n", *pi);
     confuse();
     printf("After confuse terminates this is %d\n", *pi);

     return EXIT_SUCCESS;
}
