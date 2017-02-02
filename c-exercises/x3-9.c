/*
 * Exercise 3-9
 * Test various expressions
*/
#include <stdio.h>
#include <stdlib.h>
int main() {

  int condition1 = 1;
  int condition2 = 0;
  int check;
  double d, e, f;

  check = condition1 && condition2 != 0;
  d = 1 / 2 * check;
  e = (double)1 * 2;
  f = (double)(3 / 2);

  printf("check is: %d\nd is: %f\ne is: %f\nf is: %f\n", check, d, e, f);

  return EXIT_SUCCESS;
}
