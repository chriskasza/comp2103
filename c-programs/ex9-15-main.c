/*
 * File: ex9-15.c
 * Program that uses string tokenizer to read a file in the delimited format
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex9-token.h"

/* 
 * Main program tests the above function 
 *  
 */
int main(int argc, char *argv[]) { 
    FILE *in;
    const char *delim = "|";
    const int SIZE = 81;
    char *line;
    char *nameS;
    char *salaryS;
    char *idS;  /* Mary Smith|2000|1 */
    double salary;
    long id;
    char *err = NULL; /* error in conversion */
    
    /* expects filename in the command line */
    if(argc != 2) {
	fprintf(stderr, "usage: program filename\n");
	return EXIT_FAILURE;
    }
    if((in = fopen(argv[1], "r")) == NULL) {
	fprintf(stderr, "can't read %s\n", argv[1]);
	return EXIT_FAILURE;
    }
    if((line = calloc(81, sizeof(char))) == NULL) {
	fprintf(stderr, "construction failed\n");
	return EXIT_FAILURE;
    }

    while(fgets(line, SIZE, in) != NULL) {
        line[strlen(line)-1]= '\0';
	construct_Token(line, delim);
	if(hasMore_Token()) 
		nameS = next_Token();
	else { /* error */
		fprintf(stderr, "can't get name, wrong file format\n");
		break; 
	}
	if(hasMore_Token()) 
		salaryS = next_Token();
	else { /* error */
		fprintf(stderr, "can't get salary, wrong file format\n");
		break; 
	}
	if(hasMore_Token()) 
		idS = next_Token();
	else { /* error */
		fprintf(stderr, "can't get id, wrong file format\n");
		break; 
	}
	salary = strtod(salaryS, &err);
	if(err == salaryS) { /* error */
		fprintf(stderr, "wrong salary format\n");
		break; 
	}
	id = strtol(idS, &err, 10);	
	if(err == idS) { /* error */
		fprintf(stderr, "wrong id format\n");
		break; 
	}
	/* ready to print */
	printf("Name: %s, salary %f, id: %ld\n", nameS, salary, id);
	destruct_Token();
     }
     (void)fclose(in);

   return EXIT_SUCCESS;
}

