/*
 * File: x7-27fraction.c
 * The implementation file for the module to perform operations on fractions; module
 * holds a fraction pair and a fractionResult in its internal state, where
 * fraction result is the fraction obtained by applying one of the operations
 * to the fraction pair
 * Internal error flags are used to maintain an error state; possible error
 * flag states include: OK, BAD_INPUT (one or both denominator are 0), INITIALIZED 
 * and NOT_INITIALIZED (the internal fraction pair has not been initialized)
 *
 * Operations: addition / subtraction / multiplication / division of fractions
 *
 * Prior to any operations, the client must initialize the internal state
 * of the module by passing in two fraction pairs, by calling InitializeFractionPair
 *
 * Sample Usage:
 *
 *  InitializeFractionPair(1,2,5,7);
 *  MultiplyFractionPair();
 *  PrintFractionPair();
 *  PrintFractionResult();
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include "x7-29fraction.h"

#define NOT_INITIALIZED    	(0)
#define INITIALIZED           (1)
#define OK                    (2)
#define BAD_INPUT    	      (3)

/*** PRIVATE VARIABLES ********************/

static int errorFlag_ = OK;
static int init_ = NOT_INITIALIZED;

/* internal state: the fraction pair */
static int numerator1, denominator1,
	     numerator2, denominator2;

/* variable to hold result of fraction operation */
static int numeratorResult, denominatorResult;
				

/*** FUNCTION DEFINITIONS ****************/

/* local functions */

/*
 * Purpose: to find the greatest common factor for the two
 * 			incoming values and return it
 */
static int GreatestCommonFactor(int val1, int val2) {
	int k, result;

	if(!( val1 > 0 && val2 > 0 )) /* invalid input */
		return 0;

	do { /* look for the the greatest common factor */
		k = val2 % val1;
		if(k == 0)
			result = val1;
		else {
			val2 = val1;
			val1 = k;
		}
	} while ( k > 0 );

	return result;
}

/*
 * Purpose: to reduce the incoming fraction to lowest possible terms
 * Modifies: global private variables numeratorResult, denominatorResult
 */
static void ReduceFraction() {
	int gcf;

	gcf = GreatestCommonFactor(abs(numeratorResult), abs(denominatorResult));

        if(gcf != 1) {
           numeratorResult /= gcf;
           denominatorResult /= gcf;
        }
}


/***** Exported Functions ********************/

/*
 * Function: PrintFractionPair
 * Purpose: to print the fraction pair maintained in the module
 * Inputs:  --
 * Returns: --
 * Modifies: --
 * Error Checking: --
*/
void PrintFractionPair() {
	if(!init_) {
           errorFlag_ = NOT_INITIALIZED;
           return;
         }
	printf("Fraction1: \t%d / %d \n", numerator1, denominator1);
	printf("Fraction2: \t%d / %d \n", numerator2, denominator2);
}

/*
 * Function: PrintFractionResult
 * Purpose: to print the fraction result
 * Inputs:  --
 * Returns: --
 * Modifies: --
 * Error Checking: --
*/
void PrintFractionResult() {
      if(!init_) {
         errorFlag_ = NOT_INITIALIZED;
         return;
       }
       printf("FractionResult: \t%d / %d \n", numeratorResult, denominatorResult );
}

/*
 * Function: InitializeFractionPair
 * Purpose: to initialize the internal state to the incoming fraction pair
 * Inputs:  four integers; the first two represent the first fraction, the
 *          next two the second fraction
 * Returns: --
 * Modifies: sets the internal fraction pair to the incoming pair; sets
 *          internal error flag if error occurs
 * Error Checking: checks to see if either denominator is 0; if so, sets
 *          error flags
*/
void InitializeFractionPair( int num1, int den1, int num2, int den2) {
	int tempN1, tempN2;

	if( den1 == 0 || den2 == 0 ){
		errorFlag_ = BAD_INPUT;
		return;
	}
	/* initialize the first fraction pair */
	numerator1 = num1;
	denominator1 = den1;	
	
	/* initialize the second fraction pair */
	numerator2 = num2;
	denominator2 = den2;

	/* now prepare for addition or subtracton: set to common denominators */
	tempN1 = denominator2 * numerator1;
	tempN2 = denominator1 * numerator2;

	denominator1 = denominator1 * denominator2;
	denominator2 = denominator1;
	numerator1 = tempN1;
	numerator2 = tempN2;

	init_ = INITIALIZED;
}

