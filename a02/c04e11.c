/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c04e11.c
 *
 * Receive an integer, n, from STDIN between 1 and 10. Output a multiplication
 * table from 1 to n.
 */
#include <stdio.h>
#include <stdlib.h>

int clean_stdin()
{
	while(getchar() != '\n');
	return 1;
}

int main() {
	int k;
	int n;
	char c;
	
	printf("Multiplication Table Generator\n");
	printf("Enter an integer from 1 to 10: ");
	
	while (((scanf("%d%c", &n, &c) != 2 || c != '\n') && clean_stdin()) || 
			n < 1 || n > 10) {
		printf("Invalid input.  Enter an integer from 1 to 10: ");
	}
	
	printf("\n\t");
	for(int i = 1; i <= n; i++) {
		printf("%d\t", i);
	}
	printf("\n");
		
	for(int i = 1; i <= n; i++) {
		printf("%d\t", i);

		for(int j = 1; j<=n; j++) {
			k = i * j;
			printf("%d\t", k);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
