/*
 * File: x7-5.c
 * formatter() function, and a simple program that tests the 
 * function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Function: formatter
 * Purpose:  prints the following output:
 * 			input string n times followed by the character 'E'
 *				 
 * Inputs:  n, string
 * Returns: --
 * Modifies: --
 * Error checking: if n is less than 1, does nothing
 */
void formatter(int n, char *string) {
   int i;

   if(n < 1)
   	return;

   for(i = 0; i < n-1; i++)
   	printf("%s%s ", string, string);
   printf("%s%sE\n", string, string);
}

int main() {
   printf("The string \"**\" with n = 1, formatted is : "); formatter(1, "**");
   printf("The string \"?\" with n = 2, formatted is : "); formatter(2, "?");
   printf("The string \"+*\" with n = 3, formatted is : "); formatter(3, "+*");
   printf("The string \"+*\" with n = 0, formatted is : "); formatter(0, "+*");

   printf("\n");

   return EXIT_SUCCESS;
}
