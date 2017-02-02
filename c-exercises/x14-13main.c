/*
 * File: x14-13main.c
 * Application of the module Figure, that provides operations on nested figures
 * The program prompts the user to input points which are used to create a
 * simple figure. The testing is limited in that no complex figures are added
 * to the local figure.
*/

#include <stdio.h>
#include <stdlib.h>
#include "x14-13fig.h"

int main(){
	AbstractFigure fig;
	SimpleFigure simpleFig2, simpleFig;
	Point testPoint = {3,3};
        Point point[ 100] ;
	int numPoints = 0;
	int pos, i;
        int numIter = 2;

	if( (fig = initComplexFig()) == NULL){
		fprintf(stderr,"Error creating figure\n");
		return EXIT_FAILURE;
	}

	for(i = 0; i < numIter; i++){
		numPoints = 0;
		printf("Adding simpleFigure %d \n", i );
		while(1){
			printf("Enter a point q to end > ");
			if( scanf("%lf%lf", &point[numPoints ].x, &point[numPoints ].y) != 2){
				while(getchar() != '\n') 
                                   ;
				break;
			}
			numPoints++;
		}
		if( (simpleFig = createSimpleFig(numPoints, point)) == NULL){
      	            fprintf(stderr,"Error creating figure \n");
      	            return EXIT_FAILURE;
   	        }

		if( addSimpleFigure( fig, simpleFig) == 0 ){
			fprintf(stderr,"Error adding figure\n");
			return EXIT_FAILURE;
		}
	}
	PrintFigure( fig );
	printf("Done first part \n\n");

	if( (simpleFig = getSimpleFig( 0, fig )) == NULL){
		fprintf(stderr,"Error getting figure\n");
		return EXIT_FAILURE;
	}	

	printf("Enter pos to add point at to first fig > ");
        if( scanf("%d", &pos) != 1){
           fprintf(stderr,"Error reading pos\n");
           return EXIT_FAILURE;
        }
        while( getchar() != '\n') 
           ;

	if( addPoint(simpleFig, &testPoint, pos) == 0){
		fprintf(stderr,"Error adding point\n");
		return EXIT_FAILURE;
	}

	printf("Added point; figure is now \n");
	PrintSimpleFigure( simpleFig );
		
	if( removePoint( simpleFig, &testPoint) == 0){
           fprintf(stderr,"Error removing point\n");
           return EXIT_FAILURE;
        }
	printf("removed point; figure is now \n");
        PrintSimpleFigure( simpleFig );

	if( (simpleFig2 = getSimpleFig( 0, fig )) == NULL){
           fprintf(stderr,"Error getting figure\n");
           return EXIT_FAILURE;
        }

	if( SameFigure( simpleFig, simpleFig2 ))
		printf("Correct : figure is equal to itself \n");
	else printf("error in equalFig function\n");

	return EXIT_SUCCESS;
}

