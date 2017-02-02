/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       book.c
 *
 * Telephone book program that has the following functionality:
 * 1. search book
 * 2. add entry
 * 3. remove entry
 * 4. list all entries
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Function: cleanStdin
 * Purpose: clear STDIN buffer
 * Inputs: -
 * Returns: returns 1 when completes successfully
 * Error checking: -
 * Sample call: cleanStdin();
 * 	discards remaining characters in STDIN
 */
int cleanStdin() ;

/*
 * Function: mainMenu
 * Purpose: print the main menu and accept menu choice
 * Inputs: -
 * Returns: returns int which corresponds to a menu choice
 * Error checking: continues to prompt until valid int is entered
 * Sample call: mainMenu();
 * 	prints menu and prompts for menu choice
 */
int mainMenu() ;

/*
 * Function: addEntry
 * Purpose: add a new entry to the phone book
 * Inputs: f (parameter)
 * Returns: returns 1 when entry successfully added to phone book; 0 if not
 * Error checking: will return 0 if phone book file doesn't exist
 * Sample call: addEntry(filehandle);
 * 	Prints
 * 	"Type in your entry, terminate with a single RETURN on the line: "
 * 	Accepts entry input and writes to file, f.
 */
int addEntry(FILE *f) ;

int main() {
	FILE *f;
	int numRecords;
	int c;
	int flag;  // EOF flag to break from loop
	f = "book.dat";
	int debug = 1; // flag for debug messaging


	printf("My Phone Book (using book.dat\n");
	printf("%f doesn't exist.  Do you want to create one? (y/n) ");

	while((c = getchar()) != EOF) {
		flag = 0;
		switch(c) {
			case 'y':
			case 'Y':
				flag = 1;
				// create file
				break;
			case 'n':
			case 'N':
				// quit
				printf("Goodbye.\n");
				return EXIT_SUCCESS;
				break;
			default: 
				printf("%f doesn't exist.  Do you want to create one? (y/n) ");
		}
		if(flag == 1) { break; }
	}

	if((fopen(f, "w+")) == NULL) {
		// open phone book file (f) with r/w
		fprintf(stderr, "can't open %s\n", f);
		return EXIT_FAILURE;
	}

	while(
		
	while((c = fgetc(f)) != EOF) {
		if(c == '/') {
			// check for comment character '/'
			if((d = fgetc(f)) == EOF) {
				// EOF detected; print c and quit
				fprintf(stdout, "%c",c);
				flag = 1;
 			} else if(d == '/') {
				// ignore comment to end of line 
				while(1) {
					if((((d = fgetc(f)) == EOF) && (flag = 1)) || d == '\n') {
						fprintf(stdout, "\n");
						break;
					}
				}
			} else if(d == '*') {
				// ignore comment to '* /'
				while(1) {
					if((d = fgetc(f)) == EOF) {
						flag = 1;
						break;
					} else if(d == '*') {
						if((e = fgetc(f)) == EOF) {
							flag = 1;
							break;
						} else if(e == '/') {
							break;
						}
					}
				}
			} else {
				fprintf(stdout, "%c",c);
				fprintf(stdout, "%c",d);
			}
		} else {
			fprintf(stdout, "%c",c);
		}

		if(flag == 1) {
			break;
		}
	}

	return EXIT_SUCCESS;
}


int cleanStdin() {
{
	while(getchar() != '\n');
	return 1;
}

int mainMenu() {
	int n;

	printf("Available commands:\n");
	printf("\t1. Look someone up\n");
	printf("\t2. Add someone to the phone book\n");
	printf("\t3. Remove someone from the phone book\n");
	printf("\t4. List all names and numbers in the phone book\n");
	printf("\t5. Change the prompt\n");
	printf("\t6. See the menu\n");
	printf("\t7. Exit the program\n");
	printf("Please select one of the above (1-7): ");

	while (((scanf("%d%c", &n, &c) != 2 || c != '\n') && cleanStdin()) || 
			n < 1 || n > 7) {
		printf("Please select one of the above (1-7): ");
	}
		
	return n;
}
