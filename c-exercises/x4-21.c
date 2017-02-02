/*
 * Exercise 4-21
 * Program that reads five double values; the first two values represent the coordinates of a point,
 * say P, the next two values represent another point, say Q, and the last value represents the radius of a
 * circle that has its origin on point Q. Your program should check whether or not point P is inside the
 *  circle. Include full error checking and describe the boundary cases for testing this program. 
 *   LINK   -lm
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
   double px, py, qx, qy, r;

   /* To check if P is inside, test if distance(P, Q) < r */

   printf("Enter five double values representing two points P and Q and the radius of a circle \n");
   if(scanf("%lf%lf%lf%lf%lf", &px, &py, &qx, &qy, &r) != 5) {
        fprintf(stderr, "reading error\n");
        return EXIT_FAILURE;
   }
   /* check validity */
   if(r <= 0)  {
        fprintf(stderr, "wrong radius\n");
        return EXIT_FAILURE;
   }

   printf("Point P = (%f, %f), point Q = (%f, %f), radius R = %f\n", px, py, qx, qy, r);

   printf("P is %s inside of a circle that has its origin on Q and radius R\n",
        sqrt( pow(px - qx, 2) + pow(py - qy, 2) ) < r ? "" : "not");

   return EXIT_SUCCESS;
}
 
/* Boundary conditions; input values:
   0 0 2 2 1
   0 0 2 2 0.5
   0 0 2 2 0
 */
