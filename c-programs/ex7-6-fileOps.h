#ifndef FILEOPS_H
#define FILEOPS_H
/*
 * File: ex7-6-fileOps.h
 * Header of the module with various file processing operations
 * The constructor uses a filename to open a file.
 * The following functions are supported:
 *   find the number of words in the file
 *   find the number of lines in the file
 *   find the number of characters in the file
 *
 * The above information is cached and not recomputed untill
 * a destructor is called.
 *
 */

/* 
 * Function: construct_fileOps
 * Purpose: constructor for the file module
 * Inputs: filename (parameter)
 * Returns: 1 if successful, 0 otherwise
 * Modifies: Nothing (for the client)
 * Error checking: fails if the file has been opened, or can not be opened
 * Sample call:
 *   if(construct_fileOps("a.dat") == 1) ... success
 */
int construct_fileOps(char *filename);

/* 
 * Function: words_fileOps
 * Purpose: read from a given file and count the number of words
 * Inputs: nothing
 * Returns: number of words or EOF if failed.
 *    A word is the longest sequence of characters that
 *	does not include whitespace.
 * Modifies: Nothing (the file is rewound before termination)
 * Error checking: Fails if the module is not initialized
 *		or input will fail
 * Sample call:
 *    long i = words_fileOps();
 *
 */
long words_fileOps();

/* 
 * Function: chars_fileOps
 * Purpose: read from a given file and count the number of characters
 * Inputs: nothing
 * Returns: number of characters or EOF if failed
 * Modifies: Nothing (the file is rewound before termination)
 * Error checking: Fails if the module is not initialized
 *		or input will fail
 * Sample call:
 *    long i = chars_fileOps();
 *
 */
long chars_fileOps();

/* 
 * Function: lines_fileOps
 * Purpose: read from a given file and count the number of lines
 * Inputs: nothing
 * Returns: number of lines, or EOF if failed
 * Modifies: Nothing (the file is rewound before termination)
 * Error checking: Fails if the module is not initialized
 *		or input will fail
 * Sample call:
 *    long i = lines_fileOps();
 *
 */
long lines_fileOps();

/* 
 * Function: destruct_fileOps
 * Purpose: destructor for the file module
 * Inputs: nothing
 * Returns: 1 if successful, 0 otherwise
 * Modifies: Closes the file
 * Error checking: fails if the file has not been opened, or can not be closed
 * Sample call:
 *   if(destruct_fileOps() == 1) ... success
 */
int destruct_fileOps();

#endif
