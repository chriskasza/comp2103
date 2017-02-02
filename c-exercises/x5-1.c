/*
 * Exercise 5-1
 * Program, which compares two text files, f1 and f2, one character at a time. Use the “Opening
  *  a file,” “Closing a file,” and “Read Single Character from a file” idioms. 
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
   FILE *fInput1;
   FILE *fInput2; 
   int i1, i2;
   
   if((fInput1 = fopen("junk1", "r")) == NULL) {
      fprintf(stderr, "can't open %s\n", "junk1");
      return EXIT_FAILURE;
   }
   if((fInput2 = fopen("junk2", "r")) == NULL) {
      fprintf(stderr, "can't open %s\n", "junk2");
      return EXIT_FAILURE;
   }

   while((i1 = fgetc(fInput1)) != EOF) 
      if((i2 = fgetc(fInput2)) != i1) { /* different */
         printf("files are different\n");
         return EXIT_SUCCESS;
      }
   /* if here, we reached the end of junk1, check if there is more in junk2 */
      printf("files are %s\n", (fgetc(fInput2) == EOF) ? "same" : "different");
   
   if(fclose(fInput1) == EOF) {
      fclose(fInput2);
      fprintf(stderr, "can't close %s\n", "junk1");
      return EXIT_FAILURE;
   }          
   if(fclose(fInput2) == EOF) {
      fprintf(stderr, "can't close %s\n", "junk2");
      return EXIT_FAILURE;
   }          
   return EXIT_SUCCESS;
}
 
