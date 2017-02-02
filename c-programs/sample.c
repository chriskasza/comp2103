/* 
 * Author:      Tomasz Muldner
 * Date:        August, 1999
 * Version:     2.0
 * File:        Sample.c
 *
 * Program that expects one or two filenames on the command 
 *  line and produces a hexadecimal dump of the file whose name is 
 *  passed as the first argument. If the second argument is 
 *  present, the dump is stored in the file whose name is 
 *  passed as this argument. Otherwise, the dump is displayed 
 *  on the screen. The format of the dump is as follows:
 *
 *  Each line contains 16 hexadecimal ASCII codes of the  
 *  corresponding 16 bytes read from the file; separated by a 
 *  blank. This line is followed by a line containing the 16 
 *  corresponding characters, again separated by a blank, 
 *  with each non-printable character displayed as a dot and 
 *  other characters unchanged.
 */

/* include files */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* global definitions */
FILE *outFile;     /* output file */

/* Function declaration */
/* 
 * Function: hex(p, max) 
 * Purpose: writes to the global output file 
 *   outFile the hexadecimal codes of max number of characters 
 *   originating at the address given by the pointer p.
 *   This line is followed by the corresponding characters.
 *   Assumes that the file outFile has
 *   been opened for output.
 * Inputs:      p, max (parameters)
 *              outFile (global variable)
 * Returns:     nothing
 * Modifies:    outFile 
 * Error checking:      none
 */
void hex(unsigned char *p, int max);

/* main program - here is where the execution starts */
int main(int argc, char *argv[]) {
     FILE *inFile;    		/* input file handle */
     int i, toFile;
     const int SIZE= 16;
     unsigned char line[SIZE];  /* local buffer */

     if(argc > 3 || argc < 2) {
         fprintf(stderr, 
 "usage: %s filename [filename2]\n", argv[0]);
         return EXIT_FAILURE;
     }
  
     outFile = stdout;   /* set default output stream */
     toFile = (argc == 3); /* is there an output file */

     /* open I/O files */
     if((inFile = fopen(argv[1], "r")) == NULL) {
          fprintf(stderr, "Cannot open file %s\n", argv[1]);
          return EXIT_FAILURE;
     }
     if(toFile && (outFile = fopen(argv[2], "w")) == NULL) {
          fprintf(stderr, "Cannot open file %s\n", argv[2]);
	    fclose(infile);
          return EXIT_FAILURE;
     }

     /* main loop; 
      *   reads SIZE bytes at a time; stores them in 
      *   line, and calls hex() 
      */
       while((i = fread(line, 1, SIZE, inFile)) > 0) 
                hex(line, i); 
     
     /* close I/O */  
      if(fclose(inFile) == EOF) {
   fprintf(stderr, "Cannot close file %s\n", argv[1]);
   if(toFile)
	fclose(outFile);
         return EXIT_FAILURE;
      }
if(toFile && fclose(outFile) == EOF) {
   fprintf(stderr, "Cannot close file %s\n", argv[2]);
         return EXIT_FAILURE;
      }

     return EXIT_SUCCESS;
}

/* Definition of hex() */
void hex(unsigned char *p, int max) {
     int i;
     unsigned char *paux;

     for(i = 0, paux = p; i < max; i++, paux++)          
          fprintf(outFile, "%02x ", *paux);
     fputc('\n', outFile);

     for(i = 0, paux = p; i < max; i++, paux++) 
          fprintf(outFile, "%c  ", 
             isprint(*paux) ? *paux : '.'); 
     fputc('\n', outFile);
}
