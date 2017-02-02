/* File: ex6-1.c
 * Reads characters until "." and output the ASCII value
 *  of the largest input character. 
 * Uses conditional compilation for debugging
 */

#include <stdio.h>
#include <stdlib.h>
int main() {
	const char SENTINEL = '.';
	int 	aux;
	int 	maxi = 0;

#ifdef DEBUG
	printf("debugging on: copy each input character\n");
#endif
	while(1) {
	   if((aux = getchar()) == EOF || aux == SENTINEL)
		break;
#ifdef DEBUG
	putchar(aux);
	putchar('\n');
#endif
	   if(aux > maxi)
#ifdef DEBUG
           {
             printf("Now setting largest character to: %c\n", aux);
#endif
		maxi = aux;
	}
#ifdef DEBUG
      }
	putchar('\n');
#endif
	printf("The largest ASCII value: %d\n", maxi);

	return EXIT_SUCCESS;
}
