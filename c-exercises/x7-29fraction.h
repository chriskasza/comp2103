#ifndef X7_27FRACTION_H
#define X7_27FRACTION_H

/*
 * File: x7-27fraction.h
 * A header file for the module to perform operations on two fractions; module
 * holds a fraction pair and a fractionResult in its internal state, where
 * fraction result is the fraction obtained by applying one of the operations
 * to the fraction pair
 * Internal error flags are used to maintain an error state.
 *
 * Operations: addition / subtraction / multiplication / division of fractions
 *
 * Prior to any operations, the client must initialize the module (two fractions)
 * by calling InitializeFractionPair
 *
 * Sample Usage:
 *
 *  InitializeFractionPair(1,2,5,7);
 *  MultiplyFractionPair();
 *  PrintFractionPair();
 *  PrintFractionResult();
 *					
*/

/* 
 * Function: InitializeFractionPair
 * Purpose: to initialize the internal state to the incoming fraction pair
 * Inputs:  four integers; the first two represent the first fraction, the
 *				next two the second fraction
 * Returns: --
 * Modifies: sets the internal fraction pair to the incoming pair; sets
 *				internal error flag if error occurs
 * Error Checking: checks to see if either denominator is 0; if so, sets
 *				error flags
*/
void InitializeFractionPair(int numerator1, int denominator1,
		int numerator2, int denominator2);

/*
 * Function: PrintFractionPair
 * Purpose: to print the fraction pair maintained in the module
 * Inputs:  --
 * Returns: --
 * Modifies: --
 * Error Checking: --
*/
void PrintFractionPair();

/*
 * Function: PrintFractionResult
 * Purpose: to print the fraction result
 * Inputs:  --
 * Returns: --
 * Modifies: --
 * Error Checking: --
*/
void PrintFractionResult();

/*
 * Function: AddFractionPair
 * Purpose: to add the fraction pair
 * Inputs:  --
 * Returns: --
 * Modifies: sets the internal fraction to the sum of the two fractions; if
 *			the fraction pair is not initialized, sets the internal error flag
 * Error Checking: checks to make sure internal fraction pair is initialized
*/
void AddFractionPair();

/*
 * Function: SubtractFractionPair
 * Purpose: to subtract the fraction pair
 * Inputs:  --
 * Returns: --
 * Modifies: sets the internal fraction to the difference of the two fractions;
 *			if the fraction pair is not initialized, sets the internal error flag
 * Error Checking: checks to make sure internal fraction pair is initialized
*/
void SubtractFractionPair();

/*
 * Function: MultiplyFractionPair
 * Purpose: to multiply the fraction pair
 * Inputs:  --
 * Returns: --
 * Modifies: sets the internal fraction to the product of the two fractions;
 *       if the fraction pair is not initialized, sets the internal error flag
 * Error Checking: checks to make sure internal fraction pair is initialized
*/
void MultiplyFractionPair();

/*
 * Function: DivFractionPair
 * Purpose: to divide the fraction pair
 * Inputs:  --
 * Returns: --
 * Modifies: sets the internal fraction to the result of dividing the two fractions;
 *       if the fraction pair is not initialized, sets the internal error flag
 * Error Checking: checks to make sure internal fraction pair is initialized
*/
void DivFractionPair();
									
/*
 * Function: GetNumeratorResult
 * Purpose: to get the numerator part of the result
 * Inputs:  --
 * Returns: the numerator part of the result
 * Modifies: --
 * Error Checking: --
*/
int GetNumeratorResult();

/*
 * Function: GetDenominatorResult
 * Purpose: to get the denominator part of the result
 * Inputs:  --
 * Returns: the denominator part of the result
 * Modifies: --
 * Error Checking: --
*/
int GetDenominatorResult();

/*
 * Function: clearError
 * Purpose:  to reset the internal error state flag
 * Inputs:   --
 * Returns:  --
 * Modifies:  resets the internal error flag
 * Error checking:  --
 */
void clearError();

/*
 * Function: isError
 * Purpose:  to return the state of the internal error flag
 * Inputs:   --
 * Returns:  1 if the internal error flag is set; 0 otherwise
 * Modifies:  --
 * Error checking:  --
 */
int isError();

/*
 * Function: printError
 * Purpose:  to print the internal error flag
 * Inputs:   --
 * Returns:  --
 * Modifies:  --
 * Error checking:  --
 */
void printError();

#endif

