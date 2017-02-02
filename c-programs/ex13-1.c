/* 
 * File: ex13-1.c
 * Functions operating on bits
 *
 */ 
#define MASK(j)	(1 << j)

/*
 * Function: getBit
 * Purpose: return the value of the j-th bit in word
 * Inputs: word w and position j
 * Returns: Value if the j-th bit of w 
 * Modifies: nothing
 * Error checking: none
 * Sample call:
 *    i = getBit(w, 2);
 */
int getBit(int w, unsigned j) {
	return ((w & MASK(j)) == 0) ? 0 : 1;
}

/*
 * Function: setBit
 * Purpose: set the value of the j-th bit in word
 * Inputs: word w, position j, and the value to set to: 0 or 1
 * Returns: modified word
 * Modifies: nothing
 * Error checking: If the value to set to is not 1 or 0, does nothing
 * Sample call:
 *    setBit(w, 2, 1);
 */
int setBit(int w, unsigned j, short value) {
	switch(value) {
	case 0:	return w & MASK(j);
	case 1: return w | MASK(j);
	default: return w;  /* unchanged */
	}
}

/*
 * Application of the above functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void help() {
	printf("Help\n");
	printf("Enter\nW i - to enter a new word\n");
	printf("G i - to get the value of the i-th bit\n");
	printf("S i j - to set the value of the i-th bit to j\n");
	printf("H for help\n");
	printf("Q to quit\n");
}

#define Max  80
int main() {
	unsigned w, i, j;
	char buffer[Max+1];
	int error = 0;
	
	printf("Program to test bitwise operations, values are displayed in hexadecimal\n");
	help();
	while(fgets(buffer, Max, stdin) != NULL) {
		switch(tolower(buffer[0])) {
		case 'w':
			if((error = (sscanf(buffer + 1, "%u", &w) != 1)) == 0)
				printf("current word is %x\n", w);
			break;
		case 'g': 
			if((error = (sscanf(buffer + 1, "%u", &i) != 1)) == 0)
				printf("The %u-th in %x is %u\n", i, w, 
					getBit(w, i));
			break;
		case 's':
			if((error = (sscanf(buffer + 1, "%u%u", &i, &j) != 2)) == 0) {
				printf("The word before modification is %x\n", w);
				w = setBit(w, i, j);
				printf("The word after setting the %u-th bit to %u is %x\n",
					 i, j, w);
			break;
		case 'h':
			help();
			break;
		case 'q': 
			printf("bye\n");
			return EXIT_SUCCESS;
		default: 
			error = 1;
			break;
		}
		if(error) {
			printf("wrong option entered\n");
			error = 0;
		}
	}}
 return EXIT_SUCCESS;  
}

