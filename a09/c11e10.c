/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c11e10.c
 *
 * a library to manage a list of double values
 *
 */

#include "c11e10.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function:       dupNode
 * Purpose:        duplicate a NodeT element
 * Inputs:
 *   p:            pointer to the NodeT element to duplicate
 * Returns:        a copy of the original NodeT element; sets node->next to
 *                   null since the new node is not apart of a list yet
 * Modifies:       nothing
 * Error checking: none
 * Sample call:
 */
NodeTP dupNode(const NodeTP *p) {
  NodeTP dupe;

  if((dupe = malloc(sizeof(NodeTP))) == NULL) {
    fprintf(stderr, "failed to allocate memory for new node\n");
    return NULL;
  }

  /* memcpy(dupe, p, sizeof(NodeTP)); */

  dupe->value = (*p)->value;
  /* unset dupe->next because dupe is not apart of any list */
  dupe->next = NULL;

  return dupe;
}

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
int deleteNode(NodeTP *p, NodeTP *firstEle) {
  NodeTP *curr;

  if((curr = genElemPtr()) == NULL)
    return 0;

  if(*firstEle == *p) { /* delete first element */
    (*p)->next = NULL;
    free(*p);
    (*p) = NULL;
    return 1;
  }

  *curr = *firstEle;

  while((*curr)->next != *p) {
    *curr = (*curr)->next;
    if((*curr) == NULL) {
      fprintf(stderr, "unable to delete; element not in list\n");
      return 0;
    }
  }

  (*curr)->next = (*p)->next;
  (*p)->next = NULL;
  free(*p);
  (*p) = NULL;
  return 1;
}

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
int maxi(NodeTP *firstEle, NodeTP *largestEle) {
  *largestEle = *firstEle;

  while((*largestEle)->next != NULL)
    *largestEle = (*largestEle)->next;

  return 1;
}

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
int insert(const NodeTP *firstEle, const double value) {
  NodeTP new;
  NodeTP *curr;
  NodeTP *prev;

  if((curr = genElemPtr()) == NULL)
    return 0;
  if((prev = genElemPtr()) == NULL)
    return 0;
  if((new = genElement(value)) == NULL)
    return 0;

  *prev = *curr = *firstEle;

  /* empty list or adding to head of list?
   * nothing to do because new node will be lost */
  if((*curr) == NULL || (*curr)->value > new->value)
    return 0;

  /* printf("*first value is %f\n", (*firstEle)->value);
  printf("*prev value is %f\n", (*prev)->value);
  printf("*curr value is %f\n", (*curr)->value); */

  *curr = (*curr)->next;
  while((*curr) != NULL && (*curr)->value < new->value) {
    *prev = *curr;
    *curr = (*curr)->next;
  }

  new->next = *curr;
  (*prev)->next = new;

  return 1;
}

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
int kill(NodeTP *firstEle) {
  NodeTP *zero, *one, *two, *three, *four, *five;

  if((zero  = genElemPtr()) == NULL)
    return 0;
  if((one   = genElemPtr()) == NULL)
    return 0;
  if((two   = genElemPtr()) == NULL)
    return 0;
  if((three = genElemPtr()) == NULL)
    return 0;
  if((four  = genElemPtr()) == NULL)
    return 0;
  if((five  = genElemPtr()) == NULL)
    return 0;

  *five = *firstEle;
  while((*five)->next != NULL) {
    *zero  = *one;
    *one   = *two;
    *two   = *three;
    *three = *four;
    *four  = *five;
    *five  = (*five)->next;
  }

  if(five != NULL) {
    deleteNode(five, five);
    if(four != NULL) {
      deleteNode(four, four);
      if(three != NULL) {
        deleteNode(three, three);
        if(two != NULL) {
          deleteNode(two, two);
          if(one != NULL) {
            deleteNode(one, one);
            if(*zero != NULL) {
              (*zero)->next = NULL;
            }
          }
        }
      }
    }
  }

  return 1;
}

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
int print(const NodeTP List) {
  if((printf("%f\n", List->value)) < 1) {
    fprintf(stderr, "unable to write to STDOUT\n");
    return 0;
  }
  if(List->next != NULL) {
    print(List->next);
  }

  return 1;
}

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
NodeTP genElement(const double value) {
  NodeTP new;

  if((new = malloc(sizeof(NodeTP))) == NULL) {
    fprintf(stderr, "failed to allocate memory for new node\n");
    return NULL;
  }

  new->value = value;
  new->next = NULL;

  return new;
}

/*
 * Function:       genElemPtr
 * Purpose:        allocates memory for a new element pointer
 * Returns:        the new pointer
 * Modifies:       creates a new element pointer
 * Error checking: none
 * Sample call:
 */
NodeTP* genElemPtr() {
  NodeTP *new;

  if((new = malloc(sizeof(NodeTP*))) == NULL) {
    fprintf(stderr, "failed to allocate memory for new element pointer\n");
    return NULL;
  }

  return new;
}
