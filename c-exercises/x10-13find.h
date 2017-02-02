#ifndef X10_13FIND_H
#define X10_13FIND_H

/*
 * File: x10-13find.h
 * A header file for the module find that allows the user to search for words
 *    occurrence in a text file
 *
 * an internal caching system is in place to make searching more efficient
 *
 * Operations: reading of a text file / maintenance of lines from file
 *		showing the contents of the file
 *		searching for words in the stored lines on a per line basis and
 *		globally
*/


/*
 * Function:  construct_Find
 * Purpose:   to construct the module: read the file and store read lines
 * Inputs:    fileName
 * Returns:   1 on success; 0 otherwise
 * Modifies:  internal state of the module
 * Error checking:  checks to ensure file can be opened, required memory
 *					is available
 */
int construct_Find( char *fileName);


/*
 * Function:  destruct_Find
 * Purpose:  to release any memory / reinitialize internal state of module
 * Inputs:  --
 * Returns:  --
 * Modifies:  internal state of module
 * Error checking:  checks to ensure state is initialized
 */
int destruct_Find();

/*
 * Function: show_Find 
 * Purpose:  shows the i'th line in the file
 * Inputs:  i, the line number
 * Returns:  1 on success; 0 otherwise
 * Modifies:  the internal cache
 * Error checking:  ensures module is initialized; i is correct
 */
int show_Find( int i);

/*
 * Function:  search_Find
 * Purpose:  to search for the occurrence of the work globally, and print
 *				the line on which it occurs
 * Inputs:   word, i
 * Returns:  1 if the word is found, 0 otherwise (-1 on error)
 * Modifies: the internal cache
 * Error checking:  ensures module is initialized; i is correct
 */
int search_Find( char *word, int i);

/*
 * Function: search_GlobalFind
 * Purpose: to search for the occurrence of the word globally
 * Inputs:  word
 * Returns:  1 if the word may be found, 0 otherwise (-1 on error)
 * Modifies: the internal cache
 * Error checking: ensures module is initialized;
 */
int search_GlobalFind( char *word);

#endif

