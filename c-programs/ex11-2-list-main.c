#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char* strdup(const char*);

#include "ex11-2-list.h"
/*
 * File: ex11-2-list-main.c
 * Application of a LIST module 
 *  
 */

/* Callback functions */
DataType copyData_List(const DataType v) {
	return strdup(v);
}

void freeData_List(DataType v) {
	free(v);
}

int main(int argc, char **argv) {
	FILE *f; /* read strings */
	char buffer[81];
	char *aux;
	Abstract_Enumeration e1;
	Abstract_List a1;

	if(argc != 2) {
		fprintf(stderr, "usage %s fname\n", argv[0]);
		return EXIT_FAILURE;
	}
	if((f = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "can not open %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	if((a1 = construct_List()) == NULL) {
		fprintf(stderr, "constructor failed\n");
		return EXIT_FAILURE;
	}
	
	/* read from a file words and store them in the first list */
	while(fscanf(f, "%80s", buffer) == 1)  
		if(insert_List(a1, 0, buffer) == 0) {
			fprintf(stderr, "insert list failed\n");
			destruct_List(&a1);
			return EXIT_FAILURE;
		}
	if(fclose(f) == EOF) {
		fprintf(stderr, "file closing failed\n");
			destruct_List(&a1);
			return EXIT_FAILURE;
		}

	/* show what is in the list */
	e1 = construct_Enumeration(a1);
	printf("words backwards are:\n");
	while(hasMoreElements_Enumeration(e1)) {
		aux=nextElementTyped_Enumeration(char*, e1);
		printf("%s\n", aux);
		free(aux);
	}
	free(e1);
 
	return EXIT_SUCCESS;
}
