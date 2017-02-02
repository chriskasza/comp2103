/* 
 * File: ex9-8-main.c
 * Driver for ex9-8.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * File: ex9-8.c
 * Function: comptext
 * Purpose: compare two text files fname1 and fname2, line by line
 * Inputs: fname1, fname2, max (parameters)
 * Returns: 1 if identical, 0 if error or not identical
 * Modifies: nothing
 * Error checking: considers only first max characters in each line
 * Sample call:
 *    if(compText("a.dat", "b.dat", 80)  == 1) ...
 */
int comptext(const char *fname1, const char *fname2, const int max);


int main() {
	char f1[FILENAME_MAX];
	char f2[FILENAME_MAX];
	int d;
 
	printf("testing file comparison\n");
	printf("enter the name of the first file\n");
	if(scanf("%s", f1) != 1) {
		fprintf(stderr, "invalid string\n");
		return EXIT_FAILURE;
	}
	printf("enter the name of the second file\n");
	if(scanf("%s", f2) != 1) {
		fprintf(stderr, "invalid string\n");
		return EXIT_FAILURE;
	}

	printf("enter the maximum line legth\n");
	if(scanf("%d", &d) != 1) {
		fprintf(stderr, "invalid integer\n");
		return EXIT_FAILURE;
	}		 

	printf("Files %s and %s are %s equal\n", f1, f2,
			comptext(f1, f2, d) ? "" : "not");

	return EXIT_SUCCESS;

}
