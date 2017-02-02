/*
 * File: x9-21main.c
 * 
 * Uses the tokenizing module and reads a single line from standard input. It
 * then gathers the following stats: the number of words, # of vowels and
 * the number of consonants.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ex9-token.h"

#define DELIM		" "

/*
 * Purpose:  returns 1 if input character is a vowel; 0 otherwise
*/
static int isVowel(char c) {
	return  c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

/*
 * Purpose:  returns 1 if input character is a consonant; 0 otherwise
*/
static int isCons(char c) {
	return isalpha( (int)c) && !isVowel(c);
}

#define SIZE 	(80) 
/* maximum size of a line */

int main(int argc, char *argv[]) {
       char *line;
       char *word;
       int len, i;
       int numWords = 0;
       int numVowels = 0;
       int numCons = 0;
       FILE *fileIn;

        if(argc != 2) {
                fprintf(stderr, "usage %s filename\n", argv[0]);
                return EXIT_FAILURE;
        }

        if((fileIn = fopen(argv[1], "r")) == NULL) {
                fprintf(stderr, "can not open %s\n", argv[1]);
                return EXIT_FAILURE;
        }
	if((line = calloc(SIZE, sizeof(char))) == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
                fclose(fileIn);
		return EXIT_FAILURE;
	}

	if(fgets(line, SIZE, fileIn) == NULL) {
		free(line);
                fclose(fileIn);
		fprintf(stderr, "Could not read a line\n");
		return EXIT_FAILURE;
	}
        if(fclose(fileIn) == EOF) {
                fprintf(stderr, "can not close %s\n", argv[1]);
                return EXIT_FAILURE;
        }
        line[strlen(line)-1]= '\0';
	/* call the constructor for token module */
	construct_Token(line, DELIM);

	/* now count words, vowels, and consonants */
	
	while(hasMore_Token()) {
		word = next_Token();

		/* now count the number of vowels and consonants */
		if(word == NULL) {
			fprintf(stderr, "Incorrect result - word is empty\n");
			free(line);
			return EXIT_FAILURE;
		}
		numWords ++;
		len = strlen(word);
		for(i = 0; i < len; i++) {
			if(isVowel(word[i]))
				numVowels++;
			if(isCons(word[i]))
				numCons++;	
		}
	}
	printf("There are %d words, %d (not necessarily different) vowels and (not necessarily different) %d consonants\n", 
                   numWords, numVowels, numCons);

	free(line);
	return EXIT_SUCCESS;
}

