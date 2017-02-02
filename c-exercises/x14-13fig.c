/*
 * File: x14-13fig.h
 * A header file for the module figure, that provides a representation
 * for two-dimentional nested figures. A figure may be defined as
 * an array of :
 *    simple figures (sequence of points)
 * and/or
 *    complexFigures (which consists of a collection of figures, figure
 *    defined above)
 *
 * Operations:
 *    create a simple figure
 *    initialize a complex figure
 *    get the type of the figure
 *    add a simple figure to the collection
 *    add a complex figure
 *    destroy a figure
 *    remove a point from a simple figure
 *    add a point to a simple figure
 *    compare two simple figures
 *    print a figure
 *    get a simple figure from the collection
*/

#include <stdio.h>
#include <stdlib.h>
#include "x14-13fig.h"

#define MAX 	(100)

/* store the first and the last convention */
struct ConcreteSimpleFig {
   Point *points;
   int numPoints;
} ;

typedef union{
   struct ConcreteSimpleFig *simpleFig;
   struct ConcreteFigure *complexFig;
} FigUnion;

typedef struct {
	FigUnion fig;
	FigType type;
} ComplexFigs;

struct ConcreteFigure {
   ComplexFigs collection[ MAX ];
   int actualSize;
};

/*
 * Function:  initComplexFig
 * Purpose:  to initialize a complex figure
 * Inputs:   --
 * Returns:  the created figure
 * Error checking: checks to ensure memory allocation was successful
 */
AbstractFigure initComplexFig( ){
	AbstractFigure fig;

	if( (fig = calloc( 1, sizeof(*fig))) == NULL)
           return NULL;
	fig->actualSize = 0;

	return fig;
}

/*
 * Function:  getSimpleFig
 * Purpose:  to access the i'th simple figure in figure
 * Inputs:   pos, fig
 * Returns:   a simple figure; NULL if an error occurs
 * Error checking: pos is correct; figure at specified pos is a simple figure
 */
SimpleFigure  getSimpleFig( int pos, AbstractFigure fig ){
	if( pos < 0 || pos >= fig->actualSize )
		return NULL;
	return fig->collection[pos].fig.simpleFig;
}

/*
 * Function:  createSimpleFig
 * Purpose:  to create a simple figure
 * Inputs:   numPoints, points
 * Returns:  the simple figure
 * Error checking: checks to ensure memory allocation was successful
 */
SimpleFigure  createSimpleFig( int numPoints, Point points[]){
	Point *ptr;
	int i;
	SimpleFigure  new;

	if( (new = calloc( 1, sizeof(*new))) == NULL)
		return NULL;

	if( (ptr = calloc( numPoints, sizeof(Point))) == NULL)
		return NULL;
	
	new->points = ptr;
	new->numPoints = numPoints;	
	for(i = 0; i < numPoints; i++)
		new->points[i] = points[i];

	return new;
}

/*
 * Function:  getType
 * Purpose:  to get the type of the figure at position pos
 * Inputs:   pos, fig
 * Returns:  the type, -1 on failure
 * Error checking: checks to ensure pos is correct
 */
FigType getType( int pos,  AbstractFigure fig ){
	if( pos < 0 || pos >= fig->actualSize )
		return -1;

	return fig->collection[ pos ].type;
}

/*
 * Function:  addComplexFigure
 * Purpose:  to add a complex figure to the figure
 * Inputs:   origFig, newFig
 * Returns:  1 on success; 0 otherwise
 * Error checking: ensures that there is room in the figure to add
 *   another component
 */
int addSimpleFigure( AbstractFigure fig, SimpleFigure  simpleFig ){
	int size;

	if( fig->actualSize >= MAX ) 
           return 0;

	size = fig->actualSize;
	fig->collection[ size ].fig.simpleFig = simpleFig;
	fig->collection[ size ].type = SimpleFigType;
	fig->actualSize++;

	return 1;
}

/*
 * Function:  addComplexFigure
 * Purpose:  to add a complex figure to the figure
 * Inputs:   origFig, newFig
 * Returns:  1 on success; 0 otherwise
 * Error checking: ensures that there is room in the figure to add
 *   another component
 */
