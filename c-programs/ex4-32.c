/* 
 * File: ex4-32.c
 * Program that outputs the roots of the equation 
 *   Ax^2+Bx+C = 0.
 * Roots may be real values or complex values
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
     double a, b, c, delta;
     double xr = 0;
     double xi = 0;
     double yr = 0;
     double yi = 0;

     printf("Enter three real values: ");
     if(scanf("%lf%lf%lf", &a, &b, &c) != 3) {
		printf("incorrect values\n");
		return EXIT_FAILURE;
     }

     if(a == 0) 
          if (b == 0) 
               printf("Degenerate equation %f = 0\n", c);
          else 
               printf("Only one solution: %f\n", -c/b);
     else { /* a != 0 */
            delta = b*b - 4*a*c;
	  	xr = yr = -b/(2*a);
	  	if(delta == 0)
			printf("\nOne double solution:  %f\n", xr);
             else if(delta < 0) {
	       	printf("Complex solutions\n");
                  delta = sqrt(-delta);
                  xi = delta/(2*a);
                  yi = -xi;
           	} else {	/* delta > 0 */
               		delta = sqrt(delta);
               		xr += delta/(2*a);
               		yr -= delta/(2*a);
          	}
        	printf("\nFirst solution:  %f + i*(%f)\n", xr, xi);
          	printf("\nSecond solution: %f + i*(%f)\n", yr, yi);
     }

	return EXIT_SUCCESS;
}
