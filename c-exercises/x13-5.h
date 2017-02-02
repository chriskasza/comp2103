#ifndef X13_5_H
#define X13_5_H

/*
 * File: x13-5.h
 * A header file for the module to provide encryption and decryption procedures
 * Operations:  encryption / decryption
*/


/*
 * Function:  encrypt
 * Purpose:   to read the text file fNameIn, and encrypt the contents
 *				  by applying the xor operation using the characters in the
 *				  key, and finally write the
 *			     encrypted data to the output binary file
 * Inputs:    fNameIn, fNameOut, key
 * Returns:   1 on success, 0 otherwise
 * Modifies:  fNameOut
 * Error checking:  checks result of file operations
 */
int encrypt( const char *fNameIn, const char *fNameOut, const char *key);

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
int decrypt(const char *fNameIn, const char *fNameOut, const char *key);

#endif

