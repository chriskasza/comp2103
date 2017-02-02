/*
 * File: x11-1.c
 * The ElemT type is defined, and a function Show. File also includes
 * a simple program to test.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX		(100)
#define MARY	        "Mary"
#define NAME_SIZE	(100)

typedef struct{
	double something;
	char *name;
} ElemT;


/*
 * Function: InitData
 * Purpose:  to initialize incoming data 
 * Inputs:   data
 * Returns:  --
 * Modifies:  data
 * Error checking: -- 
 */
static void InitData( ElemT data[] ) {
	int i;

	for(i = 0; i < MAX; i++) {
		data[i].name = NULL;
		data[i].something = 0.0;  /* unused here */
	}
}

/*
 * Function:  show
 * Purpose:  to  count the number of occurences of the string MARY in data
 * Inputs:   data, numMarys
 * Returns:  --
 * Modifies:  sets numMarys to the number of occurences of the string MARY in data
 * Error checking:  --
 */
static void show( ElemT data[], int *numMarys ) {
	int i;

	*numMarys = 0;
	for(i = 0; i < MAX; i++)
		if( data[i].name && strcmp(data[i].name, MARY) == 0)	
			(*numMarys) += 1;
}

/*
 * Function:  freeAll
 * Purpose:  to free memory
 * Inputs:   data 
 * Returns:  --
 * Modifies:  deallocates memory that has been allocated for strings
 * Error checking:  --
 */
static void freeAll( ElemT data[] ) {
	int i;

	 for(i = 0; i < MAX; i++)
		if( data[i].name )	
			free(data[i].name);
}

int main() {
	ElemT data[MAX];
	char name[100];
	int size = 0;
        int numMarys;

	InitData( data );

	/* build data */
	while(1) {
		printf("Enter a name, <quit to finish entering names> >");
		if( scanf("%s", name) != 1) {
			fprintf(stderr, "Incorrect input\n");
			return EXIT_FAILURE;
		}
		if( strcmp( name, "quit") == 0 ) {
			printf("Done\n");
			break;
		}
	 
		if( (data[size].name = calloc(NAME_SIZE, sizeof(char))) == NULL ) {
			fprintf(stderr, "Memory allocation failed\n");
			return EXIT_FAILURE;
		}
		strncpy(data[size].name, name, NAME_SIZE-1);
		size++;
	}

	/* count the number of Mary strings */
	show( data, &numMarys);
	printf("The number of strings \"Mary\" is %d\n", numMarys);
        freeAll(data);

	return EXIT_SUCCESS;	
}

