#include <stdlib.h>
#include <stdio.h>
/*
 * File: ex7-6-fileOps-main.c
 * An application of the file I/O module (menu-driven).
 * The user can enter the following commands:
 * 	I - to set the filename
 * 	W to count words in the given file
 * 	L - to count words
 * 	C to count characters
 * 	Q to quit.
 */
#include "ex7-6-fileOps.h"

/* Displays available commands */
void help() {
    printf("enter\n");
    printf("\tH for help\n");
    printf("\tI to provide filename\n");
    printf("\tW to count words\n");
    printf("\tL to count lines\n");
    printf("\tC to count characters\n");
    printf("\tQ to quit\n");
}

/* reads in user's command and executes the corresponding command */
void menu() {
  int c;
  int initialized = 0;
  char filename[FILENAME_MAX];
  long result;

  while(1) {
    printf("> (h for help): ");
    c = getchar();

    while (getchar() != '\n')
          ;

    switch (c) {
    case 'h':
    case 'H':
                help();
                break;
    case 'i':
    case 'I':	
              if(initialized) 
    		    if(destruct_fileOps() == 0) {
			  fprintf(stderr, "failed to close previous file\n");
		        break;
		    } else initialized = 0;

	        printf("filename please: ");
		  if(scanf("%s", filename) != 1) {
			fprintf(stderr, "can't read file %s\n", filename);
			break;
		  }
		  while (getchar() != '\n')  /* skip till end of line */
      			;
              if(construct_fileOps(filename) == 0)
		     fprintf(stderr, "can't initialize %s\n", filename);
		  else initialized = 1;
              break;
    case 'w':
    case 'W':
	        if((result = words_fileOps()) == EOF) 
			fprintf(stderr, "failed to execute\n");
              else fprintf(stderr, "number of words is %ld\n", result);
              break;
    case 'l':
    case 'L':
	        if((result = lines_fileOps()) == EOF) 
			fprintf(stderr, "failed to execute\n");
              else printf("number of lines is %ld\n", result);
              break;
    case 'c':
    case 'C':  
	        if((result = chars_fileOps()) == EOF) 
			fprintf(stderr, "failed to execute\n");
	        else printf("number of characters is %ld\n", result);
              break;
    case 'q':
    case 'Q': 
	       if(destruct_fileOps() == 0)
		   fprintf(stderr, "failed to clean up\n");
             return;
    default :
             fprintf(stderr, "\nunknown command\n");
             break;
    }
 }
}

int main() {
   menu();
   return EXIT_SUCCESS;
}
