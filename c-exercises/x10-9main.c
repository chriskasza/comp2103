/*
 * File: x10-9main.c
 * Application of a dynamic array module to read a line of an unlimited length
 * with added shrink capability
 *  
*/
 
#include <stdio.h>
#include <stdlib.h>
#include "x10-Arr.h"

#define SIZE (5)

int main(int argc, char **argv) {
	FILE *f;
	int c, i;
	int max;

	if(argc != 2) {
		fprintf(stderr, "usage %s fname\n", argv[0]);
		return EXIT_FAILURE;
	}
	if( (f = fopen(argv[1], "r") ) == NULL) {
		fprintf(stderr, "can not open %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	construct_Arr( SIZE );
	

	for( i = 0; ( c = fgetc( f ) ) != '\n'; i++ ) {
         if( c == EOF ) {
            fprintf(stderr, "could not read a line\n");
            fclose(f);
            destruct_Arr();
            return EXIT_FAILURE;
         }
	
         set_Arr( c, i );
        }
	max = i;

		 
	/* now, show this line */
	printf("The line is:");
	for(i = 0; i < length_Arr(); i++)
		putchar(get_Arr(i));
	printf("\nend-of-line\n");
	

	/* now try to add a large value to test shrink */
	set_Arr(c, max * 2 );

	/* now shrink it */
        i = 5;
	shrink_Arr( i );
        printf("the same line again; with only %d characters\n", i);
	for(i = 0; i < length_Arr(); i++)
           putchar(get_Arr(i));
        printf("\nend-of-line\n");

	destruct_Arr();

	if(fclose(f) == EOF) {
		fprintf(stderr, "can not close %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
