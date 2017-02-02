/*
 * File: x13-1.c
 * Application which tests the function that reverses bits in a byte
*/

#include <stdio.h>
#include <stdlib.h>

#define	LEN 		(8)
#define 	CLEAR		(1)

/*
 * Function:  reverse
 * Purpose:  to reverse the bits in a byte
 * Inputs:   byte
 * Returns:  the reversed byte
 */
unsigned reverse( unsigned byte ){
	int i;
	unsigned b1 = byte, b2 = 0;

	for(i = 0; i < LEN; i++){
		b2 <<= 1;
		b2 += (b1 & 1);
		b1 >>= 1;
	}
		
	return b2;
}

/*
 * Function: printBits
 * Purpose:  print the bits in a byte
 * Inputs:   byte
 * Returns:  --
 */
void printBits( char byte ){
	int i;

	for(i=LEN-1; i>=0 ;i--)
		printf("%d\t", (byte >> i)&CLEAR);

	printf("\n");
}


int main(){
	unsigned x, y;

	while(1){
		printf("Enter a byte (0 to quit)> ");

		if( scanf("%u", &x) != 1){
			printf("incorrect input \n");
			break;
		}
		while(getchar() != '\n' )   
                    ;
		if(x == 0)
			break;
		printBits(x);
		y = reverse(x);
		printBits( y );
	}

	return EXIT_SUCCESS;
}

