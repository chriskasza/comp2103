/*
 * File: x14-1poly.c
 * The implementation file for the module that represents a polynomial of degree n
 * Operations: construction (several constructors are provided)
 *     destructor
 *     show the polynomial
 *     modify the polynomial
 *     add two polynomials
 *     subtract two polynomials
 *     multiply two polynomials
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "x14-1poly.h"

struct Concrete_Polynomial {
	int degree;
	int init;
	double *poly;
};

/*
 * Function:  constructor_PolynomialSimple
 * Purpose:   to allocate the memory for a polynomial
 * Inputs:    degree
 * Returns:   the constructed polynomial; NULL on failure
 * Modifies:  the polynomial
 * Error checking:  ensures degree is correct (i.e > 0 )
 */
Abstract_Polynomial constructor_PolynomialSimple( int degree ){
   
   Abstract_Polynomial poly;

   if( degree < 0 )
      return NULL;

   if( (poly = (Abstract_Polynomial)calloc(1, sizeof(*poly))) == NULL)
      return NULL;

   if( (poly->poly = (double *)calloc(degree+1 , sizeof(double))) == NULL)
      return NULL;

      poly->degree = degree;
      poly->init = 1;

     return poly;
}


/*
 * Function:  constructor_Polynomial
 * Purpose:   to allocate the memory for a polynomial, and initialize
 *             the polynomial coefficients
 * Inputs:    degree, inPoly
 * Returns:   the constructed polynomial; NULL on failure
 * Modifies:  the polynomial
 * Error checking:  ensures degree is correct (i.e > 0 )
 */
Abstract_Polynomial constructor_Polynomial( int degree , double * inPoly){
	int i;
	Abstract_Polynomial poly;

	if((poly = constructor_PolynomialSimple( degree )) == NULL)
		return NULL;

	for(i = 0; i <= degree; i++)
		poly->poly[i] = inPoly[i];
	
	return poly;
}

/*
 * Function:  destruct_Polynomial
 * Purpose:   to de-allocate the memory for a polynomial
 * Inputs:    this
 * Returns:   --
 * Modifies:  this
 * Error checking:  ensures polynomial is initialized
 */
void destruct_Polynomial( Abstract_Polynomial * this ){

	if( !*this || !(*this)->init)
		return;

	if( (*this)->poly)
		free((*this)->poly);
	free( *this);
	*this = NULL;
}

/*
 * Function:  showPolynomial
 * Purpose:   to display the polynomial
 * Inputs:    this
 * Returns:   --
 * Modifies:  --
 * Error checking:  ensures polynomial is initialized
 */
void showPolynomial( Abstract_Polynomial this){

	int i;

	assert(this->init);
	for(i = 0; i <= this->degree; i++)
		printf("%d'th degree coefficient is %f\t", i, this->poly[i]);

	printf("\n");
	
}

/*
 * Function:  modifyPolynomial
 * Purpose:   to set the polynomial's degree coefficient to coef
 * Inputs:    this, degree, coef
 * Returns:   1 on success; 0 otherwise
 * Modifies:  the specified coefficient
 * Error checking:  ensures polynomial is initialized and degree is correct
 */
int modifyPolynomial( Abstract_Polynomial this , int degree, double coef){

	if( !this->init || degree < 0 || degree > this->degree)
		return 0;
	
	this->poly[ degree ] = coef ;
	return 1;	
}

/*
 * Function:  AddPolys
 * Purpose:   to add two polynomials together
 * Inputs:    a and b
 * Returns:   the sum, NULL on failure
 * Modifies:  the result
 * Error checking:  ensures both polynomials are initialized
 */
Abstract_Polynomial AddPolys( Abstract_Polynomial a, Abstract_Polynomial b){

	Abstract_Polynomial new, biggerPoly;
	int i, biggerDegree , smallerDegree;

	/* both must be initialized */
	if( !a->init || !b->init )
		return NULL;

	 /* figure out which polynomial is smaller */
	if( a->degree > b->degree ){ 
		biggerDegree = a->degree;
		smallerDegree = b->degree;
		biggerPoly = a;
	} else {
		biggerDegree = b->degree;
		smallerDegree = a->degree;
		biggerPoly = b;
	}

	if((new = constructor_PolynomialSimple( biggerDegree )) == NULL)
		return NULL;

	for( i = 0; i <= smallerDegree; i++)
		new->poly[ i ] =	a->poly[i] + b->poly[i];

	/* now add the remaining degrees */
	for( ; i <= biggerDegree; i++)
		new->poly[i] = biggerPoly->poly[i];

	return new;
}

