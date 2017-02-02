#ifndef X10_11GETLINE_H
#define X10_11GETLINE_H
/*
 * File: x10-11getLine.h
 * Function: getLine
 * Purpose: read from file a line of unlimited length using a single dynamic allocation
 * Inputs: FILE in (parameter)
 * The client is responsible for opening and closing this file.
 * Returns: pointer to the memory block that stores the line (through parameter)
 *  The client is responsible for deallocating this memory
 *  Through function returns 1 if a line has been read, 0 on error, and EOF on eof
 * Modifies: file
 * Error checking: returns 0 if fails
 * Sample call:
 *    char *p;
 *    FILE *f;
 *    ... open f ..
 *    if(getLine(f, &p) == 1)
 *       printf("line is %s\n", p);
 *
 */
int getLine(FILE *in, char **result);

#endif
