/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c11e19.c
 *
 * a simple line editor program which supports the following functionality:
 *  - print the current line
 *  - edit the current line
 *  - go to a different line
 *  - print lines m to n
 *
 */

#include "x11-17array.h"
#include "ex11-2-list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char* strdup(const char*);

Abstract_List list;
int current;

DataType copyData_List(const DataType v) {
  return strdup(v);
}

void freeData_List(DataType v) {
  free(v);
}

void clean_stdin(void) {
  int ch;
  while ( (ch = getchar()) != EOF && ch != '\n' );
}

/*
 * Function: menu
 * Purpose:  prints menu options and requests a menu choice
 * Returns:  the menu choice
 */
int menu() {
  int option = 0;

  clean_stdin();

  printf("\nOptions\n1) print the current line\n2) edit the current line\n"
         "3) go to a different line\n4) print lines X to Y\n"
         "5) save and exit\n6) exit without saving\nChoose an option: [1-6] ");
  if(scanf("%d", &option) != 1 || option < 1 || option > 6) {
    printf("Invalid option.\n");
    return menu();
  }
  return option;
}

/*
 * Function: printLine
 * Purpose:  prints the current line
 * Returns:  1 if successful; 0 if not
 */
int printLine() {
  Abstract_Enumeration e;
  char *aux;
  int i;

  e = construct_Enumeration(list);

  for(i = 0; i < current; i++) {
    if(hasMoreElements_Enumeration(e) == 0) {
      fprintf(stderr, "ERR: line not found\n");
      return 0;
    }
    aux=nextElementTyped_Enumeration(char*, e);
  }

  printf("\n%s\n", aux);
  free(aux);
  free(e);

  return 1;
}

/*
 * Function: editLine
 * Purpose:  replaces the current line with use input
 * Returns:  1 if successful; 0 if not
 */
int editLine() {
  DataType line;
  char buffer[81];

  if(delete_List(list, current, &line) == 0) {
    fprintf(stderr, "failed to access current line for editing\n");
    return 0;
  }

  printf("Current contents of line:\n");
  printf("%s\n", line);
  printf("Enter the replacement line (max 80 chars):\n");

  /* clean_stdin(); */

  if(fgets(buffer, 80, stdin) == NULL) {
    fprintf(stderr, "failed to read from stdin\n");
    return 0;
  }

  if(insert_List(list, current, buffer) == 0) {
    fprintf(stderr, "failed to update line in list\n");
    return 0;
  }

  free(line);
  return 1;
}

/*
 * Function: gotoLine
 * Purpose:  goes to the requested line and prints the line
 * Returns:  1 if successful; 0 if not
 */
int gotoLine() {
  int t;

  printf("Which line do you want to go to? (1-%d) ", length_List(list));
  if(scanf("%d", &t) != 1 || t < 1 || t > length_List(list)) {
    printf("Invalid line.\n");
    return 1;
  }

  current = t;
  if(printLine() == 0)
    return 0;

  return 1;
}

/*
 * Function: printLines
 * Purpose:  prints multiple lines
 * Returns:  1 if successful; 0 if not
 */
int printLines() {
  Abstract_Enumeration e;
  char *aux;
  int i;
  int l1, l2;

  printf("Which line do you want to start from? (1-%d) ", length_List(list));
  if(scanf("%d", &l1) != 1 || l1 < 1 || l1 > length_List(list)) {
    printf("Invalid line.\n");
    return 0;
  }

  printf("Which line do you want to print to? (%d-%d) ",
         l1+1, length_List(list));
  if(scanf("%d", &l2) != 1 || l2 <= l1 || l2 > length_List(list)) {
    printf("Invalid line.\n");
    return 0;
  }

  e = construct_Enumeration(list);

  for(i = 0; i < l1-1; i++) {
    if(hasMoreElements_Enumeration(e) == 0) {
      fprintf(stderr, "ERR: line not found\n");
      return 0;
    }
    aux=nextElementTyped_Enumeration(char*, e);
  }

  for(; i < l2; i++) {
    if(hasMoreElements_Enumeration(e) == 0) {
      fprintf(stderr, "ERR: line not found\n");
      return 0;
    }
    aux=nextElementTyped_Enumeration(char*, e);
    printf("%s", aux);
  }

  putchar('\n');

  current = l2;

  free(aux);
  free(e);

  return 1;
}

/*
 * Function: writeFile
 * Purpose:  writes list to file
 * Returns:  1 if successful; 0 if not
 */
int writeFile(char *filename) {
  FILE *f;
  Abstract_Enumeration e;
  char *aux;

  printf("opening %s", filename);

  if((f = fopen(filename, "w")) == NULL) {
    fprintf(stderr, "can not open %s for writing\n", filename);
    return 0;
  }

  e = construct_Enumeration(list);
  while(hasMoreElements_Enumeration(e) == 0) {
    aux=nextElementTyped_Enumeration(char*, e);
    fprintf(f, "%s", aux);
  }

  free(aux);
  free(e);

  if(fclose(f) == EOF) {
    fprintf(stderr, "can not save %s\n", filename);
    return 0;
  }

  return 1;
}

/*
 * main
 */
int main(int argc, char **argv) {
  FILE *f;
  const int LINESIZE = 80;
  char *filename;
  char buffer[81]; /* LINESIZE + 1  for \0 */
  int size = 0;

  current = 0;

  if(argc != 2) {
    fprintf(stderr, "usage %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  filename = argv[1];

  if((f = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "can not open %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  if((list = construct_List()) == NULL) {
    fprintf(stderr, "list constructor failed\n");
    return EXIT_FAILURE;
  }

  while(fgets(buffer, LINESIZE, f) != NULL) {
    if(insert_List(list, size, buffer) == 0) {
      fprintf(stderr, "building list failed\n");
      destruct_List(&list);
      return EXIT_FAILURE;
    }
    size++;
  }

  if(fclose(f) == EOF) {
    fprintf(stderr, "can not close %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  printf("Done reading all %d lines from %s into memory.  ", size, argv[1]);

  if(gotoLine() == 0) {
    return EXIT_FAILURE;
  }

  while(1) {
    switch(menu()) {
      case 1: if(printLine() == 0) {
                destruct_List(&list);
                EXIT_FAILURE;
              }
              break;
      case 2: if(editLine() == 0) {
                destruct_List(&list);
                EXIT_FAILURE;
              }
              break;
      case 3: if(gotoLine() == 0) {
                destruct_List(&list);
                EXIT_FAILURE;
              }
              break;
      case 4: if(printLines() == 0) {
                destruct_List(&list);
                EXIT_FAILURE;
              }
              break;
      case 5: printf("about to pass %s to write func\n", argv[1]);
              if(writeFile(filename) == 0) {
                destruct_List(&list);
                EXIT_FAILURE;
              }
      case 6: destruct_List(&list);
              return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}


