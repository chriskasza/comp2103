/* 
 * File: ex4-3.c
 * Program that outputs the roots of the equation 
 *   Ax^2+Bx+C = 0.
 * No check for valid real coefficients.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
     double a, b, c, delta, xr, yr;

     printf("Enter three real values: ");
     scanf("%lf%lf%lf", &a, &b, &c);

     delta = b*b - 4*a*c;
     delta = sqrt(delta);
     xr = (-b - delta)/(2*a);
     yr = (-b + delta)/(2*a);
     printf("\nFirst solution:  %f\n", xr);
     printf("\nSecond solution:  %f\n", yr);

     return EXIT_SUCCESS;
}
/*
Enter three real values: 1 -2 1
First solution: 1
Second solution: 2
*/

