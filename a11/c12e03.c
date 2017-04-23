/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c12e03.c
 *
 * store integers or characters (whichever comes first) into a union.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  character, integer
} ElemTagT;

/* the union, Elem, which stores characters or integers */
typedef struct {
  ElemTagT tag;
  union {
    char c;
    int i;
  } value;
} Elem;

/*
 * main
 */
int main() {
  Elem elemss[100];
  char c;
  int i;
  int j;
  int size = 0;

  printf("Enter some characters and hit enter.  Any numbers enterd will be"
      "printed in reverse.\n");
  while(size < 100) {
    if(scanf("%d", &i) == 1) {
      elemss[size].tag = integer;
      elemss[size].value.i = i;
    } else if(scanf("%c", &c) != EOF) {
      elemss[size].tag = character;
      elemss[size].value.c = c;
    } else {
      break;
    }
    size++;
  }

  for(j = size; j >= 0; j--) {
    if(elemss[j].tag == integer) {
      printf("%d\n", elemss[j].value.i);
    }
  }

  return EXIT_SUCCESS;
}
