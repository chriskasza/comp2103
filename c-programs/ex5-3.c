/* 
 * File: ex5-3.c
 * Reads text from the file TEST until end-of-file and outputs to the file 
 *   TEST2 the length of the longest line and the number of this line 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
     typedef FILE* FILE_P;
     int     c;
     int     len     = 0;
     int     maxlen  = 0;
     long    longest = 0;
     long    line    = 0;
     FILE_P  f, g;

     if((f = fopen("TEST", "r")) == NULL) {
          fprintf(stderr, "The file TEST cannot be opened\n");
          return EXIT_FAILURE;
     }
     if((g = fopen("TEST2", "w")) == NULL) {
          fprintf(stderr, "The file TEST2 cannot be opened\n");
	  fclose(f);
          return EXIT_FAILURE;
     }

     while((c = fgetc(f)) != EOF) {
          if(c == '\n') {
               line++;
               if(len > maxlen) {
                    maxlen = len;
                    longest = line;
               }
               len = 0;  /* reset running length */
          } else len++;
     }
     
     if(line == 0) {  /* no line read */
	fprintf(stderr, "TEST has no line\n");
	return EXIT_SUCCESS;
     }

     if(fclose(f) == EOF) {
        fprintf(stderr, "File TEST cannot be closed\n");
	fclose(g);
	return EXIT_FAILURE;
     }

     fprintf(g, "\nThe longest line is ## %ld, ", longest);
     fprintf(g, "it has %d characters\n", maxlen);

     if(fclose(g) == EOF) {
        fprintf(stderr, "File TEST2 cannot be closed\n");
	return EXIT_FAILURE;
     }

     return EXIT_SUCCESS;
}
