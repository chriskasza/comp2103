/*
 * File: ex5-4.c
 * Reads from stdin or the file TEST1, write to stdout or the file TEST2.
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
	FILE *f, *g;
	int c;
	int fromFile = 0;  /* reading from a file ? */
	int toFile = 0;  /* writing to a file ? */
          
	printf("Enter Y or y to read from the standard input stream, ");
	printf("any other character to read from TEST1: ");
	c = getchar();
	while(getchar() != '\n') 	/* skip until end-of-line */
		;

	if(c == 'y' || c == 'Y') 		/* reading from stdin */
		f = stdin;
	else { 
		if((f = fopen("TEST1", "r")) == NULL) {
                    fprintf(stderr, "can't open TEST1\n");
                    return EXIT_FAILURE;
             }
	     fromFile = 1;		/* reading from TEST1 */
	}
          
	printf("Enter Y or y to write to the standard output stream, ");
	printf("any other character to write to TEST2: ");
	c = getchar();
	while(getchar() != '\n') 	/* skip until end-of-line */
		;

	if(c == 'y' || c == 'Y')
		g = stdout;
	else {
	    /* to see if TEST2 exists, open it for reading, then close it */

	    if((g = fopen("TEST2", "r")) != NULL) { /* TEST2 exists */

               fprintf(stderr, "File exists, overwrite? (Y/N) ");
               c = getchar();
               while (getchar() != '\n') 
                    ;

	       if(fclose(g) == EOF) {
                    	fprintf(stderr, "error in closing\n");
			if(fromFile)
				fclose(f);
                    	return EXIT_FAILURE;
	       }

               if(!(c == 'y' || c == 'Y')) {
		    fprintf(stderr, "Leaving TEST2 intact; terminating\n");
 		    return EXIT_SUCCESS;
	       }
	     }              
	       /* overwrite TEST2 */
               if((g = fopen("TEST2", "w")) == NULL) {
                    fprintf(stderr, "can't open TEST2\n");
		    if(fromFile)
			fclose(f);
                    return EXIT_FAILURE;
               }
            
	       toFile = 1; /* set the flag */
	}
           
	/* Now, both I/O files are ready */
	while((c = fgetc(f)) != EOF)
		putc(c, g);

	if(fromFile && fclose(f) == EOF) {
		fprintf(stderr, "error in closing TEST1\n");
		if(toFile)
			fclose(g);
		return EXIT_FAILURE;
	}
	if(toFile && fclose(g) == EOF) {
		fprintf(stderr, "error in closing TEST2\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

