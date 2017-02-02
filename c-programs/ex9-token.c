#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/*
 * File: ex9-token.c
 * Implementation of the module to tokenize a string
 * Constructor tokenizes the entire string and stores it in a block
 * of pointers to tokens. Therefore, when a string is
 * traversed, only this block is used.
 */

static char **block_;		/* stores pointers to tokens */
static int tokenNumber_;	/* total number of tokens */
static int current_;		/* current token number (in enumeration) */
static int initialized_ = 0;	/* was constructor called */

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
int construct_Token(const char *str, const char *delimiters) {
	char *token;
	char *copyStr;
	int i;
	
	if(initialized_)
		return 0;
	if((copyStr = strdup_((char*)str)) == NULL)
		return 0;
	/* traverse to set the value of tokenNumber_ */
	for(tokenNumber_ = 0, token = strtok(copyStr, delimiters); token != NULL;
			token = strtok(NULL, delimiters))
	   tokenNumber_++;
	/* allocate a block of memory */
	if((block_ = calloc(sizeof(char*), tokenNumber_)) == NULL) {
		free(copyStr);
		return 0;
	}
	strcpy(copyStr, str);
	/* traverse the string and store pointers to tokens in the block */
	for(i = 0, token = strtok(copyStr, delimiters); token != NULL;
			token = strtok(NULL, delimiters), i++)
		block_[i] = strdup(token);
	initialized_ = 1;
	current_ = 0;
	free(copyStr);
	return 1;
}

/*
 * Function: destruct_Token
 * Purpose: destruct a tokenizer
 * Inputs: None
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: returns 0 if the collection is not constructed
 */
int destruct_Token(void) {
	int i;

	if(!initialized_)
		return 0;
	for(i=0; i < tokenNumber_; i++)
		free(block_[i]);
	initialized_ = 0;
	free(block_);
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
int hasMore_Token() {
	if(!initialized_)
		return 0;
	return current_ < tokenNumber_;
}

/*
 * Function: next_Token
 * Purpose: retrieve the next token of the string
 * Inputs: nothing
 * Returns: pointer to next token
 * Modifies: nothing (for the client)
 * Error checking: returns NULL if the tokenizer has not been constructed
 *	or, there is no next token
 */
char *next_Token() {
	if(!initialized_ || current_ == tokenNumber_)
		return 0;

	return block_[current_++];
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
int count_Token() {
	if(!initialized_)
		return 0;
	return tokenNumber_ - current_;
}

/*
 * Function: reset_Token
 * Purpose: reset enumeration
 * Inputs: nothing
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: returns 0 if the tokenizer has not been constructed
 */
int reset_Token(){
	if(!initialized_)
		return 0;
	current_ = 0;
	return 1;
}
