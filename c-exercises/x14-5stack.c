/*
 * File: x14-5stack.c
 * The implementation file for the module stacks that provides operations
 * on stacks, with added persistance
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
#include "x14-5stack.h"

#define MAX 		(100)

typedef struct{
	int size;
	int data[ MAX ];
} Stack;

/*** PRIVATE VARIABLES ********************/

static Stack stack_ = {0};  /*initialize the stack */
static FILE *storage_ = NULL; /* to store the state of the stack */

/*** FUNCTION DEFINITIONS ****************/

/*
 * Function:  startStorage
 * Purpose:   intializes the system so that storage of stack may begin
 * Inputs:    --
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  internal files are initialized
 * Error checking:  checks to see if file operation are successful,
 *             and ensures that the internal state is not already
 *             initialized to start storage operation
 */
int startStorage( const char *name ){
	if( storage_ ) /* already open */
		return 0;

	if( (storage_ = fopen(name, "w")) == NULL)
		return 0;
	return 1;
}

/*
 * Function:  endStorage
 * Purpose:   finishes the storage operation, closes any opened files
 * Inputs:    name, the name of the file to which the stack will be
 *             written
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  internal files are closed
 * Error checking:  checks to see if internal state is initialized
 */
int endStorage(){
	if( !storage_) /*closed file */
		return 0;
	fclose(storage_);
	storage_ = NULL;
	return 1;
}

/*
 * Function:  stackToStorage
 * Purpose:   writes the contents of the stack to storage (a file)
 * Inputs:    --
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  the file is modified
 * Error checking:  checks to see if file operations are successful
 */
int stackToStorage(){
	int i;

	if( !storage_ )
		return 0;
	
	for(i = 0; i < stack_.size; i++)
		fprintf(storage_, "%d\t", stack_.data[i]);
	fprintf(storage_,"\n");
	return 1;
}

/*
 * Function:  readStackFromFile
 * Purpose:   reads a file and initializes the stack with its contents
 * Inputs:    --
 * Returns:   1 if successful; 0 otherwise
 * Modifies:  the stack is initialized with the contents of the file
 * Error checking:  checks to see if file operations are successful
 */
int readStackFromFile( const char *name ){
	FILE *in;
	int val;

	if( (in = fopen(name, "r")) == NULL)
		return 0;

	initStack();
	while(1){
		if( feof(in))
			break;

		if( fscanf(in, "%d", &val) != 1){
			initStack();
			fclose(in);
			return 0;
		}
		if( !pushOnStack( val )){
			initStack();
                  fclose(in);
                  return 0;
		}
	}

	fclose(in);
	return 1;

}

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

