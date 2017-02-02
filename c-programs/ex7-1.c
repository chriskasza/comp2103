/*
 * File: ex7-1.c
 * Prints a box of N asterisks
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Function: drawFullLine
 * Purpose:  prints numOfC occurrences of character c, 
 *   and then end-of-line
 * Inputs:   c and numOfC (parameters)
 * Returns: void
 * Error checking: Does nothing if numOfC is not positive
 * Sample call: draw('?', 3); 
 * 	Prints
 * 	???
 */
void drawFullLine(char c, int numOfC);

/*
 * Function: drawIntermediateLine
 * Purpose: prints character c, then numOfD-2 occurrences of d,
 *   then c, followed by end-of-line
 * Inputs: c, d, numOfD (parameters)
 * Returns: void
 * Error checking: Does nothing if numOfD is not positive
 * Sample call: draw('?', '$', 3); 
 * 	Prints
 * 	?$$$?
 */
void drawIntermediateLine(char c, char d, int numOfD);

/* 
 * main program that calls the above functions
 */
int main() {
	const int N = 4;
	const char STAR = '*';
	const char BLANK = ' ';
	int 	i;
 
	if(N < 3)  /* here, can not happen */
		return EXIT_FAILURE;

	drawFullLine(STAR, N);   /* draw the top line */
	for(i = 0; i < N - 2; i++)
		drawIntermediateLine(STAR, BLANK, N); 
	drawFullLine(STAR, N);  /* draw the bottom line */

	return EXIT_SUCCESS;
}

void drawFullLine(char c, int numOfC) {
	int i;

	for(i = 0; i < numOfC; i++)
		putchar(c);
	putchar('\n');
}

void drawIntermediateLine(char c, char d, int numOfD) {
	int i;

	putchar(c);
	for(i = 0; i < numOfD - 2; i++)
		putchar(d);
	putchar(c);
	putchar('\n');
}
