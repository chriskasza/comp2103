#include <stdio.h>
/*
 * File: ex8-8.c
 * Function: tabulate
 * Purpose: tabulate function
 * Inputs: low and high that define the range of tabulation;
 *	    step which defines the granularity, and f - a function to
 *	    tabulate (parameters)
 * Outputs: prints tabulation
 * Modifies: nothing
 */
void tabulate(double low, double high, double step, double (*f)(double) ) {
     double x;
          
     for (x = low; x <= high; x += step)
          printf("%13.5f %20.10f\n", x, f(x));
}
