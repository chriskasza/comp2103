#ifndef X14_4STACK_H
#define X14_5STACK_H

/*
 * File: x14-5stack.h
 * A header file for the module stacks that provides operations
 * on stacks, with added persistance
 * Operations: 
 *		write stack to a file
 *		read file and initialize the stack with its contents
 * 	is the stack empty
 *    push an element on the stack
 *    pop an element from the stack
 *    show the first element of the stack
 */


/*
 * Function:  startStorage
 * Purpose:   intializes the system so that storage of stack may begin
 * Inputs:    --
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  internal files are initialized
 * Error checking:  checks to see if file operation are successful,
 *					and ensures that the internal state is not already
 *					initialized to start storage operation
 */
int startStorage( const char *name );

/*
 * Function:  endStorage
 * Purpose:   finishes the storage operation, closes any opened files
 * Inputs:    name, the name of the file to which the stack will be
 *					written
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  internal files are closed
 * Error checking:  checks to see if internal state is initialized
 */
int endStorage();

/*
 * Function:  stackToStorage
 * Purpose:   writes the contents of the stack to storage (a file)
 * Inputs:    --
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  the file is modified
 * Error checking:  checks to see if file operations are successful
 */
int stackToStorage();

/*
 * Function:  readStackFromFile
 * Purpose:   reads a file and initializes the stack with its contents
 * Inputs:    --
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  the stack is initialized with the contents of the file
 * Error checking:  checks to see if file operations are successful
 */
int readStackFromFile( const char *name );

/*
 * Function:  initStack
 * Purpose:   to intialize the stack
 * Inputs:    --
 * Returns:   --
 * Modifies:  the stack
 * Error checking:  --
 */
void initStack( );

/*
 * Function:  stackSize
 * Purpose:   to return the stack size
 * Inputs:    --
 * Returns:   size of stack
 * Modifies:  --
 * Error checking:  --
 */
int stackSize();

/*
 * Function:  isFull
 * Purpose:   to determine if the stack is full
 * Inputs:    --
 * Returns:   1 if stack is full; 0 otherwise
 * Modifies:  --
 * Error checking:  --
 */
int isFull();

/*
 * Function:  isEmpty
 * Purpose:   to determine if the stack is empty
 * Inputs:    --
 * Returns:   1 if stack is empty; 0 otherwise
 * Modifies:  --
 * Error checking:  --
 */
int isEmpty();

/*
 * Function:  pushOnStack
 * Purpose:   to push an element onto the stack
 * Inputs:    val
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  stack
 * Error checking:  checks to see if stack is full
 */
int pushOnStack( int val );

/*
 * Function:  popStack
 * Purpose:   to pop an element from the stack
 * Inputs:    val
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  val, stack
 * Error checking:  checks to see if stack is empty
 */
int popStack( int * val );

/*
 * Function:  ShowFirstEle
 * Purpose:   to show the first element on the stack
 * Inputs:    --
 * Returns:   --
 * Modifies:  --
 * Error checking:  --
 */
void ShowFirstEle();

#endif

