#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/*
 * File: ex7-3.c
 * Function: getInt
 * Purpose: read characters from the keyboard and
 *   return the corresponding integer value
 * Inputs: nothing
 * Returns: integer value of characters read
 * Modifies: reads in input stream. Any character that has
 *   not been used is pushed back.
 * Error checking: returns 0 if no digits encountered
 * Sample call:  i = getInt();
 * Assuming the input was
 *    -12a
 *  the value of i will be -12, and 'a' will be the current
 *   input character.
 */
int getInt(void) {
     int c;
     int sign = 1;
     int val  = 0;

     /* skip whitespace  */
     while((c = getchar()) != EOF)
	if(!isspace(c))
		break;

     switch(c) { /* check current character */

     case '-' :  sign = -1;

     case '+' :  c = getchar();

     default  :  if(!isdigit(c))  {   /* error */
			ungetc(c, stdin);
                        return 0;
		}
     }

     while (isdigit(c)) {
          val = val * 10 + (c - '0');
          c = getchar();
     }
     
     if(c != EOF) 
          ungetc(c, stdin); /* return last character */

     return sign * val;
}

/* driver */
int main() {
	printf("enter characters representing an integer value\n");
	printf("getInt() read %d\n", getInt());
	printf("next input character was %c\n", getchar());
 	return EXIT_SUCCESS;
}

