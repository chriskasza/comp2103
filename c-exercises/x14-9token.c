#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include  "x14-9token.h"
/*
 * File: x14-9token.c
 * Implementation of the module to tokenize a string
 * Constructor tokenizes the entire string and stores it in a block
 * of pointers to tokens. Therefore, when a string is
 * traversed, only this block is used.
 */

struct ConcreteToken {
	char **block;		/* stores pointers to tokens */
	int tokenNumber;	/* total number of tokens */
	int current;		/* current token number (in enumeration) */
	int initialized ;	/* was constructor called */
};

/* 
 * Function: strdup
 * Purpose: private function to copy strings
 */
static char *strdup_(char *s) {
	char *kopy;
 	if((kopy = malloc((strlen(s)+1)*sizeof(char))) == NULL)
		return NULL;
	strcpy(kopy, s);
	return kopy;
}

/*
 * Function: construct_Token
 * Purpose: construct a string tokenizer
 * Inputs: String str and delimiters (parameters)
 * Returns: 1 if successful, 0 otherwise
 * Modifies: tokenNumber_, current_, block_
 * Error checking: none
 */
AbstractToken construct_Token(const char *str, const char *delimiters) {
	char *token;
	char *copyStr, **block;
	int i, tokenNumber;
	AbstractToken tok;
	
	if((tok = calloc(1, sizeof(*tok))) == NULL)
		return NULL;

	if((copyStr = strdup_((void*)str)) == NULL)
		return NULL;

	/* traverse to set the value of tokenNumber_ */
	for(tokenNumber = 0, token = strtok(copyStr, delimiters); token != NULL;
			token = strtok(NULL, delimiters))
	tokenNumber++;

	/* allocate a block of memory */
	if((block = calloc(sizeof(char*), tokenNumber)) == NULL) {
		free(copyStr);
		return NULL;
	}
	strcpy(copyStr, str);

	/* traverse the string and store pointers to tokens in the block */
	for(i = 0, token = strtok(copyStr, delimiters); token != NULL;
			token = strtok(NULL, delimiters), i++)
		block[i] = strdup(token);

	tok->initialized = 1;
	tok->current = 0;
	tok->block = block;
	tok->tokenNumber = tokenNumber;
	free(copyStr);
	return tok;
}

/*
 * Function: destruct_Token
 * Purpose: destruct a tokenizer
 * Inputs: None
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: returns 0 if the collection is not constructed
 */
int destruct_Token(AbstractToken *tok) {
	int i;

	if(!(*tok)->initialized || !tok)
		return 0;

	for(i=0; i < (*tok)->tokenNumber; i++)
		free((*tok)->block[i]);
	free((*tok)->block);

	free(*tok);
	*tok = NULL;
	return 1;

}

/*
 * Function: hasMore_Token
 * Purpose: check if there are more tokens
 * Inputs: nothing
 * Returns: 1 if there are more tokens, 0 otherwise
 * Modifies: nothing
 * Error checking: returns 0 if the tokenizer has not been constructed.
 */
int hasMore_Token( AbstractToken tok) {
	if(!tok->initialized)
		return 0;
	return tok->current < tok->tokenNumber;
}

/*
 * Function: next_Token
 * Purpose: retrieve the next token of the string; shallow copy
 * Inputs: nothing
 * Returns: pointer to next token
 * Modifies: nothing (for the client)
 * Error checking: returns NULL if the tokenizer has not been constructed
 *	or, there is no next token
 */
char *next_TokenShallow(AbstractToken tok) {
	if(!tok->initialized  || tok->current  == tok->tokenNumber )
		return 0;

	return tok->block[(tok->current)++];
}

/*
 * Function: next_Token
 * Purpose: retrieve the next token of the string; deep copy
 * Inputs: nothing
 * Returns: pointer to next token
 * Modifies: nothing (for the client)
 * Error checking: returns NULL if the tokenizer has not been constructed
 * or, there is no next token
 */
char * next_TokenDeep(AbstractToken tok) {
   if(!tok->initialized  || tok->current  == tok->tokenNumber )
      return 0;

   return strdup( tok->block[(tok->current)++] );
}


/*
 * Function: count_Token
 * Purpose: find the number of remaining tokens in the string
 * Inputs: nothing
 * Returns: number of tokens
 * Modifies: nothing
 * Error checking: returns 0 if the tokenizer has not been constructed
 *	or, there is no remaining tokens
 */
int count_Token( AbstractToken tok ) {
	if(!tok->initialized)
		return 0;
	return tok->tokenNumber - tok->current;
}

/*
 * Function: reset_Token
 * Purpose: reset enumeration
 * Inputs: nothing
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: returns 0 if the tokenizer has not been constructed
 */
int reset_Token( AbstractToken tok ){
	if(!tok->initialized)
		return 0;

	tok->current = 0;
	return 1;
}
