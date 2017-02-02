/*
 * File: x14-1main.c
 * Application of the module to operate on polygons
 * The application expects a text file as input, which contains polygons. The
 * file is of the form:
 *			degree
 *			coefficient1 coefficient2 ... coefficientN
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "x14-1poly.h"

#define MAX		            (10)
#define MAX_DEGREE		(1000)

/*
 * Function: cleanUp
 * Purpose:  to get rid of any used memory
 */
static void cleanUp( Abstract_Polynomial poly[], int size ){
	int i;

	for(i = 0; i < size; i++)
		destruct_Polynomial( &poly[i] );
}

int main(int argc, char * argv[]){
	FILE *file;
	int degree, i;
        int currentSize = 0;
	int pos1, pos2;
	double *val;
        double tempPoly[ MAX_DEGREE ];
	Abstract_Polynomial new, polynomials[ MAX ];
	Abstract_Enumeration e;

	if( argc != 2){
		fprintf(stderr, "Usage: program filename\n");
		return EXIT_FAILURE;
	}

	if( ((file = fopen(argv[1], "r")) == NULL) ){
		fprintf(stderr,"could not open the file\n");
		return EXIT_FAILURE;
	}

	/* now read in the file : create polynomials */
	while( 1 ){
        	/* 
        	 * format is : #degree newline all coefficients on one line etc 
        	*/
		if( fscanf(file,"%d\n", &degree) != 1){
			if( feof( file))
				break;

			fprintf(stderr, "Error reading\n");
			cleanUp( polynomials, currentSize );
			return EXIT_FAILURE;
		}

		if( degree > MAX_DEGREE ){
			fprintf(stderr, "max allowable degree is %d, truncating\n", MAX_DEGREE);
			degree = MAX_DEGREE;
		}

		/* read in each coefficient */
		for(i = 0; i <= degree; i++){
			if( fscanf(file,"%lf\n", &tempPoly[ i ]) != 1){
				if( feof( file))
					break;
         				
				fprintf(stderr, "Error reading\n");
				cleanUp( polynomials, currentSize );
				return EXIT_FAILURE;
			}         
		}

		if( (polynomials[ currentSize ] = constructor_Polynomial( degree, tempPoly))
				== NULL){
			fprintf(stderr, "Error creating polynomial\n");
			cleanUp( polynomials, currentSize );
                        return EXIT_FAILURE;
		}
		currentSize ++;

		if( currentSize > MAX){
			fprintf(stderr, "too many polynomials in file, max allowed is %d\n", MAX);
			break;
		}
                if(feof( file ))
                   break;
	}

	if( currentSize == 0 ){ /* nothing read */
		fprintf(stderr, " empty poly set !\n");
		cleanUp( polynomials, currentSize );
		return EXIT_FAILURE;
	}

	/* now show the polynomials */
        for(i = 0; i < currentSize; i++)
	   showPolynomial( polynomials[i] );
	/* construct enumeration over first poly */

	if( (e = construct_Enumeration( (void *)polynomials[0] )) == NULL){
		fprintf(stderr, "enumeration construction failed\n");
                cleanUp( polynomials, currentSize );
                return EXIT_FAILURE;
	}

	while( hasMoreElements_Enumeration( e ) ){
		if( (val = (double *)nextElement_Enumeration( e )) == NULL){
			fprintf(stderr, "enumeration error\n");
      	                cleanUp( polynomials, currentSize );
      	                return EXIT_FAILURE;
		}
		printf("Got %f \t", *val);
	}
	printf("\n");


	while(1){
		printf("Enter the positions of two polynomials (between 0 and %d, (-1 -1) to end ) > ",
			currentSize - 1);

		if( scanf("%d%d", &pos1, &pos2) == 2) {
			if( pos1 == -1 && pos2 == -1)
				return EXIT_SUCCESS;
                        }
		else  {
                  printf("Incorrect input\n");
		  break;
                }
		
		while( getchar() != '\n' ) 
                   ;

		if(pos1 < 0 || pos2 < 0 || pos1 >=currentSize || pos2 >=currentSize){
			printf("Out of range\n");
			continue;
		}

		new = AddPolys( polynomials[ pos1 ], polynomials[ pos2 ]);	
		if( !new ){
			fprintf(stderr, "addition error\n");
                        cleanUp( polynomials, currentSize );
                        return EXIT_FAILURE;
		}

		printf("now adding\n");
		showPolynomial( new );
		printf("now multiplying \n");
		destruct_Polynomial( &new );

		if((new = MultPolys( polynomials[ pos1 ], polynomials[ pos2 ])) == NULL ) {
                        fprintf(stderr, "addition error\n");
                        cleanUp( polynomials, currentSize );
                        return EXIT_FAILURE;
                  }

                 showPolynomial( new );
		 destruct_Polynomial( &new );
	    }
	
	if(fclose( file ) == EOF)
            return EXIT_FAILURE;
	cleanUp(polynomials, currentSize );

	return EXIT_SUCCESS;

}

