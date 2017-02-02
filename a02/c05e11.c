/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c05e11.c
 *
 * Output contents of input with all C comments removed.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *f;
	int c, d, e;
	int flag = 0;  // EOF flag to break from loop
	f = stdin;
	int debug = 1; // flag for debug messaging
	
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
