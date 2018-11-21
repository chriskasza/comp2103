/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c07e15-polyprops.c
 *
 * Functions to calculate the properties of polygons
 * 
 * layer modules add a customized interface to an existing module
 * package modules define new functions
 * type abstraction modules provide new data types, operations for the type, 
 * 	and a set of values
 * 
 */

/* Function: calcArcs */
int calcArcs(int nodes) {
	int remainingNodes, connections;

	if(nodes <= 1) {
		return 0;
	}

	remainingNodes = nodes - 1;
	connections = remainingNodes + calcArcs(remainingNodes);
	return connections;
}

