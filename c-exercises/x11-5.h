#ifndef X11_5_H
#define X11_5_H

/*
 * File: x11-5.h
 * A header file for the module x11-5 that operates on integer data
 *
 * Operations:  operations to construct and destruct the module
 *		 showing the data in the module
 *		 getting a constant pointer to data in the module
 *  		 getting the number of elements from the module that are
 *		   divisible by user-provided number 
*/

typedef struct {
   int *data;
   int size;
} *DataTP;

/*
 * Function:  freeData
 * Purpose:   to free the memory occupied by the internal state of the module
 * Inputs:    --
 * Returns:   1 on success, 0 otherwise
 * Modifies:  the internal state of the module 
 * Error checking:  ensures the module is initialized
 */
int freeData();

/*
 * Function:  initialize
 * Purpose:   to initialize the memory of the internal state of the module by
 *					reading the data contained in file fname
 * Inputs:    fname; contains integer values
 *						
 * Returns:   1 on success, 0 otherwise
 * Modifies:  the internal state of the module 
 * Error checking:  ensures the module is not initialized
 */
int initialize( const char *fname );

/*
 * Function:  getDataPtr
 * Purpose:   to get a pointer to the block containing the data
 * Inputs:    --
 * Returns:   a pointer to the data
 * Modifies:  
 * Error checking:  --
 */
const DataTP getDataPtr();

/*
 * Function:   divisible
 * Purpose:   returns the number of elements divisible by factor
 * Inputs:    a pointer to data d, factor
 * Returns:   the number of elements divisible by factor; -1 on error
 * Modifies:  --
 * Error checking:  ensures factor != 0 and module is initialized
 */
int divisible( const DataTP d, int factor);

/*
 * Function:  showData
 * Purpose:  shows the contents of the data memory block
 * Inputs:   --
 * Returns:  --
 * Modifies:  --
 * Error checking:  checks module is initialized
 */
void showData();

#endif

