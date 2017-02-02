#ifndef X11_21LIST_H
#define X11_21LIST_H
/*
 * File: x11-21list.h
 * A header file for the module that implements lists of homogenous objects.
 * Each element of the list contains three integers.
 * Operations:  a constructor
 *			a destructor
 *			the reading of integers stored in a file
 *			the writing of contents of list to a file
 *			the appending of a new integer to the end of the list
 *			the removing of the first element from the list
 *			the displaying of the i-th element 
 *			a destructor
*/

typedef int EleType;

/*
 * Function: constructList
 * Purpose:  to initialize a list with values in a text file
 * Inputs:   maxSize
 * Returns:  1 is successful; 0 otherwise
 * Modifies: creates memory for the list
 * Error checking:  checks the result of memory call; ensures list is not
 *				already initialized
 */
int constructList( int maxSize );

/*
 * Function: readFile
 * Purpose:  to read values from a file and store them in the list
 * Inputs:   name, The text file must contain only integer values, 
 *					seperated by whitespace
 * Returns:  1 is successful; 0 otherwise
 * Modifies: initializes the memory in the list
 * Error checking:  checks the result of read operations; ensures list is 
 *          already initialized
 */
int readFile( const char *name );

/*
 * Function: writeFile
 * Purpose:  to write the contents of the list to the file
 * Inputs:   name
 * Returns:  1 is successful; 0 otherwise
 * Modifies: creates text file
 * Error checking:  ensures list is initialized
 */
int writeFile( const char *name );

/*
 * Function: appendEle
 * Purpose:  to add an element at the end of the list
 * Inputs:   the three integers representing a new element
 * Returns:  1 is successful; 0 otherwise
 * Modifies: the list
 * Error checking:  ensures list is initialized and not full
 */
int appendEle( EleType newEle1, EleType newEle2, EleType newEle3 );

/*
 * Function: removeFirstEle
 * Purpose:  to remove the first element from the list
 * Inputs:   --
 * Returns:  1 is successful; 0 otherwise
 * Modifies: the list
 * Error checking:  ensures list is initialized and not empty
 */
int removeFirstEle( );

/*
 * Function: showEle
 * Purpose:  to show the i'th element
 * Inputs:   pos
 * Returns:  --
 * Modifies: --
 * Error checking:  ensures list is initialized and pos is correct
 */
void showEle( int pos );

/*
 * Function: destructList
 * Purpose:  to free memory occupied by the list
 * Inputs:   --
 * Returns:  1 if ssuccessful; 0 otherwise
 * Modifies:  the internal state of module
 * Error checking:  ensures list is initialized 
 */
int destructList ();

#endif

