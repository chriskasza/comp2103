#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * File: ex10-4.c
 * Function: search
 * Purpose: search an array of sorted strings looking for a key value
 * Inputs: string key, array names and its size (parameters)
 * Returns:  1 if key found 0 otherwise
 * Modifies: nothing
 * Error checking: fails if array is not sorted
 * Sample call:
 *    char *n[] = {"abc", "def" ); 
 *    if(search("ab",n, 2))... 
 *
 */
int search(const char *key, char *names[], int size) {

   char **low = names;
   char **high = names + size - 1;
   char **mid;
   int c;
  
   while (low <= high) {
	 mid = low + (high - low)/2;
    if ((c = strcmp(*mid, key)) == 0)
      return 1;
    if (c < 0)
        low = mid + 1;
     else
        high = mid - 1;
  }
  
  return 0;
} 

/* 
 * Aapplication of the search function
 * Search an array of keywords
 */

char *reservedWords[] = {   /* note the words are sorted. */
  "case",         
  "const",       
  "do",          
  "if",
  "then",     
  "while",
  "zerylongkeyword",
  NULL
  };

int main() {
    char key[20];
    char **p;
    int size = sizeof(reservedWords)/sizeof(char*);

   /* show all keywords and then ask the user to search for one */
   printf("There are %d reserved words; the list of them follows.\n", size);
	for(p = reservedWords; *p != NULL; p++)
	printf("%s\n", *p);
   printf("Enter a word to look for:");
   if(scanf("%19s", key) != 1)
		return EXIT_FAILURE;
   printf("%s has %s been found\n", key, search(key, reservedWords, size) ? "" : "not");

   return EXIT_SUCCESS;
}
