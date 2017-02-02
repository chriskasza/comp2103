/*
 * File: x7-13.c
 * Application to maintain information about books borrowed from the library.
 * The information is stored in a binary file, which contains structures
 * of type BookT. For each book, the binary file stores the following info:
 *		author, title, callNo and the number of copies of the book which 
 *    are available
 *
 * The main program first creates a binary file using a user provided text
 * file. The text file is of the format
 * 		title author callNumber numCopies < newLine >
 * The application then allows the user to search for books by call number
 * using the binary file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXI 					(20)

typedef struct{	
	char title[MAXI];
	char author[MAXI];
	long callNo;
	int copies;
} BookT;

/*** LOCAL VARIABLES ********************/

static FILE *binFile_ = NULL;


/*
 * Function:  print
 * Purpose:   to print the contents of the binary file
 * Inputs:    -- (reads from global binary file) 
 * Returns:   --
 * Modifies:  -- (file pointer is reset after the read)
 * Error checking:  checks the result of each read operation
 */
static void print( ){
   
   BookT book;
   long curPos;

   if((curPos = ftell(binFile_)) == -1L) { /* this should not happen */
         fprintf(stderr, "Error in looking for the current position\n");
         return;
   }

   /* reset the file pointer */
   rewind(binFile_);

   /* print all data */
   while(1) {
      if( fread(&book, sizeof(book), 1, binFile_) != 1){
         if( feof(binFile_))
            return;
         else {
            fprintf(stderr, "Error reading file\n");
            return;
         }
      }
      printf(" %s %s %ld %d \n", book.title, book.author, book.callNo, book.copies);
  }

  /* reset the file pointer to the original position */
  if(fseek(binFile_, curPos, SEEK_SET))
       fprintf(stderr,"Error resetting file position\n");
}

/*
 * Function: search
 * Purpose:  to look for a book specified by the callNo and name 
 *				in the binary file
 * Inputs:   callNo, name
 * Returns:  -1 on error; 2 if the book is found, but there are 0 copies
 *				remaining in the library; 1 if the book is in the library and
 *				there are more than 0 copies of the book remaining
 * Modifies: if the book is available, decrements the number of copies available
 * Error checking:  checks the result of each read operation
 */
static int search( long callNo, char *name){
	
	BookT book;

	/* start searching at the beginning: reset the file pointer */
	rewind(binFile_);
        while(1) {
          if( fread(&book, sizeof(book), 1, binFile_) != 1){
             if( feof(binFile_))
                break;
             else {
              fprintf(stderr, "Error reading file\n");
              return -1;
            }
          } else {
		if( callNo == book.callNo){
			if( book.copies == 0 )
				return 2;
			else {
				strncpy(name, book.author, MAXI-1);
				book.copies--;
				fseek(binFile_, -sizeof(book), SEEK_CUR);
				return fwrite( &book, sizeof(book), 1, binFile_) != 1;
			}
		}
          }
       }

       return 1; /* not found */
}

/*
 * we first create a binary file, by reading a user provided input file where
 * each line is of the form:
 *	title<whitespace>author<whitespace>callNo<whitespace>copies<newline>
 *
 *
*/
int main(int argc, char *argv[]){
        FILE *in, *out;
	BookT book;
	char *name;
	int result;
	long num;

       if( argc != 3){
          fprintf(stderr, "Usage: programName inputFileName outputBinFileName\n");
          return EXIT_FAILURE;
       }

	if( (name = calloc(MAXI, sizeof(char))) == NULL){
		fprintf(stderr, "Memory allocation failed\n");
		return EXIT_FAILURE;
	}

	/* we will first create the required binary file from the input file*/
         if( (in = fopen (argv[1],  "r")) == NULL){
            fprintf(stderr, "could not open the input file\n");
            free(name);
            return EXIT_FAILURE;
         }

	if( (out = fopen (argv[2],  "w")) == NULL){
            fprintf(stderr, "could not open the output file\n");
            fclose(in);
            free(name);
            return EXIT_FAILURE;
         }

	/* now create the file */
	while(1){
		if( fscanf(in,"%s%s%ld%d\n", book.title, book.author, &book.callNo,
				&book.copies) != 4){
			if(feof(in))
				break;
			else {
		          fprintf(stderr, "Error reading file\n");
                          fclose(in);
                          fclose(out);
                          free(name);
			  return EXIT_FAILURE;
			}
		}
		if( fwrite(&book, sizeof(book), 1, out) != 1){
		 	fprintf(stderr,"Error writing binary file \n");
                        fclose(in);
                        fclose(out);
                        free(name);
		 	return EXIT_FAILURE;
		}
	}

	if(fclose(in) == EOF) { 
           fprintf(stderr, "could not close the input file\n");
           fclose(out);
           free(name);
           return EXIT_FAILURE;
        }

	if(fclose(out) == EOF) { 
           fprintf(stderr, "could not close the input file\n");
           free(name);
           return EXIT_FAILURE;
        }

	
	if( (binFile_ = fopen (argv[2], "r+")) == NULL){
           fprintf(stderr, "could not open the input binary file\n");
           free(name);
           return EXIT_FAILURE;
        }

	/* now we are ready to look for a book */
	while(1){
		printf("Enter: a call number  (0 to quit) > ");
		if( scanf("%ld", &num ) != 1){
			printf("Incorrect input \n");
			break;
		}
		else if(num == 0){
			printf("Done \n");
			break;
		}
		result = search(num, name);
		if( result == 1 )
			printf("book not in library\n");
		else if(result == 2)
			printf("book in library but not available\n");
		else printf("Book is available, author is %s \n", name);
		printf("Currently, the file looks like:\n");
		print();

	}
        free(name);
	if(fclose(binFile_) == EOF) {
           fprintf(stderr, "could not close the binary file\n");
           return EXIT_FAILURE;
        }

	return EXIT_SUCCESS;
}