/*
 * Function: AddFractionPair
 * Purpose: to add the fraction pair
 * Inputs:  --
 * Returns: --
 * Modifies: sets the internal fraction to the sum of the two fractions; if
 *       the fraction pair is not initialized, sets the internal error flag
 * Error Checking: checks to make sure internal fraction pair is initialized
*/
void AddFractionPair(){
	if(!init_) {
		errorFlag_ = NOT_INITIALIZED;
		return;
	}

	numeratorResult = numerator1 + numerator2;		
	denominatorResult = denominator1;

	/* reduce */
	ReduceFraction();
}

/*
 * Function: SubtractFractionPair
 * Purpose: to subtract the fraction pair
 * Inputs:  --
 * Returns: --
 * Modifies: sets the internal fraction to the difference of the two fractions;
 *       if the fraction pair is not initialized, sets the internal error flag
 * Error Checking: checks to make sure internal fraction pair is initialized
*/
void SubtractFractionPair() {

    if(!init_) {
         errorFlag_ = NOT_INITIALIZED;
         return;
     }

    numeratorResult = numerator1 - numerator2;
    denominatorResult = denominator1;

   /* reduce */
   ReduceFraction();
}

/*
 * Function: MultiplyFractionPair
 * Purpose: to multiply the fraction pair
 * Inputs:  --
 * Returns: --
 * Modifies: sets the internal fraction to the product of the two fractions;
 *       if the fraction pair is not initialized, sets the internal error flag
 * Error Checking: checks to make sure internal fraction pair is initialized
*/
void MultiplyFractionPair(){
      if(!init_) {
         errorFlag_ = NOT_INITIALIZED;
         return;
       }

      numeratorResult = numerator1 * numerator2;
      denominatorResult = denominator1 * denominator2;

   /* reduce */
   ReduceFraction();

}

/*
 * Function: DivFractionPair
 * Purpose: to divide the fraction pair
 * Inputs:  --
 * Returns: --
 * Modifies: sets the internal fraction to the result of dividing the two fractions;
 *       if the fraction pair is not initialized, sets the internal error flag
 * Error Checking: checks to make sure internal fraction pair is initialized
*/
void DivFractionPair(){

    if(!init_) {
         errorFlag_ = NOT_INITIALIZED;
         return;
     }

    numeratorResult = numerator1 * denominator2;
    denominatorResult = denominator1 * numerator2;

   /* reduce */
   ReduceFraction();
}

/*
 * Function: GetNumeratorResult
 * Purpose: to get the numerator part of the result
 * Inputs:  --
 * Returns: the numerator part of the result
 * Modifies: --
 * Error Checking: --
*/
int GetNumeratorResult() {
      if(!init_) {
         errorFlag_ = NOT_INITIALIZED;
         return 0;  /* just return something */
       }
       return numeratorResult;
}

/*
 * Function: GetDenominatorResult
 * Purpose: to get the denominator part of the result
 * Inputs:  --
 * Returns: the denominator part of the result
 * Modifies: --
 * Error Checking: --
*/
int GetDenominatorResult() {
      if(!init_) {
         errorFlag_ = NOT_INITIALIZED;
         return 0;
       }
	return denominatorResult;
}

/*
 * Function: clearError
 * Purpose:  to reset the internal error state flag
 * Inputs:   --
 * Returns:  --
 * Modifies:  resets the internal error flag
 * Error checking:  --
 */
void clearError() {
   errorFlag_ = OK;
}

/*
 * Function: isError
 * Purpose:  to return the state of the internal error flag
 * Inputs:   --
 * Returns:  1 if the internal error flag is set; 0 otherwise
 * Modifies:  --
 * Error checking:  --
 */
int isError() {
   return errorFlag_ != OK;
}

/*
 * Function: printError
 * Purpose:  to print the internal error flag
 * Inputs:   --
 * Returns:  --
 * Modifies:  --
 * Error checking:  --
 */
void printError() {
   switch( errorFlag_ ){
      case BAD_INPUT:
         fprintf(stderr, "Bad Input: Zero not permitted\n");
         return;
      case OK:
         return;
      default:
         fprintf(stderr, "Unknown Error\n");
         return;
   }
}
