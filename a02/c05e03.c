/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c05e03.c
 *
 * Read list of expense values from file and provide tally.
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *f, *g;
	int c;
	double d;
	double total = 0;

	printf("Expense Calculator (using money.txt)\n");

	if((f = fopen("money.txt", "r")) == NULL) {
		fprintf(stderr, "can't open %s\n", "money.txt");
		return EXIT_FAILURE;
	}

	while(fscanf(f, "%lf", &d) == 1) {
		total += d;
	}
	
	if(fclose(f) == EOF) {
		fprintf(stderr, "failed to close %s\n", "money.txt");
		return EXIT_FAILURE;
	}

	printf("The total expenses are $%.2f.\n", total);
	printf("Do you want to appended this sum to expenses.dat? [Y/n] ");
	
	if(((c = getchar()) == EOF) || c == 'y' || c == 'Y') {
		if((g = fopen("expenses.dat", "a+")) == NULL) {
			fprintf(stderr, "can't open %s\n", "expenses.dat");
			return EXIT_FAILURE;
		}
	
		if(fprintf(g, "%.2f\n\n", total)== EOF) {
			fprintf(stderr, "failed to write to %s\n", "expenses.dat");
			return EXIT_FAILURE;
		} else {
			printf("%.2f added to expenses.dat.\n", total);
		}

		if(fclose(g) == EOF) {
			fprintf(stderr, "failed to close %s\n", "expenses.dat");
			return EXIT_FAILURE;
		}
	}	

	return EXIT_SUCCESS;
}
