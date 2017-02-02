/*
 * File: ex5-1.c
 * Reads three real values from the file TEST1.txt
 *  and displays on the screen the sum of these values
 */

#include <stdio.h>
#include <stdlib.h>

int main()  {
	FILE *f;
	double x, y, z;

	if((f = fopen("TEST1.TXT", "r")) == NULL) {
 		fprintf(stderr, " can't read %s\n", "TEST1.txt");
		return EXIT_FAILURE;
	}
	if(fscanf(f, "%lf%lf%lf", &x, &y, &z) != 3) {
		fprintf(stderr, "File read failed\n");
		return EXIT_FAILURE;
	}

	printf("%f\n", x + y + z);

	if(fclose(f) == EOF) {
		fprintf(stderr, "File close failed\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
