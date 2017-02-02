/*
 * File: x13-5.c
 * The implementation file for the module to provide encryption 
 * and decryption procedures
 *
 * Operations:  encryption / decryption
*/            
 
#include <stdio.h>
#include <stdlib.h>

#define	BYTE_SIZE 		(8)
#define	CLEAR 		(1)

/* 
 * Function:  encrypt
 * Purpose:   to read the text file fNameIn, and encrypt the contents
 *            by applying the xor operation using the characters in the
 *            key, and finally write the
 *            encrypted data to the output binary file
 * Inputs:    fNameIn, fNameOut, key
 * Returns:   1 on success, 0 otherwise
 * Modifies:  fNameOut
 * Error checking:  checks result of file operations
 */
int encrypt( const char *fNameIn, const char *fNameOut, const char *key){
	FILE *inFile;
	FILE *outFile;
	int i;
        int len = strlen(key);
	int ch;

	if( (inFile = fopen(fNameIn, "r")) ==  NULL)
		return 0;
	
	if( (outFile = fopen(fNameOut, "w")) == NULL){
		fclose(inFile);
		return 0;
	}

	while((ch = getc(inFile)) != EOF){
		for(i = 0; i < len; i++)
			ch = ch ^ key[i];	
		fprintf(outFile, "%c", ch);
	}
	
	if(fclose(inFile) == EOF) {
           fclose(outFile);
           return 0;
        }
	if(fclose(outFile) == EOF)
           return 0;

	return 1;
}

/* 
 * Function:  decrypt
 * Purpose:   to read the binary file fNameIn, and decrypt the contents
 *            by applying the xor operation using the characters in the
 *            key, and finally write the
 *            decrypted data to the output text file
 * Inputs:    fNameIn, fNameOut, key
 * Returns:   1 on success, 0 otherwise
 * Modifies:  fNameOut
 * Error checking:  checks result of file operations
 */
int decrypt(const char *fNameIn, const char *fNameOut, const char *key){

   FILE *inFile;
   FILE *outFile;
   int i;
   int len = strlen(key);
   int ch;

   if( (inFile = fopen(fNameIn, "r")) ==  NULL)
      return 0;
   
   if( (outFile = fopen(fNameOut, "w")) == NULL){
      fclose(inFile);
      return 0;
   }

   while((ch = getc(inFile)) != EOF){
      for(i=len-1;i >= 0;i--)   
         ch = ch ^ key[i];
      fprintf(outFile,"%c", ch);
   }

   if(fclose(inFile) == EOF) {
         fclose(outFile);
         return 0;
    }
    if(fclose(outFile) == EOF)
         return 0;

   return 1;
}


