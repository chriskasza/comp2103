/* Note: to enter *, use "*" */
#include <stdio.h>
#include <stdlib.h>

/*
 * File: ex10-1.c
 * A simple version of a calculator program that evaluates expressions
 * of the form
 *     n blanks op blanks n
 * passed on the command line.
 * For example
 *  evaluate   10   *       5
 */

#include <stdlib.h>
#include <stdio.h>

#define ERROR(mes, fatal) { fprintf(stderr, "%s\n", mes); \
	if(fatal) return EXIT_FAILURE; }

int main(int argc, char **argv) {
     double f, s;
     char oper[2];
#define FATAL 1
#define MILD  0
     if(argc != 4)
	ERROR("usage: %s n blanks op blanks n (for product use \"*\")", FATAL)
     
     if (sscanf(argv[1], "%lf", &f) != 1  ||       /* read first        */
         sscanf(argv[2], "%1s", oper) != 1 ||       /* read the operator */
         sscanf(argv[3], "%lf", &s) != 1)        /* read second       */
               ERROR("Incorrect input", MILD)

     switch (oper[0]) {
     case '+' : f += s; 
                break;
     case '-' : f -= s;
                break;
     case '*' : f *= s; 
                break;
     case '/' : if (s != 0) {
                     f /= s; 
                     break;
                } else ERROR("Cannot divide by zero", MILD)
     default  : ERROR("unknown operator", MILD);
     }

     printf("The result is %f\n", f);

     return EXIT_SUCCESS;
}

