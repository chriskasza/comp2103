/*
 * Exercise 5-17
 * A  program that reads a file and splits it into two files; 
 * the first file contains the first half of the
 * lines of the input file, and the second file contains the remaining lines. 
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
   FILE *fInput;
   FILE *fOutput1;
   FILE *fOutput2;
   int c = 0;  /* line counter */ 
   int i;
   int limit;
   
   if((fInput = fopen("junk", "r")) == NULL) {
      fprintf(stderr, "can't open %s\n", "junk");
      return EXIT_FAILURE;
   }
   if((fOutput1 = fopen("junk1", "w")) == NULL) {
      fclose(fInput);
      fprintf(stderr, "can't open %s\n", "junk1");
      return EXIT_FAILURE;
   }
   if((fOutput2 = fopen("junk2", "w")) == NULL) {
      fclose(fInput);
      fclose(fOutput1);
      fprintf(stderr, "can't open %s\n", "junk2");
      return EXIT_FAILURE;
   }
   /* initial read to get the number of lines */
   while((i = fgetc(fInput)) != EOF)
      if(i == '\n')
         c++;
   limit = c/2;
   c = 0;
   /* second read to copy */
   rewind(fInput);
   while((i = fgetc(fInput)) != EOF) {
      fputc(i, c < limit ? fOutput1 : fOutput2);
      if(i == '\n') 
         c++;
   }
   if(fclose(fInput) == EOF) {
      fclose(fOutput1);
      fclose(fOutput2);
      fprintf(stderr, "can't close %s\n", "junk");
      return EXIT_FAILURE;
   }
   if(fclose(fOutput1) == EOF) {
      fclose(fOutput2);
      fprintf(stderr, "can't close %s\n", "junk1");
      return EXIT_FAILURE;
   }
   if(fclose(fOutput2) == EOF) {
      fprintf(stderr, "can't close %s\n", "junk2");
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
 
 
