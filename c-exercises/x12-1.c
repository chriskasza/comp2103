/*
 * File: x12-1.c
 * Program to represent the days of the week using
 * an enumerated type DAYS.
 * Operations: an operation is provided to print the day of the week
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum DAYS{ Monday = 0, Teusday, Wednesday, Thursday, 
		Friday, Saturday, Sunday} DAYS;

/*
 * Function: printDay
 * Purpose:  prints the day of the week
 * Inputs:   d
 * Returns:  --
 * Error checking: checks to make sure d is a valid DAYS type
 */
void printDay( DAYS d  ){

	switch( d ){
		case Monday: printf("Monday\n"); break;
		case Teusday: printf("Tuesday\n"); break;
		case Wednesday: printf("Wednesday\n"); break;
		case Thursday: printf("Thursday\n"); break;
		case Friday: printf("Friday\n"); break;
		case Saturday: printf("Saturday\n"); break;
		case Sunday: printf("Sunday\n"); break;
		default: printf("Not recognized\n");	
	}
}


int main() {
	DAYS day;
	int i;

	day = Monday;
	printf("Day is \t"); 
        printDay( day );

	printf("Trying something different ...\n");
	for(i = (int)Monday; i < (int)Thursday; i++){
	    printf("Day is \t"); 
            printDay( (DAYS)i );
	}

	return EXIT_SUCCESS;
}

