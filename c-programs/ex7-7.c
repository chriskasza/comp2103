/*
 * File: ex7-7.c
 * Illustrates a function with a variable number  
 *	of arguments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double product(int number,...);

int main() {
  printf("%f\n", product(2,2.0,3.0) * product(1,4.0,5.0));
 
  return EXIT_SUCCESS;
}

/* return a product of double arguments */
double product(int number, ...) {
  va_list list;
  double p;
  int i;

  va_start(list, number);
  for(i = 0, p = 1.0; i < number; i++)
	p *= va_arg(list, double);
  va_end(list);

  return p;
}
