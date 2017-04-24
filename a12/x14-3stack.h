#ifndef X14_3STACK_H
#define X14_3STACK_H

/*
 * File: x14-3stack.h
 * A header file for the module stacks that provides operations
 * on stacks
 * Operations: 
 *    write stack to a file
 *    read file and initialize the stack with its contents
 *    is the stack empty
 *    push an element on the stack
 *    pop an element from the stack
 *    show the first element of the stack
 */

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

/*
 * Function:  printStack
 * Purpose:   print out the complete stack (useful for debugging)
 * Inputs:    --
 * Returns:   --
 * Modifies:  --
 * Error checking:  --
 */
void printStack();

#endif

