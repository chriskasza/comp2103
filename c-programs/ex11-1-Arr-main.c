#include <stdio.h>
#include <stdlib.h>
#include "ex11-1-Arr.h"
/*
 * File: ex11-1-Arr-main.c
 * Application of a dynamic array module to read two lines of an unlimited length
 *  Lines are read from a file whose name is passed on the command line.
 */
 
int main(int argc, char **argv) {
	FILE *f;
	int c, i;
	Abstract_Enumeration e1, e2;
	Abstract_Arr a1, a2;
	const int initSize = 10;

	if(argc != 2) {
		fprintf(stderr, "usage %s fname\n", argv[0]);
		return EXIT_FAILURE;
	}
	if((f = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "can not open %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	if((a1 = construct_Arr(sizeof(char), initSize)) == NULL) {
		fprintf(stderr, "constructor failed\n");
		return EXIT_FAILURE;
	}
	
	if((a2 = construct_Arr(sizeof(char), initSize)) == NULL) {
		fprintf(stderr, "constructor failed\n");
		return EXIT_FAILURE;
	}
	for(i = 0; (c = fgetc(f)) != '\n'; i++) {
		if(c == EOF) {
			fprintf(stderr, "could not read first line\n");
			destruct_Arr(&a1);
			destruct_Arr(&a2);
			return EXIT_FAILURE;
		}
		set_Arr(a1, &c, i);
	}

	if(c == EOF) { /* emppty file */
		fprintf(stderr, "could not read first line\n");
		destruct_Arr(&a1);
		destruct_Arr(&a2);
		return EXIT_FAILURE;
	}

	for(i = 0; (c = fgetc(f)) != '\n'; i++) {
		if(c == EOF) {
			fprintf(stderr, "could not read second line\n");
			destruct_Arr(&a1);
			destruct_Arr(&a2);
			return EXIT_FAILURE;
		}
		set_Arr(a2, &c, i);
	}

	/* now, show both lines using two enumerations */
 
	e1 = construct_Enumeration(a1);
	e2 = construct_Enumeration(a2);
	printf("First line is:\n");
	while(hasMoreElements_Enumeration(e1))
		putchar(*nextElementTyped_Enumeration(char*, e1));
	putchar('\n');
	printf("Second line is:\n");
	while(hasMoreElements_Enumeration(e2))
		putchar(*nextElementTyped_Enumeration(char *, e2));
	putchar('\n');
	
	destruct_Arr(&a1);
	destruct_Arr(&a2);
	free(e1);
	free(e2);
	if(fclose(f) == EOF) {
		fprintf(stderr, "can not close %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