/*
 * Function:  SubtractPolys
 * Purpose:   to subtract two polynomials together
 * Inputs:    a and b
 * Returns:   the difference, NULL on failure
 * Modifies:  the result
 * Error checking:  ensures both polynomials are initialized
 */
Abstract_Polynomial SubtractPolys(Abstract_Polynomial a, Abstract_Polynomial b){

	Abstract_Polynomial new, biggerPoly;
	int i, biggerDegree, smallerDegree;

	/* both must be initialized */
	if( !a->init || !b->init )
		return NULL;

	/* figure out which polynomial is smaller */
	if( a->degree > b->degree ){ 
		smallerDegree = b->degree;
		biggerDegree = a->degree;
		biggerPoly = a;
	} else{
		smallerDegree = a->degree;
		biggerDegree = b->degree;
		biggerPoly = b;
	}

	if((new = constructor_PolynomialSimple( biggerDegree )) == NULL)
		return NULL;

	for( i = 0; i <= smallerDegree; i++)
		new->poly[ i ] = a->poly[i] - b->poly[i];

	/* now add the remaining degrees */
	for( ; i <= biggerDegree ;i++)
		new->poly[i] = biggerPoly->poly[i];

	return new;
}

/*
 * Function:  MultPolys
 * Purpose:   to multiply two polynomials together
 * Inputs:    a and b
 * Returns:   the product, NULL on failure
 * Modifies:  the result
 * Error checking:  ensures both polynomials are initialized
 */
Abstract_Polynomial MultPolys(Abstract_Polynomial a, Abstract_Polynomial b){

	Abstract_Polynomial new, biggerPoly, smallerPoly;
	int i, j , biggerDegree, smallerDegree;

	/* both must be initialized */
	if( !a->init || !b->init )
		return NULL;

	/* figure out which polynomial is smaller */
	if( a->degree > b->degree ){
            biggerDegree = a->degree;
            smallerDegree = b->degree;
            biggerPoly = a;
            smallerPoly = b;
	} else {
            biggerDegree = b->degree;
            smallerDegree = a->degree;
            biggerPoly = b;
            smallerPoly = a;
         }

	/* create a new polynomial */
	if((new = constructor_PolynomialSimple( smallerDegree + biggerDegree )) == NULL)
		return NULL;

	for(i = 0; i <= biggerDegree ;i++){
		for(j = 0; j <= smallerDegree ;j++)
			new->poly[ i+j ] += biggerPoly->poly[i] * smallerPoly->poly[j];
		
	}

	return new;
}


/******************************************************************/

struct Concrete_Enumeration {
   int pos;
   Abstract_Polynomial poly;
};

/* 
 * Function: hasMoreElements_Enum
 * Purpose: check if there is another element
 * Inputs: an abstract enumeration
 * Returns: 1 if there is another element, 0 otherwise
 * Modifies: nothing  
 * Error checking: fails if not initialized
 * 
 */
int hasMoreElements_Enumeration(Abstract_Enumeration e) {
   assert(e->poly->init);
   return e->pos <= e->poly->degree;
}

/* 
 * Function: nextElement_Enumeration
 * Purpose: returns the next element
 * Inputs: an abstract enumeration
 * Returns: the element; NULL if there is not one
 * Modifies: --
 * Error checking: fails if not initialized
 * 
 */
void *nextElement_Enumeration(Abstract_Enumeration e ) {
	double *val;

   assert(e->poly->init);
   if(e->pos > e->poly->degree)
      return NULL;
	
   val = &e->poly->poly[ e->pos ];
   e->pos++;
   return (void *)val;
}

/*
 * Function: construct_Enumeration
 * Purpose: return a new enumeration
 * Inputs: nothing
 * Returns: a new abstract enumeration, NULL if fails
 * Modifies: nothing (except the internal state of the enumeration)
 * The client is responsible for deallacating this enumeration
 * Error checking: none
 *
 */
Abstract_Enumeration construct_Enumeration(void *p) {
   Abstract_Enumeration e; 

   if((e = calloc(1, sizeof(struct Concrete_Enumeration))) == NULL)
      return NULL;

   e->poly = (Abstract_Polynomial)p;
   e->pos = 0;
   return e;
}

/*
 * Function: destruct_construct_Enumeration
 * Purpose: destructs the enumeration
*/
void destruct_construct_Enumeration( Abstract_Enumeration e ){
	free( e );
}

