/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c07e15-driver.c
 *
 * Prints out the number of arcs in a polygon having 5, 6, and 7 nodes
 */

#include <stdio.h>
#include <stdlib.h>
#include "c07e15-polyprops.h"

int main() {
	int numArcs, i;
	
	for(i=5; i<8; i++) {
		numArcs = calcArcs(i);
		printf("For a polygon with %d nodes, ", i);
		printf("the number of arcs is %d.\n", numArcs);
	}

	return EXIT_SUCCESS;
}
