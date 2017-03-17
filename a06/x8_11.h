#ifndef X8_11BAG_H
#define X8_11BAG_H

/*
 * File: x8-11bag.h Tomasz Muldner
 * A header file for the generic module to represent an unordered collection
 * Operations: construction of a bag
 *              - destruction of a bag
 *              - add an element to a bag
 *              - remove an element from a bag
*/


/*
 * Function:  constructBag
 * Purpose:   to construct a bag
 * Inputs:    nElements: the size of the bag
 *                        elSize: the size of each element in the bag
 * Returns:   1 on success; 0 otherwise
 * Modifies:  sets the internal state of the module
 * Error checking:  checks to make sure nElements of elSize are not 0,
 *                                      and that any memory allocation was successful; if the
 *                                      bag is already initialized, 0 is returned
 */
int constructBag(size_t nElements, size_t elSize);

/*
 * Function:  destructBag
 * Purpose:   to destruct a bag
 * Inputs:    --
 * Returns:   1 on success; 0 otherwise (bag not initialized)
 * Modifies:  resets the internal state of the module
 * Error checking:  checks to make sure bag is intialized before releasing it
 */
int destructBag(void);

/*
 * Function:  addElementToBag
 * Purpose:   to add an element to a bag
 * Inputs:    the element to be added
 * Returns:   1 on success; 0 otherwise (bag not initialized)
 * Modifies:  adds the element to the bag
 * Error checking:  checks to make sure bag is intialized , and that there is
 *                                room in the bag to add the element
 */
int addElementToBag(void *ele);

/*
 * Function:  removeElementFromBag
 * Purpose:   to remove an element to a bag
 * Inputs:    the element to be removed, and a comparison function to compare
 *                                      two elements [ this function must return 1 if two elements are
 *                                      equal and 0 otherwise]
 * Returns:   1 on success; 0 otherwise (bag not initialized)
 * Modifies:  removes the element to the bag
 * Error checking:  checks to make sure bag is intialized, and not empty
 */
int removeElementFromBag(void *ele, int (*compareIt)(const void *, const void *));

#endif
