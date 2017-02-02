#ifndef X14_1POLY_H
#define X14_1POLY_H


/*
 * File: x14-1poly.h
 * A header file for the module that represents a polynomial of degree n
 * Operations: construction (several constructors are provided)
 *		 destructor
 *		 show the polynomial
 *		 modify the polynomial
 *     add two polynomials
 *     subtract two polynomials
 *     multiply two polynomials
*/
#include "ex11-enum.h"


typedef struct Concrete_Polynomial  *Abstract_Polynomial;

/*
 * Function:  constructor_PolynomialSimple
 * Purpose:   to allocate the memory for a polynomial
 * Inputs:    degree
 * Returns:   the constructed polynomial; NULL on failure
 * Modifies:  the polynomial
 * Error checking:  ensures degree is correct (i.e > 0 )
 */
Abstract_Polynomial constructor_PolynomialSimple( int degree );

/* 
 * Function:  constructor_Polynomial
 * Purpose:   to allocate the memory for a polynomial, and initialize
 *					the polynomial coefficients
 * Inputs:    degree, inPoly
 * Returns:   the constructed polynomial; NULL on failure
 * Modifies:  the polynomial
 * Error checking:  ensures degree is correct (i.e > 0 )
 */
Abstract_Polynomial constructor_Polynomial( int degree , double *inPoly);

/* 
 * Function:  destruct_Polynomial
 * Purpose:   to de-allocate the memory for a polynomial
 * Inputs:    this
 * Returns:   --
 * Modifies:  this
 * Error checking:  ensures polynomial is initialized
 */
void destruct_Polynomial( Abstract_Polynomial *this );

/* 
 * Function:  showPolynomial
 * Purpose:   to display the polynomial
 * Inputs:    this
 * Returns:   --
 * Modifies:  --
 * Error checking:  ensures polynomial is initialized
 */
void showPolynomial( Abstract_Polynomial this);

/* 
 * Function:  modifyPolynomial
 * Purpose:   to set the polynomial's degree coefficient to coef
 * Inputs:    this, degree, coef
 * Returns:   1 on success; 0 otherwise
 * Modifies:  the specified coefficient
 * Error checking:  ensures polynomial is initialized and degree is correct
 */
int modifyPolynomial( Abstract_Polynomial this, int degree, double coef);

/* 
 * Function:  AddPolys
 * Purpose:   to add two polynomials together
 * Inputs:    a and b
 * Returns:   the sum, NULL on failure
 * Modifies:  the result
 * Error checking:  ensures both polynomials are initialized 
 */
Abstract_Polynomial AddPolys( Abstract_Polynomial a, Abstract_Polynomial b);

/* 
 * Function:  SubtractPolys
 * Purpose:   to subtract two polynomials together
 * Inputs:    a and b
 * Returns:   the difference, NULL on failure
 * Modifies:  the result
 * Error checking:  ensures both polynomials are initialized 
 */
Abstract_Polynomial SubtractPolys(Abstract_Polynomial a, Abstract_Polynomial b);

/* 
 * Function:  MultPolys
 * Purpose:   to multiply two polynomials together
 * Inputs:    a and b
 * Returns:   the product, NULL on failure
 * Modifies:  the result
 * Error checking:  ensures both polynomials are initialized 
 */
Abstract_Polynomial MultPolys(Abstract_Polynomial a, Abstract_Polynomial b);

#endif

