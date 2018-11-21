/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c11e07.c
 *
 * a library to manage an array of 100 student records.
 * includes a function for adding records (but not delete).
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int id;
} StudentT;

StudentT table[100];
int tabsize = 0; /* 0 <= tabsize <= 100 */

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
int add(const char *sName, int sId) {
  int bottom = 0;
  int top = tabsize;
  int middle;
  int i;

  middle = (bottom + top) / 2;

  if(top > 0) {
    while(1) {
      if(sId < table[middle].id) {
        top = middle;
        middle = (bottom + top) / 2;
      } else if(sId > table[middle].id) {
        bottom = middle;
        middle = (bottom + top) / 2;
      } else {
        /* id is already present */
        return -1;
      }
      if(bottom == middle) {
        if(sId > table[middle].id)
          middle++;
        break;
      }
    }
  }

  for(i = tabsize; i >= middle; i--) {
    memcpy(&table[i], &table[i-1], sizeof(StudentT));
  }

  if((table[middle].name = malloc(strlen(sName)+1)) == NULL) {
    fprintf(stderr, "failed to allocate memory for record name\n");
    return -1;
  }
  strcpy(table[middle].name, sName);
  table[middle].id = sId;
  tabsize++;
  return middle;
}

/*
 * Function:       printarray
 * Purpose:        print all records to STDOUT
 * Returns:        1 if successful; otherwise 0
 * Sample call:
 *   printarray();
 */
int printarray() {
  int i;

  printf("Array of structs\n");
  for(i = 0; i < tabsize; i++) {
    if(printf("Record %d: %s (%d)\n", i, table[i].name, table[i].id) < 0)
      return 0;
  }

  return 1;
}
