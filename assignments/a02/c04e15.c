/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c04e15.c
 *
 * Receive a mixed fraction on STDIN. Convert to a decimal value.
 */
#include <stdio.h>
#include <stdlib.h>

int clean_stdin()
{
	while(getchar() != '\n');
	return 1;
}

int main() {
	int c, i, n, d;
	double f;

	printf("Fraction to Decimal Converter\n");
	printf("Enter [m] for mixed fraction or [i] for improper fraction: ");
	while(((c = getchar()) == EOF) || (c != (int)'m' && c != (int)'i')) {
		clean_stdin();
		printf("Invalid choice.  ");
		printf("Enter [m] for mixed fraction or [i] for improper fraction: ");
	}
	clean_stdin();

	if(c == 'm') {
		// mixed fraction
		printf("Enter a mixed fraction (ex. \"1 4/5\"): ");
		while((scanf("%d %d/%d%c", &i, &n, &d, &c) != 4 || c != '\n') && 
				clean_stdin()) {
			printf("Invalid input. ");
			printf("Enter a mixed fraction (ex. \"1 4/5\"): ");
		}
		i *= d;
		n += i;
	} else if(c == 'i') {
		// improper fraction
		printf("Enter an improper fraction (ex. \"6/5\"): ");
		while((scanf("%d/%d%c", &n, &d, &c) != 3 || c != '\n') && clean_stdin()) {
			printf("Invalid input.  ");
			printf("Enter an improper fraction (ex. \"6/5\"): ");
		}
	} else {
		printf("Invalid choice. Quitting.\n");
		return EXIT_FAILURE;
	}

	f = (double)n / d;

	printf("\nThe equivalent decimal value of %d/%d is %f.\n", n, d, f);
	return EXIT_SUCCESS;
}
