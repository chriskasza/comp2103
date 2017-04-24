/*
 * File: x14-5stack.c
 * The implementation file for the module stacks that provides operations
 * on stacks
 * Operations:
 *    write stack to a file
 *    read file and initialize the stack with its contents
 *    is the stack empty
 *    push an element on the stack
 *    pop an element from the stack
 *    show the first element of the stack
 */

#include <stdio.h>
#include <stdlib.h>
#include "x14-3stack.h"

#define MAX 100

typedef struct{
  int size;
  int data[MAX];
} Stack;

/*** PRIVATE VARIABLES ********************/

static Stack stack_ = {0};  /*initialize the stack */

/*** FUNCTION DEFINITIONS ****************/

/*
 * Function:  stackSize
 * Purpose:   to return the stack size
 * Inputs:    --
 * Returns:   size of stack
 * Modifies:  --
 * Error checking:  --
 */
int stackSize( ){
  return stack_.size;
}

/*
 * Function:  initStack
 * Purpose:   to intialize the stack
 * Inputs:    --
 * Returns:   --
 * Modifies:  the stack
 * Error checking:  --
 */
void initStack( ){
  stack_.size = 0;
}

/*
 * Function:  isFull
 * Purpose:   to determine if the stack is full
 * Inputs:    --
 * Returns:   1 if stack is full; 0 otherwise
 * Modifies:  --
 * Error checking:  --
 */
int isFull(){
  return stack_.size >= MAX ? 1 : 0;
}

/*
 * Function:  isEmpty
 * Purpose:   to determine if the stack is empty
 * Inputs:    --
 * Returns:   1 if stack is empty; 0 otherwise
 * Modifies:  --
 * Error checking:  --
 */
int isEmpty(){
  return stack_.size == 0 ? 1 : 0;
}

/*
 * Function:  pushOnStack
 * Purpose:   to push an element onto the stack
 * Inputs:    val
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  stack
 * Error checking:  checks to see if stack is full
 */
int pushOnStack( int val ){

  if( isFull() )
    return 0;

  stack_.data[ stack_.size++] = val;
  return 1;
}

/*
 * Function:  popStack
 * Purpose:   to pop an element from the stack
 * Inputs:    val
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  val, stack
 * Error checking:  checks to see if stack is empty
 */
int popStack( int * val ){
  if( isEmpty() )
    return 0;
  *val = stack_.data[ stack_.size - 1 ];
  stack_.size--;
  return 1;
}

/*
 * Function:  ShowFirstEle
 * Purpose:   to show the first element on the stack
 * Inputs:    --
 * Returns:   --
 * Modifies:  --
 * Error checking:  --
 */
void ShowFirstEle(){
  if(isEmpty())
    printf("Stack is empty \n");
  else printf("The first element is %d \n", stack_.data[0]);
}

/*
 * Function:  printStack
 * Purpose:   print out the complete stack (useful for debugging)
 * Inputs:    --
 * Returns:   --
 * Modifies:  --
 * Error checking:  --
 */
void printStack() {
  int i;

  if(isEmpty()) {
    printf("Stack empty\n");
    return;
  }

  for(i = 0; i < stack_.size; i++) {
    printf("%d\n", stack_.data[i]);
  }

  return;
}
