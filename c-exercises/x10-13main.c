/*
 * File: x10-13main.c
 * Application of the module find to test it
 * The program expects a single command line argument containing the name
 * 	of a text file. It then searches for some predefined constants in the
 *		file
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "x10-13find.h"
#define SIZE  (100)

int main(int argc, char *argv[]){
	char *string;
	int pos;

	if( argc < 2 ){
		fprintf(stderr, "usage: pname filename\n");
		return EXIT_FAILURE;
	}

	if( (string = calloc(SIZE, sizeof(char) ) ) == NULL ){
		fprintf(stderr, "Memory allocation failed\n");
		return EXIT_FAILURE;
	}

	if( construct_Find( argv[1] ) == 0){
            free(string);
            fprintf(stderr, "could not construct module\n");
            return EXIT_FAILURE;
	}

	while ( 1) {
		printf("Enter a string and a position ");
		if( scanf("%s%d", string, &pos ) != 2){
			fprintf(stderr, "Error reading string / pos pair\n");
                        free(string);
                        destruct_Find();
			return EXIT_FAILURE;
		}
		if( search_GlobalFind(string) == 1 )
			printf("Global find found the string\n");
		else printf("Global find did not find the string\n");
		if( search_Find( string, pos ) == 1)
			printf("local find found the string\n");
		else printf("Local find did not find the string\n");
		show_Find( pos );
	}

	free( string );
	destruct_Find();
	return EXIT_SUCCESS;	
}

