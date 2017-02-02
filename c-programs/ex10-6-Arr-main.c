#include <stdio.h>
#include <stdlib.h>
#include "ex10-6-Arr.h"
/*
 * File: ex10-6.c
 * Application of a dynamic array module to read a line of an unlimited length
 *  
 */
 
int main(int argc, char **argv) {
	FILE *f;
	int c, i, j;
	int line;  /* line counter */

	if(argc != 2) {
		fprintf(stderr, "usage %s fname\n", argv[0]);
		return EXIT_FAILURE;
	}
	if((f = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "can not open %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	printf("Reads lines from %s\n", argv[1]);
	construct_Arr(5);
	
	for(line = 1; ; line++) {	
	  for(i = 0; (c = fgetc(f)) != '\n'; i++) {
		if(c == EOF) {
			destruct_Arr();
			return EXIT_SUCCESS;
		}
		set_Arr(c, i);
	  }
		 
	  /* now, show this line */
	  printf("Line #%d:", line);
	  for(j = 0; j < i; j++)
		putchar(get_Arr(j));
	  putchar('\n');
	}
	 printf("\nbye\n");
	
	destruct_Arr();

	if(fclose(f) == EOF) {
		fprintf(stderr, "can not close %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

