/*
 * File: ex4-5.c
 * Reads integers until 0 and output the largest integer
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	const int SENTINEL = 0;
	int 	i;
	int 	maxi;

	printf("Enter integers, 0 to stop\n");
	/* first read */
	if(scanf("%d", &maxi) != 1 || maxi == SENTINEL) {
		printf("No value read\n");
		return EXIT_SUCCESS;
	}
	/* first value read, start looping */
	while(1) {
	   if(scanf("%d", &i) != 1 || i == SENTINEL)
		break;
	   if(i > maxi)
		maxi = i;
	}

	printf("The largest value: %d\n", maxi);
	return EXIT_SUCCESS;
}
