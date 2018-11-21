/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c11e07.h
 *
 * a library to manage an array of student records.
 * includes a function for adding records (but not delete).
 *
 */
#ifndef C11E07
#define C11E07

#include <string.h>

/*
 * Function:       add
 * Purpose:        add a student to the StudentT array, table
 * Inputs:
 *   sName:        name of the student to add
 *   sId:          id of the student to add
 * Returns:        index in the array where the student record is added
 *                 or -1 if the record is not added
 * Modifies:       modifies the array, table, by adding the provided student
 * Error checking: ensures that table is not full
 *                 ensures that id is unique
 * Sample call:
 *   if(add(*studentName, 100133723) == -1)
 *     fprintf("failed to add student to the array\n");
 */
int add(const char *sName, int sId);

/*
 * Function:       printarray
 * Purpose:        print all records to STDOUT
 * Returns:        1 if successful; otherwise 0
 * Sample call:
 *   printarray();
 */
int printarray();

#endif
