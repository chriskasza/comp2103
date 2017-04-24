/*
 * Author:     Chris Kasza
 * Student #:  100133723
 * Course:     COMP 2103 N1
 * Version:    1.0
 * File:       c14e03.c
 *
 * a simple calculator for expressions provided in reverse Polish notation.
 * operands are limited to single digit numbers and only the first one hundred
 * characters inputed are included in the expression.
 * to exit the program enter an empty line (hit the enter key).
 *
 * example:
 * $ c14e03
 * > 235+*
 * 16
 *
 * equivalent infix notation: (2 * (3 + 5))
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "x14-3stack.h"

#define EXPRSIZE 100
#define DEBUG 0

/*
 * Function:       compress
 * Purpose:        removes ith characters from a given string where the ith
 *                   bit in a given mask is a zero
 * Inputs:
 *   str:          the string to be compressed
 *   mask:         an 8-bit mask
 * Modifies:       the string provided is modified in memory
 * Error checking:
 */
void compress(char *str, char mask) {
  return;
}

/*
 * main
 */
int main() {
  char chararray[EXPRSIZE];
  int i, x, y, res;
  short int fail;

  while(1) {
    fail = 0;
    printf("> ");

    if(fgets(chararray, EXPRSIZE, stdin) == NULL) {
      fprintf(stderr, "err: unable to read expression\n");
      return EXIT_FAILURE;
    }

    if(strlen(chararray) == 1) {
      return EXIT_SUCCESS;
    }

    initStack();

    for(i = 0; i < strlen(chararray)-1; i++) {
      /*if(DEBUG) {
        printf("DEBUG: Stack contents:\n");
        printStack();
        putchar('\n');
      }*/

      if(chararray[i] >= '0' && chararray[i] <= '9') { /* operand */
        if(DEBUG)
          printf("DEBUG: push %c\n", chararray[i]);

        x = chararray[i] - '0';
        if(pushOnStack(x) == 0) {
          fprintf(stderr, "err: stack is full; discarding %c\n", chararray[i]);
        }
      } else if(chararray[i] == '*' || chararray[i] == '+') { /* operator */
        if(stackSize() == 0) {
          fprintf(stderr, "err: stack is empty; unable to proceed\n");
          fail = 1;
          break;
        }

        if(popStack(&x) == 0) {
          fprintf(stderr, "err: failed to pop first operand\n");
          fail = 1;
          break;
        }

        if(DEBUG)
          printf("DEBUG: popped %d\n", x);

        if(popStack(&y) == 0) {
          fprintf(stderr, "err: failed to pop second operand\n");
          fail = 1;
          break;
        }

        if(DEBUG)
          printf("DEBUG: popped %d\n", y);

        switch(chararray[i]) {
          case '+': res = x + y;
                    if(DEBUG) 
                      printf("DEBUG: push %d   (%d + %d)\n", res, x, y);
                    pushOnStack(res);
                    break;
          case '*': res = x * y;
                    if(DEBUG)
                      printf("DEBUG: push %d   (%d * %d)\n", res, x, y);
                    pushOnStack(res);
                    break;
          default:  fprintf(stderr, "err: problem with operand\n");
                    fail = 1;
        }
      } else {
        fprintf(stderr, "err: invalid character\n");
        fail = 1;
        break;
      }
    }

    if(fail == 0) {
      if(isEmpty()) {
        fprintf(stderr, "err: no values in stack\n");
        EXIT_FAILURE;
      }

      if(popStack(&res) == 0) {
        fprintf(stderr, "err: problem accessing result\n");
        EXIT_FAILURE;
      }

      printf("%d", res);

      if(isEmpty()) {
        printf("\n");
      } else {
        printf("   (warning: values left on the stack)\n");
      }
    }
  }

  return EXIT_SUCCESS;
}
