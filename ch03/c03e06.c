/*
 * Author: 	Chris Kasza
 * Student #: 	100133723
 * Course:    	COMP 2103 N1
 * Version: 	1.0
 * File: 	ch03ex06.c
 *
 * compare size of types
 */
#include <stdio.h>

int main() {
	int sizeShort	= sizeof(short);
	int sizeInt	= sizeof(int);
	int sizeLong	= sizeof(long);
	int sizeFloat	= sizeof(float);
	int sizeDouble	= sizeof(double);
	int sizeLongD	= sizeof(long double);

	if( (sizeShort < sizeInt) && (sizeInt < sizeLong) ) {
		printf("The size of the short type, %d, is ", sizeShort);
		printf("smaller than the size of the int type, ");
		printf("%d.\n", sizeInt);
		printf("The size of the int type, %d, is ", sizeInt);
		printf("smaller than the size of the long type, ");
		printf("%d.\n", sizeLong);
	} else {
		printf("Sizes of short, int, and long aren't what you expect\n");
/*
		printf("The size of the short type, %d, is ", sizeShort);
		printf("not smaller than the size of the int type, ");
		printf("%d.\n", sizeInt);
	}
	if( sizeInt < sizeLong ) {
	} else {
		printf("The size of the int type, %d, is ", sizeInt);
		printf("smaller than the size of the long type, ");
		printf("%d.\n", sizeLong);
*/	
	}
	
		
}
