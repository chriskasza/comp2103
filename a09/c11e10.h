/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c11e10.h
 *
 * a library to manage a list of double values
 *
 */

#ifndef C11E10
#define C11E10

typedef struct node {
  struct node *next;
  double value;
} NodeT, *NodeTP;

/*
 * Function:       dupNode
 * Purpose:        duplicate a NodeT element
 * Inputs:
 *   p:            pointer to the NodeT element to duplicate
 * Returns:        a copy of the original NodeT element
 * Modifies:       nothing
 * Error checking: none
 * Sample call:
 */
NodeTP dupNode(const NodeTP *p);

/*
 * Function:       deleteNode
 * Purpose:        recovers the storage used by the node p that is no longer
 *                 needed and sets the value of p to NULL
 * Inputs:
 *   p:            pointer to the node to delete
 * Returns:        1 if successful; otherwise 0
 * Modifies:       releases the memory used by p
 *                 updates the next pointer of the node before p in the list
 * Error checking: none
 * Sample call:
 */
int deleteNode(NodeTP *p, NodeTP *firstEle);

/*
 * Function:       maxi
 * Purpose:        returns a pointer to the largest element in the list
 * Inputs:
 *   firstEle:     the pointer to the head of the list
 *   largestEle:   this pointer will be used to return the largest element
 * Returns:        the function returns 1 if the list is non-empty
 *                   and 0 if the list is empty
 *                 the largestEle pointer will contain the pointer to the 
 *                   largest elementer or -1 if the list is empty
 * Modifies:       only largestEle is modified
 * Error checking: none
 * Sample call:
 */
int maxi(NodeTP *firstEle, NodeTP *largestEle);

/*
 * Function:       insert
 * Purpose:        inserts the provided value in the sorted list
 * Inputs:
 *   firstEle:     the pointer to the head of the list
 *   value:        the value to be added
 * Returns:        1 if successful; otherwise 0
 * Modifies:       a new node will be created and will be inserted in the list
 *                 in the appropriate location to maintain sort
 * Error checking: none
 * Sample call:
 */
int insert(const NodeTP *firstEle, const double value);

/*
 * Function:       kill
 * Purpose:        removes the last five elements from the list
 * Inputs:
 *   firstEle:     the pointer to the head of the list
 * Returns:        1 if successful; otherwise 0
 * Modifies:       the last five elements are removed from the list
 * Error checking: none
 * Sample call:
 */
int kill(NodeTP *firstEle);

/*
 * Function:       print
 * Purpose:        recursively prints all elements in the list
 * Inputs:
 *   firstEle:     the pointer to the head of the list
 * Returns:        1 if successful; otherwise 0
 *                 prints all elements to STDOUT
 * Modifies:       nothing
 * Error checking: none
 * Sample call:
 */
int print(const NodeTP List);

/*
 * Function:       genElement
 * Purpose:        given a double value, returns an element that can be added
 *                   to a list
 * Inputs:
 *   value:        the double value to be stored into the element
 * Returns:        returns the new element if successful; otherwise NULL
 * Modifies:       creates a new element
 * Error checking: none
 * Sample call:
 */
NodeTP genElement(const double value);

/*
 * Function:       genElemPtr
 * Purpose:        allocates memory for a new element pointer
 * Returns:        the new pointer
 * Modifies:       creates a new element pointer
 * Error checking: none
 * Sample call:
 */
NodeTP* genElemPtr();

#endif
