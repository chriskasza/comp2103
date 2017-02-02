/*
 * File: ex4-8.c
 * Reads two integers a and b and
 *       ???
 * Error checking: Keep reading if either of two
 *   integers is invalid or a >= b.
 */

#include <stdlib.h>
#include <stdio.h>
int main() {
	int i, j, a, b;

	while(1) {
		printf("enter two integers a and b, a < b:");
		if(scanf("%d%d", &a, &b) == 2 && a < b)
			break;
	}

	for(i = a, j = b; i <= j; i += 2, j -= 2)
		printf("%d\n", i + j);

	return EXIT_SUCCESS;
}
/*

i	2	4	6
j	10	8	6
output	12	12	12
*/
