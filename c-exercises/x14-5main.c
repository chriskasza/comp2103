/*
 * File: x14-5main.c
 * Application of the module stacks. The program tests the stack
 * program by evaluating simple arithmetic operations using the
 * Polish post-fix notation. The program reads user-supplied
 * arithmetic expressions and uses the stack to evaluate them;
 * it also tests the persistance functions added to the module.
*/


#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "x14-5stack.h"

int process( int operator ){

	int val1, val2;

	switch( operator ){
		case '+' : 
			if( !popStack( &val1 ) || !popStack( &val2 ))
				return 0;
			pushOnStack(val1 + val2 ); 
			break;

		case '*' : 
			if( !popStack( &val1 ) || !popStack( &val2 ))
				return 0;
			pushOnStack(val1 * val2 ); 
			break;
		case '-' : 
			if( !popStack( &val1 ) || !popStack( &val2 ))
				return 0;
			pushOnStack(val2 - val1 ); 
			break;

		case '/' : 
			if( !popStack( &val1 ) || !popStack( &val2 ))
				return 0;
			if( val1 == 0 ) /* div by 0 */
				return 0;
			pushOnStack(val2 / val1 ); 
			break;

		default: fprintf(stderr,"Unknown operator \n");
			return 0;
	}
	return 1;
}

int main(int argc, char *argv[]){

	char c;
	int  done = 0;

	if( argc < 2 ){
		fprintf(stderr, "Usage : program storageFile\n");
		return EXIT_FAILURE;
	}

	if( !startStorage( argv[1] ) ){
		fprintf(stderr, "Could not open storage file\n");
		return EXIT_FAILURE;
	}

	while(1){
		initStack();
		printf("Enter an expression, q anywhere to quit > ");
		while( (c = getchar()) != '\n' ){
			if( c == 'q' ){
				done  = 1 ;
				break;
			}
			if( isFull() ){
				fprintf(stderr, "Stack is full\n");
				done = 1;
				break;
			}
			if( isdigit( c ))
				pushOnStack( c - '0' );
			else{ /* we have an operator */
				if( !stackToStorage() ){
					fprintf(stderr, "Error writing to stack \n");
					return EXIT_FAILURE;
				}
				if( !process( c )){
					fprintf(stderr, "Incorrect format entered \n");
					return EXIT_FAILURE;
				}
			}
		}
		if( done ) break;
		if( stackSize() != 1)
			printf("Missing operators! \n");
		else if( !stackToStorage() ){
         fprintf(stderr, "Error writing to stack \n");
         return EXIT_FAILURE;
      }

	}

	endStorage();
	return EXIT_SUCCESS;
}