int addComplexFigure( AbstractFigure origFig, AbstractFigure newFig ){
   int size;

   if( origFig->actualSize >= MAX ) 
      return 0;

   size = origFig->actualSize;
   origFig->collection[ size ].fig.complexFig = newFig;
   origFig->collection[ size ].type = ComplexFigType;
   origFig->actualSize++;

   return 1;
}

/*
 * Function:  destroyFigure
 * Purpose:  to release memory occupied by a figure
 * Inputs:   f
 * Returns:  --
 */
void destroyFigure( AbstractFigure  f){
	int i;

	for(i = 0; i < f->actualSize; i++){

		if( f->collection[i].type == SimpleFigType){
			free( f->collection[i].fig.simpleFig->points );
			free( f->collection[i].fig.simpleFig );
		} else destroyFigure( f->collection[i].fig.complexFig);
		
	}
}

/*
 * Function:  EqualPoint
 * Purpose:  to determine if two points are equal
 * Inputs:   a, b
 * Returns:  1 if points are equal, 0 otherwise
 */
int EqualPoint( Point *a, Point *b){
	return a->x == b->x && a->y == b->y;
}

/*
 * Function:  removePoint
 * Purpose:  to remove a point from the specified simple figure
 * Inputs:   simpleFig, p
 * Returns:  1 on success; 0 otherwise
 * Error checking: ensures that the point exists in the figure
 */
int removePoint ( SimpleFigure fig, Point *p ){
	int i, k;

	for(i = 0; i < fig->numPoints; i++)
		if( EqualPoint( &fig->points[i], p))
			break;

	if( i == fig->numPoints)
		return 0; /* could not find the point */
	if( fig->numPoints == 1 ) /* last point : not allowed */
		return 0;

	/* now remove the point */
	for(k = i + 1; k < fig->numPoints; k++)
		fig->points[k-1] = fig->points[k];
			
	fig->numPoints--;

	return 1;
}

/*
 * Function:  addPoint
 * Purpose:  to add a point to the specified simple figure at position pos
 * Inputs:   simpleFig, p, pos
 * Returns:  1 on success; 0 otherwise
 * Error checking: ensures that pos is correct
 */
int addPoint( SimpleFigure  fig, Point *p, int pos){
	int i, k;
	Point *temp;

	if( pos < 0 || pos > fig->numPoints )
		return 0;

	/* create the new points array */
	if( (temp = (Point *)calloc( fig->numPoints , sizeof(Point))) == NULL)
		return 0;

	/* copy the first pos- 1 points */
	for(i = 0; i < pos; i++)
		temp[i] = fig->points[i];

	temp[i++] = *p;

	for(k = i - 1; k < fig->numPoints; k++)
		temp[i++] = fig->points[k];

	fig->numPoints++;

	free( fig->points );
	fig->points = temp;

	return 1;
}

/*
 * Function:  SameFigure
 * Purpose:  to determine if the two figures are the same
 * Inputs:   f1, f2
 * Returns:  1 if figures are the same; 0 otherwise
 */
int SameFigure( SimpleFigure  f1, SimpleFigure  f2){

	int i, j;

	if( f1->numPoints != f2->numPoints )
		return 0;

	for(i = 0; i < f1->numPoints; i++){
		for(j = 0; j < f1->numPoints; j++)	
			if( !EqualPoint( &f1->points[i], &f2->points[i]))
				return 0;
	}
	
	return 1;
}

/*
 * Function:  PrintSimpleFigure
 * Purpose:  to print a simple figure
 * Inputs:   fig
 * Returns:  --
 * Error checking: --
 */
void PrintSimpleFigure( SimpleFigure fig ){
	int  k;

	for(k = 0; k < fig->numPoints; k++)
            printf("%f %f \t", fig->points[k].x, fig->points[k].y);
        printf("\n");
}

/*
 * Function:  PrintFigure
 * Purpose:  to print the contents of a figure
 * Inputs:   fig
 * Returns:  --
 */
void PrintFigure( AbstractFigure fig ){
	int i, k;
	SimpleFigure  temp;

	for(i = 0; i < fig->actualSize; i++){
		if( fig->collection[i].type == SimpleFigType ){
			temp = fig->collection[i].fig.simpleFig;
			for(k = 0; k < temp->numPoints; k++)
				printf("%f %f \t", temp->points[k].x, temp->points[k].y);
			printf("\n");
		}
		else PrintFigure( fig->collection[i].fig.complexFig);
	}
}

