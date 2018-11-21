/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c07e15-polyprops.h
 *
 * Functions to calculate the properties of polygons
 * 
 * layer modules add a customized interface to an existing module
 * package modules define new functions
 * type abstraction modules provide new data types, operations for the type, 
 * 	and a set of values
 * 
 */

#ifndef POLYPROPS_H
#define POLYPROPS_H

/* 
 * Function: calcArcs
 * Purpose: calculate the number of arcs in a complete polygon with n nodes
 * Inputs: number of nodes, n
 * Returns: the number of arcs
 * Error checking: 
 * Sample call: numArcs = calcArcs(numNodes)
 */
int calcArcs(int nodes);

#endif
