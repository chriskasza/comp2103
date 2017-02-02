#ifndef X14_13FIG_H
#define X14_13FIG_H

/*
 * File: x14-13fig.h
 * A header file for the module figure, that provides a representation
 * for two-dimentional nested figures. A figure may be defined as
 * a collection of :
 * 	simple figures (sequence of points) 
 * and/or 
 * 	complexFigures (which consists of a collection of figures, figure
 *		defined above)
 *
 * Operations:  
 *		create a simple figure
 *		initialize a complex figure
 * 	get the type of the figure
 *    add a simple figure to the collection
 *		add a complex figure
 *	   destroy a figure
 * 	remove a point from a simple figure	 
 * 	add a point to a simple figure
 * 	compare two simple figures
 * 	print a figure
 *    get a simple figure from the collection
*/

typedef struct {
   double x;
   double y;
} Point;

typedef enum { SimpleFigType = 0, ComplexFigType } FigType;

typedef struct ConcreteFigure *AbstractFigure;
typedef struct ConcreteSimpleFig *SimpleFigure;

/*
 * Function:  initComplexFig
 * Purpose:  to initialize a complex figure
 * Inputs:   --
 * Returns:  the created figure
 * Error checking: checks to ensure memory allocation was successful
 */
AbstractFigure initComplexFig();

/*
 * Function:  createSimpleFig
 * Purpose:  to create a simple figure
 * Inputs:   numPoints, points
 * Returns:  the simple figure
 * Error checking: checks to ensure memory allocation was successful
 */
SimpleFigure  createSimpleFig( int numPoints, Point points[]);

/*
 * Function:  getType
 * Purpose:  to get the type of the figure at position pos
 * Inputs:   pos, fig
 * Returns:  the type, -1 on failure
 * Error checking: checks to ensure pos is correct
 */
FigType getType( int pos,  AbstractFigure fig );

/*
 * Function:  addSimpleFigure
 * Purpose:  to add a simple figure to the figure
 * Inputs:   fig, simpleFig
 * Returns:  1 on success; 0 otherwise
 * Error checking: ensures that there is room in the figure to add
 *   another component
 */
int addSimpleFigure( AbstractFigure fig, SimpleFigure  simpleFig );

/*
 * Function:  addComplexFigure
 * Purpose:  to add a complex figure to the figure
 * Inputs:   origFig, newFig
 * Returns:  1 on success; 0 otherwise
 * Error checking: ensures that there is room in the figure to add
 *   another component
 */
int addComplexFigure( AbstractFigure origFig, AbstractFigure newFig );

/*
 * Function:  destroyFigure
 * Purpose:  to release memory occupied by a figure
 * Inputs:   f
 * Returns:  --
 */
void destroyFigure( AbstractFigure  f);

/*
 * Function:  EqualPoint
 * Purpose:  to determine if two points are equal
 * Inputs:   a, b
 * Returns:  1 if points are equal, 0 otherwise
 */
int EqualPoint( Point *a, Point *b);

/*
 * Function:  removePoint
 * Purpose:  to remove a point from the specified simple figure
 * Inputs:   simpleFig, p
 * Returns:  1 on success; 0 otherwise
 * Error checking: ensures that the point exists in the figure
 */
int removePoint ( SimpleFigure  simpleFig, Point *p );

/*
 * Function:  addPoint
 * Purpose:  to add a point to the specified simple figure at position pos
 * Inputs:   simpleFig, p, pos
 * Returns:  1 on success; 0 otherwise
 * Error checking: ensures that pos is correct
 */
int addPoint( SimpleFigure  fig, Point *p, int pos);

/*
 * Function:  SameFigure
 * Purpose:  to determine if the two figures are the same
 * Inputs:   f1, f2
 * Returns:  1 if figures are the same; 0 otherwise
 */
int SameFigure( SimpleFigure  f1, SimpleFigure  f2);

/*
 * Function:  PrintFigure
 * Purpose:  to print the contents of a figure
 * Inputs:   fig
 * Returns:  --
 */
void PrintFigure( AbstractFigure fig );

/*
 * Function:  getSimpleFig
 * Purpose:  to access the i'th simple figure in figure
 * Inputs:   pos, fig
 * Returns:   a simple figure; NULL if an error occurs
 * Error checking: pos is correct; figure at specified pos is a simple figure
 */
SimpleFigure  getSimpleFig( int pos, AbstractFigure fig );

/*
 * Function:  PrintSimpleFigure
 * Purpose:  to print a simple figure
 * Inputs:   fig
 * Returns:  --
 * Error checking: --
 */
void PrintSimpleFigure( SimpleFigure fig );

#endif

