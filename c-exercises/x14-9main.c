/*
 * File: x14-9main.c
 * Program that uses string tokenizer to read a file in the delimited format
 *  and output all tokens. Provides the option of using either the deep 
 *  or shallow copy
 */


#define LINE_SIZE		(81)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "x14-9token.h"

#define DEEP 

/* 
 * Main program tests the above function 
 *  
 */
int main(int argc, char *argv[]) { 
    FILE *in;
    const char *delim = " ";
    const int SIZE = 81;
    char *line;
    char *str;
    AbstractToken tok;
    
    /* expects filename in the command line */
    if(argc != 2) {
		fprintf(stderr, "usage: program filename\n");
		return EXIT_FAILURE;
    }
    if((in = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "can't read %s\n", argv[1]);
		return EXIT_FAILURE;
    }
    if((line = calloc(LINE_SIZE, sizeof(char))) == NULL) {
        fclose(in);
	fprintf(stderr, "construction failed\n");
	return EXIT_FAILURE;
    }

    while(fgets(line, SIZE, in) != NULL) {
		line[ strlen(line)-1 ] = '\0';

		tok = construct_Token(line, delim);
		while( hasMore_Token( tok )){
			#ifdef DEEP
				str = next_TokenDeep( tok );
				printf("The next token is %s \n", str);
				free( str );
			#else
				str = next_TokenShallow( tok );	
				printf("The next token is %s \n", str);
			#endif
		}
  }
  /* ready to print */

   destruct_Token( &tok);
   if(fclose(in) == EOF)
      return EXIT_FAILURE;

   return EXIT_SUCCESS;
}
