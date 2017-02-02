/* 
 * File: ex8-4.c
 *
 * Function: textToBinary
 * Purpose: read a text file containing double values and 
 *          store these values in a binary file.
 * Inputs: two file names, tname for the input text file 
 *	bname for the output binary file
 * Returns: 1 if successful, otherwise 0
 * Modifies: the output file (overwrites the existing file)
 * Error checking: Full
 * Sample call:
 *    if(textToBinary("a.txt", "a.bin") == 0)
 *	error
 */
int textToBinary(const char *tname, const char *bname);

/*
 * Function: binaryToText
 * Purpose: read a binary file containing double values and store these
 *     values in a text file; up to 10 values per line
 * Inputs: two file names, bname for the input binary file 
 *	tname for the output text file
 * Returns: 1 if successful, otherwise 0
 * Modifies: the output file (overwrites the existing file)
 * Error checking: Full
 * Sample call:
 *    if(binaryToText("b.bin", "b.txt") == 0)
 *	error
 */
int binaryToText(const char *tname, const char *bname);

#define SKIP 	while(getchar() != '\n');
#include <stdio.h>
#include <stdlib.h>
/*
 * Main program
 * The user can choose to convert a text file containing double values
 *	to a binary file called "junk.bin"
 *	or to convert a binary file containing double values
 *	to a text file called "junk.txt"
 */
int main() {

	/* FILENAME_MAX is the maximum size of the file name */
	char *tname;
	char *bname;
	int noSkip = 1;	/* flag */

	printf("This programs converts text files to binary files and back\n");

	if((tname = malloc(FILENAME_MAX*sizeof(char))) == NULL)
		return EXIT_FAILURE;
	if((bname = malloc(FILENAME_MAX*sizeof(char))) == NULL) {
		free(tname);
		return EXIT_FAILURE;
	}

	printf("To convert a text file into a binary file\n");
	printf("press y or Y, to skip this conversion press any other character\n");
	switch(getchar()) {
		case 'y':
		case 'Y': break;
		case '\n': noSkip = 0;
			   break;
		default: noSkip = 0;
			 SKIP
		         break;
	}

	if(noSkip == 1) {
 	 printf("Enter the name of the text file:\n");
	 printf(" (one word, no more than %d characters)\n", FILENAME_MAX);
 	 if(scanf("%s", tname) != 1)
		return EXIT_FAILURE;
	SKIP
   
  	printf("Text file %s is converted to a binary file %s\n", 
		tname, "junk.bin");
  	printf("Conversion %s successful\n", 
    		(textToBinary(tname, "junk.bin") == 0) ? "not" : "");
}

	printf("To convert a binary file into a text file \n");
	printf(" press y or Y, to terminate press anything else\n");
	switch(getchar()) {
	case 'y':
	case 'Y': break;
	case '\n': 
	default: return EXIT_FAILURE;
	}
	SKIP

	printf("Enter the name of the binary file:\n");
	printf("(one word, no more than 20 characters) ");
	if(scanf("%s", bname) != 1)
		return EXIT_FAILURE;
	SKIP
	printf("Binary file %s will be converted to a text file %s\n", 
		bname, "junk.txt");
	printf("Conversion %s successful\n", (binaryToText(bname, "junk.txt") == 0) ?
			"not" : "");

	return EXIT_SUCCESS;
}

/* auxiliary macros to open and close a file */
#define OPEN(f, fname, mode)   if((f = fopen(fname, mode)) == NULL) \
				return 0;

#define CLOSE(f)   if(fclose(f) == EOF) \
				return 0;

int textToBinary(const char *tname, const char *bname) {
	FILE *in;
	FILE *out;
	double d;

	OPEN(in, tname, "r")
	OPEN(out, bname, "wb")
	 
	while(fscanf(in, "%lf", &d) == 1) 
		if(fwrite(&d, sizeof(double), 1, out) != 1) {
			fclose(in);
			fclose(out);
			return 0;
		}
	CLOSE(in)
	CLOSE(out)
	return 1;
}


int binaryToText(const char *bname, const char *tname) {
	FILE *in;
	FILE *out;
	double d;
	int i;
	const int MAX = 10;

	OPEN(in, bname, "rb")
	OPEN(out, tname, "w")
	i = 0;
	while(fread(&d, sizeof(double), 1, in) == 1) {
		i++;
		if(i == MAX) {
			putchar('\n');
			i = 0;
		}
		fprintf(out, "%f\t", d);
	}

	CLOSE(in)
	CLOSE(out)
	return 1;

}
