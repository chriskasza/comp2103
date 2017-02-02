/*
 * File: ex9-17.c
 * Displays up to n lines from a file
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Function: display
 * Purpose: display up to n lines from a file
 *   Lines are truncated to max characters
 * Inputs: filename, n and max (parameters)
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing
 * Error checking: fails if the file can not be open
 * Sample call:
 *    if(display("ex9-17.c", 20) == 0)
 *	error
 */
int display(const char *fname, int n, int max);

#define DEFAULT 10
#define MAX 80

int main(int argc, char **argv) {
	int lines = DEFAULT;

	switch(argc) {
	case 3:
		if(sscanf(argv[1]+1, "%d", &lines) != 1 || lines <= 0) {
		    fprintf(stderr, "incorrect argument %s\n", argv[1]+1);
		    return EXIT_FAILURE;
		}
		argv++;
	case 2:
		if(display(argv[1], lines, MAX) == 0) {
    		    fprintf(stderr, "incorrect argument %s\n", argv[1]);
		    return EXIT_FAILURE;
		}
		break;
	default: fprintf(stderr, "usage: %s [-b] file\n", argv[0]);
		return EXIT_FAILURE;
	}

     return EXIT_SUCCESS;
}

int display(const char *fname, int n, int max) {
	FILE *in;
	char *line;
	int i;
 
	if((in = fopen(fname, "r")) == NULL)
		return 0;
	if((line = calloc(max + 1, sizeof(char))) == NULL) {
		fclose(in);
		return 1;
	}

	for(i = 0; i < n; i++) {
		if(fgets(line, max, in) == NULL)
			break;
		printf("%s", line);
	}
	free(line);
	if(fclose(in) == EOF)
		return 0;
	return 1;
}
