/*
 * File: ex7-5-io2-main1.c
 * An application of the file I/O module IO2
 * Reads from a file of integers; outputs to a file valid integers and 
 * for invalid integers outputs an error message and skips a single input
 * character
 * Stops after having read 10 valid integers
 * Menu driven program
 */
#include "ex7-5-io2.h"
#include <stdio.h>
#include <stdlib.h>
/* Displays available commands */
void help() {
    printf("enter\n");
    printf("\th for help\n");
    printf("\ti to use the standard input stream\n");
    printf("\tj to read an integer from the current input file\n");
    printf("\to to use the standard output stream\n");
    printf("\tp to write an integer to the current output file\n");
    printf("\tf to read from a file\n");
    printf("\tg to write to a file\n");
    printf("\tw to close input\n");
    printf("\ty to close output\n");
    printf("\tq to quit\n");
}

#define SKIP 	while(getchar() != '\n');

/* reads in user's command and executes the corresponding command */
void menu() {
  int c, d;
  char filename[FILENAME_MAX];

  while(1) {
    printf("> (h for help): ");
    c = getchar();
    SKIP

    switch (c) {
    case 'h':
    case 'H':
		help();
                break;
    case 'i':
    case 'I':	
		if(constructRead_IO2(NULL) == FAIL_IO2)
	      		fprintf(stderr, "failed opening standard input\n");
		break;
    case 'j':
    case 'J':	
		clearError_IO2();
		d = getInt_IO2();
		if(isError_IO2())
			printError_IO2();
		else printf("read %d\n", d);
		break;
    case 'o':
    case 'O':	
		if(constructWrite_IO2(NULL) == FAIL_IO2)
	      		fprintf(stderr, "failed  opening standard output\n");
		break;
    case 'p':
    case 'P':	
		printf("Enter an integer value:");
		if(scanf("%d", &d) != 1) {
			SKIP
			printf("invalid integer\n");
			break;
		}
		SKIP
		clearError_IO2();
		putInt_IO2(d);
		if(isError_IO2())
			printError_IO2();
		break;
    case 'f':
    case 'F':	
	        printf("input file filename: ");
		if(scanf("%s", filename) != 1) {
			SKIP
			fprintf(stderr, "can't read %s\n", filename);
			break;
		}
		SKIP
		if(constructRead_IO2(filename) == FAIL_IO2)
	      		fprintf(stderr, "failed using %s\n", filename);
		break;
    case 'g':
    case 'G':	
	        printf("output file filename: ");
		if(scanf("%s", filename) != 1) {
			SKIP
			fprintf(stderr, "can't read %s\n", filename);
			break;
		}
		SKIP
		if(constructWrite_IO2(filename) == FAIL_IO2)
	      		fprintf(stderr, "failed using %s\n", filename);
		break;
    case 'w':
    case 'W':
	 	if(destructRead_IO2() == FAIL_IO2)
	      		fprintf(stderr, "failed closing input\n");
		break;
    case 'y':
    case 'Y':
	 	if(destructWrite_IO2() == FAIL_IO2)
	      		fprintf(stderr, "failed closing output\n");
		break;
    case 'q':
    case 'Q': 
	       if(destructReadWrite_IO2() == FAIL_IO2)
		   fprintf(stderr, "failed to clean up\n");
               return;
    default :
             fprintf(stderr, "\nunknown command\n");
             break;
    }
 }
}

int main() {
   menu();
   return EXIT_SUCCESS;
}

