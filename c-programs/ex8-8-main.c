/* 
 * File: ex8-8-main.c
 * Driver for function from ex8-8.c
 */

#include <stdio.h>
#include <stdlib.h>

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
void tabulate(double low, double high, double step, double (*f)(double));

/*
 * Two simple functions for sample tabulation
 */
double pol1(double x) {
     return x*x - 2;
}

double pol2(double x) {
     return x*x*x - 2*x + 5;
}

/*
 * Program that tests tabulation
 */
int main()
{
     /* Hardcoded trial runs to show examples of this program */
     tabulate(-1.0, 1.0, 0.01, pol1);          
     tabulate(-2.0, 2.0, 0.02, pol2);          

    return EXIT_SUCCESS;
}
