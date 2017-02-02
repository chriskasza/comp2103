#ifndef X14_9TOKEN_H
#define X14_9TOKEN_H
/*
 * File: x14-9token.h
 * Header of the module Tokens to tokenize a string
 * The client is responsible for executing as the first call
 *   construct() passing the string and delimiter
 * The behavior of functions described below is undefined if the constructor
 * has not been called.
 * Once this call has been made, a string can be enumerated, using
 * - hasMore_Token()
 * - next_Token()
 * - count_Token()
 * - reset_Token()
 * The client of the module is responsible for calling destruct()
 */


typedef struct ConcreteToken  *AbstractToken ;

/*
 * Function: construct_Token
 * Purpose: construct a string tokenizer
 * Inputs: String str and delimiters (parameters)
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: none
 */
AbstractToken construct_Token(const char *str, const char *delimiters);

/*
 * Function: destruct_Token
 * Purpose: destruct a tokenizer
 * Inputs: None
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: returns 0 if the collection is not constructed
 */
int destruct_Token(AbstractToken *tok); 

/*
 * Function: hasMore_Token
 * Purpose: check if there are more tokens
 * Inputs: nothing
 * Returns: 1 if there are more tokens, 0 otherwise
 * Modifies: nothing
 * Error checking: returns 0 if the tokenizer has not been constructed.
 */
int hasMore_Token(AbstractToken tok);

/*
 * Function: next_Token
 * Purpose: retrieve the next token of the string; shallow copy
 * Inputs: nothing
 * Returns: pointer to next token
 * Modifies: nothing (for the client)
 * Error checking: returns NULL if the tokenizer has not been constructed
 *	or, there is no next token
 */
char *next_TokenShallow(AbstractToken tok);

/*
 * Function: next_Token
 * Purpose: retrieve the next token of the string; deep copy
 * Inputs: nothing
 * Returns: pointer to next token
 * Modifies: nothing (for the client)
 * Error checking: returns NULL if the tokenizer has not been constructed
 * or, there is no next token
 */
char *next_TokenDeep(AbstractToken tok);

/*
 * Function: count_Token
 * Purpose: find the number of remaining tokens in the string
 * Inputs: nothing
 * Returns: number of tokens
 * Modifies: nothing
 * Error checking: returns 0 if the tokenizer has not been constructed
 *	or, there is no remaining tokens
 */
int count_Token(AbstractToken tok);

/*
 * Function: reset_Token
 * Purpose: reset enumeration
 * Inputs: nothing
 * Returns: 1 if successful, 0 otherwise
 * Modifies: nothing (for the client)
 * Error checking: returns 0 if the tokenizer has not been constructed
 */
int reset_Token(AbstractToken tok);

#endif

