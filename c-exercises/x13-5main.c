/*
 * File: x13-5main.c
 * Application of the module to encrypt and decrypt files.
*/

#include <stdio.h>
#include <stdlib.h>
#include "x13-5.h"

int main(int argc, char *argv[]){
	char *key = "ab";

	if( argc < 3 ){
		fprintf(stderr,"Usage: inFile outFile debFile\n");
		return EXIT_FAILURE;
	}

	encrypt( argv[1], argv[2], key);
	decrypt( argv[2], argv[3], key);
        return EXIT_SUCCESS;
}
